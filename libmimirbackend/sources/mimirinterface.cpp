// mimirbackend.cpp
// Cale Overstreet 11/27/2019
// Source code for "C" interface for mimirbackend. 


#include "mimirbackend.h"

#include <iostream>
#include <new> // Used for creating object pointer
#include <vector>
#include <cmath>

trajectorymodel::~trajectorymodel() {
	// Delete arrays associated with data values
	//delete arraydata;
}

int trajectorymodel::fill_data(int size) {
	for (int i = 0; i < size; i++) {
		times.push_back(i / double(10));
		x_positions.push_back(double(i * i));
		y_positions.push_back(2 * i / double(3));
		z_positions.push_back(4 * i / double(3));

		x_velocities.push_back(3 * i / double(3));
		y_velocities.push_back(5 * i / double(3));
		z_velocities.push_back(7 * i / double(3));
	}

	for (int i = 0; i < size - 1; i++) {
		halftimes.push_back(i / double(10) + 0.05);
		x_accelerations.push_back(3 * i / double(3));
		y_accelerations.push_back(5 * i / double(3));
		z_accelerations.push_back(7 * i / double(3));
	}

	return 0;
}



int trajectorymodel::prepare_model() {
	// Filling stage_average_force and stage_mass_rate_change
	for (int i = 0; i < stage_impulses.size(); i++) {
		stage_average_forces.push_back(stage_impulses[i] / stage_burn_times[i]);

		double temp_mass_rate_change = ((stage_total_masses[i] - stage_dry_masses[i]) / stage_burn_times[i]) * timestep_size;

		stage_mass_rate_changes.push_back(temp_mass_rate_change);

		printf("Stage %i Force: %f\n", i, stage_average_forces[i]);
		printf("Stage %i MRC: %f\n", i, stage_mass_rate_changes[i]);
	}

	int m = int(stage_impulses.size()), n = 2;
	stage_firing_and_glide_times.resize(m);
	for(int i = 0 ; i < m ; ++i){
		//Grow rows by n
		stage_firing_and_glide_times[i].resize(n);
	}

	double temp_buffer_time = 0;
	for (int i = 0; i < m; i++){
		temp_buffer_time += stage_burn_times[i];
		stage_firing_and_glide_times[i][0] = temp_buffer_time;
		temp_buffer_time += stage_delay_times[i];
		stage_firing_and_glide_times[i][1] = temp_buffer_time;
	}

	for (int i = 0; i < stage_impulses.size() - 1; i++ ) {
		stage_separation.push_back(1);
	}
	stage_separation.push_back(0);


	return 0;
}

int trajectorymodel::calculate_trajectory() {
	// Main trajectory calculation component. Publicly accessible class member
	prepare_model();

	// Environment Variables
	double g = 9.81; // m/s^2
	double rho_air = 1.225; // kg/m^3
	double Pi = 3.141592653589;

	int number_of_stages = stage_impulses.size();

	// Initial Conditions
	times.push_back(0);
	x_positions.push_back(0);
	y_positions.push_back(0);
	z_positions.push_back(0);

	x_velocities.push_back(0);
	y_velocities.push_back(0);
	z_velocities.push_back(0);

	// Current Variables (posiitons, velocities, etc)
	double current_x_position = 0;
	double current_y_position = 0;
	double current_z_position = 0;

	double current_x_velocity = 0;
	double current_y_velocity = 0;
	double current_z_velocity = 0;
	double current_speed = 0;

	double current_x_acceleration = 0;
	double current_y_acceleration = 0;
	double current_z_acceleration = 0;

	double current_thrust = 0;

	// Preparing drag constants
	double rocket_drag_constant = 0.5 * rocket_cd * std::pow((0.5 * rocket_diameter), 2) * Pi;
	double parachute_drag_constant = 0.5 * parachute_cd * std::pow((0.5 * parachute_diameter), 2) * Pi;
	double rocket_drag = 0;
	double parachute_drag = 0;
	double pressure_0 = 101325; // (Pa), atmospheric pressure at sea altitude_above_sea_level
	double temperature_0 = 288.15; // (K),sea level Temperature_0
	double temperature_lapse_rate = 0.0065; // (K/m) decrease in temperature with minHeight
	double ideal_gas_constant = 8.31447; // (J/mol-k) ideal gas constants
	double molar_mass_air = 0.0289644; // (kg/mol) molar mass of atmospheric molar_mass_air
	double temp_pressure = 0;
	double temp_density = 0;	

	// Setting direction of the rocket
	double current_x_direction = std::cos(vertical_direction * Pi / 180) * std::cos(horizontal_direction * Pi / 180); // Calculating Direction from initial values
	double current_y_direction = std::cos(vertical_direction * Pi / 180) * std::sin(horizontal_direction * Pi / 180);
	double current_z_direction = std::sin(vertical_direction * Pi / 180);

	double current_altitude = starting_altitude; // Setting starting altitude in m

	double current_time = timestep_size;
	double current_mass = initial_mass + 0.5 * stage_mass_rate_changes[0];

	int parachute_status = 0; // 0 is non-deployed, 1 is deployed. Used to minimize comparisons during loop
	int launch_rail_status = 1; // 1 is on launch rail, 0 is off launch rail
	int stage_number = 0; // For incrementing stage arrays
	int stage_subnumber = 0; // 0 is burn phase, 1 is glide phase;

	// Main calculation loop
	while (current_z_position >= 0 ) {
		// Determining stage_number, stage_subnumber, and mass due to stage separations
		if (parachute_status != 1) {
			if (float(current_time) > stage_firing_and_glide_times[stage_number][stage_subnumber]) {
				if (stage_subnumber == 0) { // The current stage is the burn stage
					current_mass += -0.5 * stage_mass_rate_changes[stage_number]; // Eliminating mass offset

					if (stage_delay_times[stage_number] == 0) { // No delay after current burn stage
						if (stage_separation[stage_number] == 1){ // Checking if stage separates
							current_mass += -stage_dry_masses[stage_number];
						}	
						
						if (stage_number + 1 == number_of_stages) { // Current stage is the last stage and has no delay
							parachute_status = 1; // Activating parachute
							current_thrust = 0; // No thrust during parachute phase
						} else {
							stage_number += 1; // Moving on to next stage
							current_mass += 0.5 * stage_mass_rate_changes[stage_number]; //Setting mass offset
						}	
					} else { // Delay after current burn stage
						stage_subnumber = 1; // Switching to delay stage
					}

				} else { // Current stage is the glide stage
					if (stage_separation[stage_number] == 1) { // Current stage separates
							current_mass += -stage_dry_masses[stage_number]; // Subtracting mass of stage
					}	
					
					if (stage_number + 1 == number_of_stages) { // If current stage is last stage
						parachute_status = 1; // Deploying parachute
						current_thrust = 0; // No thrust during parachute phase
					} else {
						stage_subnumber = 0; // Setting stage subnumber back to burn stage
						stage_number += 1; // Moving to next stage
						current_mass += 0.5 * stage_mass_rate_changes[stage_number]; // Setting mass offset
					}
				}	
			}
		}

		// Setting thrust and changing mass as necessary. No action necessary for parachute phase as thrust is set to 0 automatically
		if (parachute_status != 1) { // Parachute is not deployed
			if (stage_subnumber == 0) { // Current stage is burn stage
				current_mass += -stage_mass_rate_changes[stage_number];
				current_thrust = stage_average_forces[stage_number]; 
			} else { // Current stage is glide stage
				current_thrust = 0;
			} 
		}	

		// Drag Force Calculations
		temp_pressure = pressure_0 * std::pow((1 - (temperature_lapse_rate * (starting_altitude + z_positions.back())) / (temperature_0)), (g * molar_mass_air) / (ideal_gas_constant * temperature_lapse_rate));
		temp_density = (temp_pressure * molar_mass_air) / (ideal_gas_constant * (temperature_0 - temperature_lapse_rate * z_positions.back())); //  calculated density at current altitude

		rocket_drag = 1 * rocket_drag_constant * temp_density * std::pow(current_speed, 2); // calculating rocket Drag
		if (parachute_status == 1){
			parachute_drag = 1 * parachute_drag_constant * temp_density * std::pow(current_speed, 2); // calculating parachute Drag
		}

		// Acceleration Calculations
		current_x_acceleration = (current_thrust - parachute_drag - rocket_drag) * timestep_size * current_x_direction * (1 / current_mass);
		current_y_acceleration = (current_thrust - parachute_drag - rocket_drag) * timestep_size * current_y_direction * (1 / current_mass);
		current_z_acceleration = (current_thrust * current_z_direction - parachute_drag * current_z_direction - rocket_drag * current_z_direction - g * current_mass) * timestep_size * (1 / current_mass);

		// Velocity Calculations
		current_x_velocity += current_x_acceleration;
		current_y_velocity += current_y_acceleration;
		current_z_velocity += current_z_acceleration;

		// Calculating currrent speed
		current_speed = std::sqrt(std::pow(current_x_velocity, 2) + std::pow(current_y_velocity, 2) + std::pow(current_z_velocity, 2)); 

		// Position Calculations
		current_x_position += 0.5 * (current_x_velocity + x_velocities.back()) * timestep_size;
		current_y_position += 0.5 * (current_y_velocity + y_velocities.back()) * timestep_size;
		current_z_position += 0.5 * (current_z_velocity + z_velocities.back()) * timestep_size;

		// Determining direction. Direction does not change if the rocket is still on the launch rail
		if (launch_rail_status != 1){
			current_x_direction = current_x_velocity / current_speed;
			current_y_direction = current_y_velocity / current_speed;
			current_z_direction = current_z_velocity / current_speed;
		} else{
			if (std::sqrt(std::pow(current_x_position, 2) + std::pow(current_y_position, 2) + std::pow(current_z_position, 2)) > launch_rail_length){
				launch_rail_status = 0;
			}
		}

		// Data storage
		x_positions.push_back(current_x_position);
		y_positions.push_back(current_y_position);
		z_positions.push_back(current_z_position);

		x_velocities.push_back(current_x_velocity);
		y_velocities.push_back(current_y_velocity);
		z_velocities.push_back(current_z_velocity);

		x_accelerations.push_back(current_x_acceleration / (timestep_size * g));
		y_accelerations.push_back(current_y_acceleration / (timestep_size * g));
		z_accelerations.push_back(current_z_acceleration / (timestep_size * g));

		halftimes.push_back((current_time - 0.5 * timestep_size));

		times.push_back(current_time);
	
		
		// Continue to next time step
		current_time += timestep_size;
	}

	printf("%f kg\n", current_mass);
	return 0;
}


// Getter functions for values at indices in vectors
double trajectorymodel::get_times(int index){
	return times[index];
}

double trajectorymodel::get_x_positions(int index){
	return x_positions[index];
}
double trajectorymodel::get_y_positions(int index){
	return y_positions[index];
}
double trajectorymodel::get_z_positions(int index){
	return z_positions[index];
}

double trajectorymodel::get_x_velocities(int index){
	return x_velocities[index];
}
double trajectorymodel::get_y_velocities(int index){
	return y_velocities[index];
}
double trajectorymodel::get_z_velocities(int index){
	return z_velocities[index];
}

double trajectorymodel::get_halftimes(int index) {
	return halftimes[index];
}

double trajectorymodel::get_x_accelerations(int index){
	return x_accelerations[index];
}
double trajectorymodel::get_y_accelerations(int index){
	return y_accelerations[index];
}
double trajectorymodel::get_z_accelerations(int index){
	return z_accelerations[index];
}


// Getter for sizes of each vector
int trajectorymodel::len_times(){
	return times.size();
}

int trajectorymodel::len_x_positions(){
	return x_positions.size();
}
int trajectorymodel::len_y_positions(){
	return y_positions.size();
}
int trajectorymodel::len_z_positions(){
	return z_positions.size();
}

int trajectorymodel::len_x_velocities(){
	return x_velocities.size();
}
int trajectorymodel::len_y_velocities(){
	return y_velocities.size();
}
int trajectorymodel::len_z_velocities(){
	return z_velocities.size();
}

int trajectorymodel::len_halftimes() {
	return halftimes.size();
}

int trajectorymodel::len_x_accelerations(){
	return x_accelerations.size();
}
int trajectorymodel::len_y_accelerations(){
	return y_accelerations.size();
}
int trajectorymodel::len_z_accelerations(){
	return z_accelerations.size();
}

// Parameter passing for stage holders
int trajectorymodel::pushback_stage_impulses(double entry) {
	stage_impulses.push_back(entry);
	return 0;
}
int trajectorymodel::pushback_stage_burn_times(double entry) {
	stage_burn_times.push_back(entry);
	return 0;
}
int trajectorymodel::pushback_stage_delay_times(double entry) {
	stage_delay_times.push_back(entry);
	return 0;
}
int trajectorymodel::pushback_stage_total_masses(double entry) {
	stage_total_masses.push_back(entry);
	return 0;
}
int trajectorymodel::pushback_stage_dry_masses(double entry) {
	stage_dry_masses.push_back(entry);
	return 0;
}
int trajectorymodel::pushback_stage_mass_rate_changes(double entry) {
	stage_mass_rate_changes.push_back(entry);
	return 0;
}

int trajectorymodel::clear_stage_impulses() {
	stage_impulses.clear();
	return 0;
}
int trajectorymodel::clear_stage_burn_times() {
	stage_burn_times.clear();
	return 0;
}
int trajectorymodel::clear_stage_delay_times() {
	stage_delay_times.clear();
	return 0;
}
int trajectorymodel::clear_stage_total_masses() {
	stage_total_masses.clear();
	return 0;
}
int trajectorymodel::clear_stage_dry_masses() {
	stage_dry_masses.clear();
	return 0;
}
int trajectorymodel::clear_stage_mass_rate_changes() {
	stage_mass_rate_changes.clear();
	return 0;
}

// Setting conditions
int trajectorymodel::set_timestep_size(double timestep_size_input) {
	timestep_size = timestep_size_input;
	return 0;
}
int trajectorymodel::set_horizontal_direction(double horizontal_direction_input) {
	horizontal_direction = horizontal_direction_input;
	return 0;
}
int trajectorymodel::set_vertical_direction(double vertical_direction_input) {
	vertical_direction = vertical_direction_input;
	return 0;
}
int trajectorymodel::set_starting_altitude(double starting_altitude_input) {
	starting_altitude = starting_altitude_input;
	return 0;
}
int trajectorymodel::set_launch_rail_length(double launch_rail_length_input) {
	launch_rail_length = launch_rail_length_input;
	return 0;
}
int trajectorymodel::set_initial_mass(double initial_mass_input) {
	initial_mass = initial_mass_input;
	return 0;
}

int trajectorymodel::set_rocket_diameter(double rocket_diameter_input) {
	rocket_diameter = rocket_diameter_input;
	return 0;
}
int trajectorymodel::set_rocket_cd(double rocket_cd_input) {
	rocket_cd = rocket_cd_input;
	return 0;
}
int trajectorymodel::set_parachute_diameter(double parachute_diameter_input) {
	parachute_diameter = parachute_diameter_input;
	return 0;
}
int trajectorymodel::set_parachute_cd(double parachute_cd_input) {
	parachute_cd = parachute_cd_input;
	return 0;
}


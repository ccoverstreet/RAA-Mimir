// mimirbackend.h
// Cale Overstreet 11/27/2019
// Interface for mimir backend. Interface itself uses "C" to externalize C++ functions to be used by Python Ctypes.

#ifndef LIBMIMIR
#define LIBMIMIR

#include <iostream>
#include <vector>

class trajectorymodel {
	private:
		std::vector<double> times;
		std::vector<double> x_positions;
		std::vector<double> y_positions;
		std::vector<double> z_positions;
		std::vector<double> x_velocities;
		std::vector<double> y_velocities;
		std::vector<double> z_velocities;

		std::vector<double> halftimes;
		std::vector<double> x_accelerations;
		std::vector<double> y_accelerations;
		std::vector<double> z_accelerations;

		std::vector<double> stage_impulses;
		std::vector<double> stage_burn_times;
		std::vector<double> stage_delay_times;
		std::vector<double> stage_total_masses;
		std::vector<double> stage_dry_masses;
		std::vector<double> stage_mass_rate_changes;
		std::vector<double> stage_average_forces;
		std::vector<int> stage_separation;

		std::vector<std::vector<double>> stage_firing_and_glide_times;

		//Initial Conditions
		double timestep_size = -1;
		double horizontal_direction = -1;
		double vertical_direction = -1;
		double starting_altitude = -1;
		double launch_rail_length = -1;
		double initial_mass = -1;

		//Rocket Characteristics
		double rocket_diameter = -1;
		double rocket_cd = -1;
		double parachute_diameter = -1;
		double parachute_cd = -1;

		// Result values like apogee and whatnot
		double apogee = -1;
		double apogee_time = -1;
		double max_speed = -1;
		double max_speed_time = -1;
		double max_acceleration = -1;
		double final_mass = -1;


	public:
		~trajectorymodel();
		void identify(); // Prints out object type. Used for setup testing.

		int prepare_model();
		int calculate_trajectory(); // Main trajectory calculating function

		// Get declarations
		double get_times(int);
		double get_x_positions(int);
		double get_y_positions(int);
		double get_z_positions(int);
		double get_x_velocities(int);
		double get_y_velocities(int);
		double get_z_velocities(int);
		double get_halftimes(int);
		double get_x_accelerations(int);
		double get_y_accelerations(int);
		double get_z_accelerations(int);

		int len_times();
		int len_x_positions();
		int len_y_positions();
		int len_z_positions();
		int len_x_velocities();
		int len_y_velocities();
		int len_z_velocities();
		int len_halftimes();
		int len_x_accelerations();
		int len_y_accelerations();
		int len_z_accelerations();


		int pushback_stage_impulses(double); // Returns 0 for no error
		int pushback_stage_burn_times(double); // Returns 0 for no error
		int pushback_stage_delay_times(double); // Returns 0 for no error
		int pushback_stage_total_masses(double); // Returns 0 for no error
		int pushback_stage_dry_masses(double); // Returns 0 for no error
		int pushback_stage_mass_rate_changes(double); // Returns 0 for no error

		int clear_stage_impulses(); // Return 0 for no error
		int clear_stage_burn_times(); // Return 0 for no error
		int clear_stage_delay_times(); // Return 0 for no error
		int clear_stage_total_masses(); // Return 0 for no error
		int clear_stage_dry_masses(); // Return 0 for no error
		int clear_stage_mass_rate_changes(); // Return 0 for no error

		int set_timestep_size(double); // Return 0 for no error
		int set_horizontal_direction(double); // Return 0 for no error
		int set_vertical_direction(double); // Return 0 for no error
		int set_starting_altitude(double); // Return 0 for no error
		int set_launch_rail_length(double); // Return 0 for no error
		int set_initial_mass(double); // Return 0 for no error
		int set_rocket_diameter(double); // Return 0 for no error
		int set_rocket_cd(double); // Return 0 for no error
		int set_parachute_diameter(double); // Return 0 for no error
		int set_parachute_cd(double); // return 0 for no error
		
		// Getters for discrete values
		double get_timestep_size(); 
		double get_horizontal_direction(); 
		double get_vertical_direction(); 
		double get_starting_altitude(); 
		double get_launch_rail_length(); 
		double get_initial_mass(); 
		double get_rocket_diameter(); 
		double get_rocket_cd(); 
		double get_parachute_diameter(); 
		double get_parachute_cd(); 

		// Getters for result values
		double get_apogee();
		double get_apogee_time();
		double get_max_speed();
		double get_max_speed_time();


};

// START OF C INTERFACE DECLARATIONS
// Declarations for interfacing with trajectorymodel object
extern "C" {
	trajectorymodel* create_trajectorymodel () {
		return new trajectorymodel;
	}

	void delete_trajectorymodel(trajectorymodel* ptr) {
		std::cout << ptr;
	}

	int calculate_trajectory(trajectorymodel* ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->calculate_trajectory();
	}

	// Getters for each holder vector
	double get_times(trajectorymodel* ptr, int index) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_times(index);
	}

	double get_x_positions(trajectorymodel* ptr, int index) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_x_positions(index);
	}
	double get_y_positions(trajectorymodel* ptr, int index) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_y_positions(index);
	}
	double get_z_positions(trajectorymodel* ptr, int index) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_z_positions(index);
	}

	double get_x_velocities(trajectorymodel* ptr, int index) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_x_velocities(index);
	}
	double get_y_velocities(trajectorymodel* ptr, int index) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_y_velocities(index);
	}
	double get_z_velocities(trajectorymodel* ptr, int index) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_z_velocities(index);
	}

	double get_halftimes(trajectorymodel* ptr, int index) {		
		return reinterpret_cast<trajectorymodel*>(ptr)->get_halftimes(index);
	}

	double get_x_accelerations(trajectorymodel* ptr, int index) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_x_accelerations(index);
	}
	double get_y_accelerations(trajectorymodel* ptr, int index) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_y_accelerations(index);
	}
	double get_z_accelerations(trajectorymodel* ptr, int index) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_z_accelerations(index);
	}
	

	// Size getters for vectors
	int len_times(trajectorymodel* ptr) { // Returns length of x_positions vector
		return reinterpret_cast<trajectorymodel*>(ptr)->len_times();
	}

	int len_x_positions(trajectorymodel* ptr) { // Returns length of x_positions vector
		return reinterpret_cast<trajectorymodel*>(ptr)->len_x_positions();
	}
	int len_y_positions(trajectorymodel* ptr) { // Returns length of y_positions vector
		return reinterpret_cast<trajectorymodel*>(ptr)->len_y_positions();
	}
	int len_z_positions(trajectorymodel* ptr) { // Returns length of z_positions vector
		return reinterpret_cast<trajectorymodel*>(ptr)->len_z_positions();
	}
	
	int len_x_velocities(trajectorymodel* ptr) { // Returns length of x_velocities vector
		return reinterpret_cast<trajectorymodel*>(ptr)->len_x_velocities();
	}
	int len_y_velocities(trajectorymodel* ptr) { // Returns length of y_velocities vector
		return reinterpret_cast<trajectorymodel*>(ptr)->len_y_velocities();
	}
	int len_z_velocities(trajectorymodel* ptr) { // Returns length of z_velocities vector
		return reinterpret_cast<trajectorymodel*>(ptr)->len_z_velocities();
	}

	int len_halftimes(trajectorymodel* ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->len_halftimes();
	}

	int len_x_accelerations(trajectorymodel* ptr) { // Returns length of x_accelerations vector
		return reinterpret_cast<trajectorymodel*>(ptr)->len_x_accelerations();
	}
	int len_y_accelerations(trajectorymodel* ptr) { // Returns length of y_accelerations vector
		return reinterpret_cast<trajectorymodel*>(ptr)->len_y_accelerations();
	}
	int len_z_accelerations(trajectorymodel* ptr) { // Returns length of z_accelerations vector
		return reinterpret_cast<trajectorymodel*>(ptr)->len_z_accelerations();
	}


	int pushback_stage_impulses(trajectorymodel*ptr, double entry) {
		return reinterpret_cast<trajectorymodel*>(ptr)->pushback_stage_impulses(entry);
	}
	int pushback_stage_burn_times(trajectorymodel*ptr, double entry) {
		return reinterpret_cast<trajectorymodel*>(ptr)->pushback_stage_burn_times(entry);
	}
	int pushback_stage_delay_times(trajectorymodel*ptr, double entry) {
		return reinterpret_cast<trajectorymodel*>(ptr)->pushback_stage_delay_times(entry);
	}
	int pushback_stage_total_masses(trajectorymodel*ptr, double entry) {
		return reinterpret_cast<trajectorymodel*>(ptr)->pushback_stage_total_masses(entry);
	}
	int pushback_stage_dry_masses(trajectorymodel*ptr, double entry) {
		return reinterpret_cast<trajectorymodel*>(ptr)->pushback_stage_dry_masses(entry);
	}
	int pushback_stage_mass_rate_changes(trajectorymodel*ptr, double entry) {
		return reinterpret_cast<trajectorymodel*>(ptr)->pushback_stage_mass_rate_changes(entry);
	}
	
	int clear_stage_impulses(trajectorymodel*ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->clear_stage_impulses();
	}
	int clear_stage_burn_times(trajectorymodel*ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->clear_stage_burn_times();
	}
	int clear_stage_delay_times(trajectorymodel*ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->clear_stage_delay_times();
	}
	int clear_stage_total_masses(trajectorymodel*ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->clear_stage_total_masses();
	}
	int clear_stage_dry_masses(trajectorymodel*ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->clear_stage_dry_masses();
	}
	int clear_stage_mass_rate_changes(trajectorymodel*ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->clear_stage_mass_rate_changes();
	}

	int set_timestep_size(trajectorymodel* ptr, double timestep_size) {
		return reinterpret_cast<trajectorymodel*>(ptr)->set_timestep_size(timestep_size);
	}
	int set_horizontal_direction(trajectorymodel* ptr, double horizontal_direction) {
		return reinterpret_cast<trajectorymodel*>(ptr)->set_horizontal_direction(horizontal_direction);
	}
	int set_vertical_direction(trajectorymodel* ptr, double vertical_direction) {
		return reinterpret_cast<trajectorymodel*>(ptr)->set_vertical_direction(vertical_direction);
	}
	int set_starting_altitude(trajectorymodel* ptr, double starting_altitude) {
		return reinterpret_cast<trajectorymodel*>(ptr)->set_starting_altitude(starting_altitude);
	}
	int set_launch_rail_length(trajectorymodel* ptr, double launch_rail_length) {
		return reinterpret_cast<trajectorymodel*>(ptr)->set_launch_rail_length(launch_rail_length);
	}
	int set_initial_mass(trajectorymodel* ptr, double initial_mass) {
		return reinterpret_cast<trajectorymodel*>(ptr)->set_initial_mass(initial_mass);
	}

	int set_rocket_diameter(trajectorymodel* ptr, double rocket_diameter) {
		return reinterpret_cast<trajectorymodel*>(ptr)->set_rocket_diameter(rocket_diameter);
	}
	int set_rocket_cd(trajectorymodel* ptr, double rocket_cd) {
		return reinterpret_cast<trajectorymodel*>(ptr)->set_rocket_cd(rocket_cd);
	}
	int set_parachute_diameter(trajectorymodel* ptr, double parachute_diameter) {
		return reinterpret_cast<trajectorymodel*>(ptr)->set_parachute_diameter(parachute_diameter);
	}
	int set_parachute_cd(trajectorymodel* ptr, double parachute_cd) {
		return reinterpret_cast<trajectorymodel*>(ptr)->set_parachute_cd(parachute_cd);
	}

	double get_timestep_size(trajectorymodel* ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_timestep_size();
	}
	double get_horizontal_direction(trajectorymodel* ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_horizontal_direction();
	}
	double get_vertical_direction(trajectorymodel* ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_vertical_direction();
	}
	double get_starting_altitude(trajectorymodel* ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_starting_altitude();
	}
	double get_launch_rail_length(trajectorymodel* ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_launch_rail_length();
	}
	double get_initial_mass(trajectorymodel* ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_initial_mass();
	}
	double get_rocket_diameter(trajectorymodel* ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_rocket_diameter();
	}
	double get_rocket_cd(trajectorymodel* ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_rocket_cd();
	}
	double get_parachute_diameter(trajectorymodel* ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_parachute_diameter();
	}
	double get_parachute_cd(trajectorymodel* ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_parachute_cd();
	}
	double get_max_speed(trajectorymodel* ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_max_speed();
	}
	double get_max_speed_time(trajectorymodel* ptr) {
		return reinterpret_cast<trajectorymodel*>(ptr)->get_max_speed_time();
	}
}

#endif

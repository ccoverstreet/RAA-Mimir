// mimirbackend.cpp
// Cale Overstreet 11/27/2019
// Source code for "C" interface for mimirbackend. 


#include "mimirbackend.h"

#include <iostream>
#include <new> // Used for creating object pointer
#include <vector>

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


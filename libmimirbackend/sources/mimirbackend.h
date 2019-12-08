// mimirbackend.h
// Cale Overstreet 11/27/2019
// Interface for mimir backend. Interface itself uses "C" to externalize C++ functions to be used by Python Ctypes.

#pragma once

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


	public:
		~trajectorymodel();
		void identify(); // Prints out object type. Used for setup testing.
		int fill_data(int);

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
};

// START OF C INTERFACE DECLARATIONS
// Declarations for interfacing with trajectorymodel object
extern "C" {
	trajectorymodel* create_trajectorymodel () {
		return new trajectorymodel;
	}

	void delete_trajectorymodel(trajectorymodel* ptr) {
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

	int trajectorymodel_fill_data(trajectorymodel* ptr, int size) {
		return reinterpret_cast<trajectorymodel*>(ptr)->fill_data(size);
	}

}

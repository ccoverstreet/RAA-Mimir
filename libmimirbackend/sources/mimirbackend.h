// mimirbackend.h
// Cale Overstreet 11/27/2019
// Interface for mimir backend. Interface itself uses "C" to externalize C++ functions to be used by Python Ctypes.

#pragma once

#include <iostream>
#include <vector>

class trajectorymodel {

	public:
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

		~trajectorymodel();
		void identify(); // Prints out object type. Used for setup testing.
		int fill_data(int);
		double index_data(int);

};

// START OF C INTERFACE DECLARATIONS
// Declarations for interfacing with trajectorymodel object
extern "C" {
	trajectorymodel* create_trajectorymodel () {
		return new trajectorymodel;
	}

	void delete_trajectorymodel(trajectorymodel* ptr) {
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
	}

	// Interactions with x_positions
	double get_times(trajectorymodel* ptr, int index) {
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->times[index];
	}
	int len_times(trajectorymodel* ptr) { // Returns length of x_positions vector
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->times.size();
	}

	// Interactions with x_positions
	double get_x_positions(trajectorymodel* ptr, int index) {
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->x_positions[index];
	}
	int len_x_positions(trajectorymodel* ptr) { // Returns length of x_positions vector
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->x_positions.size();
	}

	//Interactions with y_positions
	double get_y_positions(trajectorymodel* ptr, int index) {
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->y_positions[index];
	}
	int len_y_positions(trajectorymodel* ptr) { // Returns length of x_positions vector
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->y_positions.size();
	}

	// Interactions with z_positions
	double get_z_positions(trajectorymodel* ptr, int index) {
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->z_positions[index];
	}
	int len_z_positions(trajectorymodel* ptr) { // Returns length of x_positions vector
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->z_positions.size();
	}
	
	double get_x_velocities(trajectorymodel* ptr, int index) {
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->x_velocities[index];
	}
	int len_x_velocities(trajectorymodel* ptr) { // Returns length of x_velocities vector
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->x_velocities.size();
	}

	double get_y_velocities(trajectorymodel* ptr, int index) {
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->y_velocities[index];
	}
	int len_y_velocities(trajectorymodel* ptr) { // Returns length of y_velocities vector
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->y_velocities.size();
	}

	double get_z_velocities(trajectorymodel* ptr, int index) {
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->z_velocities[index];
	}
	int len_z_velocities(trajectorymodel* ptr) { // Returns length of z_velocities vector
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->z_velocities.size();
	}

	double get_halftimes(trajectorymodel* ptr, int index) {
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->halftimes[index];
	}
	int len_halftimes(trajectorymodel* ptr) { // Returns length of halftimes vector
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->halftimes.size();
	}

	double get_x_accelerations(trajectorymodel* ptr, int index) {
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->x_accelerations[index];
	}
	int len_x_accelerations(trajectorymodel* ptr) { // Returns length of x_accelerations vector
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->x_accelerations.size();
	}

	double get_y_accelerations(trajectorymodel* ptr, int index) {
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->y_accelerations[index];
	}
	int len_y_accelerations(trajectorymodel* ptr) { // Returns length of y_accelerations vector
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->y_accelerations.size();
	}


	double get_z_accelerations(trajectorymodel* ptr, int index) {
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->z_accelerations[index];
	}
	int len_z_accelerations(trajectorymodel* ptr) { // Returns length of z_accelerations vector
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref->z_accelerations.size();
	}



	int trajectorymodel_fill_data(trajectorymodel* ptr, int size) {
		trajectorymodel* ref = reinterpret_cast<trajectorymodel*>(ptr);
		return ref -> fill_data(size);
	}

}

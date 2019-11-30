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

void trajectorymodel::identify() {
	printf("This object is a trajectorymodel object\n");
}



int trajectorymodel::fill_data(int size) {
	
	for (int i = 0; i < size; i++) {
		times.push_back(i / double(10));
		x_positions.push_back(i / double(3));
		y_positions.push_back(2 * i / double(3));
		z_positions.push_back(4 * i / double(3));


		x_velocities.push_back(3*i / double(3));
		y_velocities.push_back(5 * i / double(3));
		z_velocities.push_back(7 * i / double(3));
	}

	for (int i = 0; i < size - 1; i++) {
		halftimes.push_back(i / double(10) + 0.05);
		x_accelerations.push_back(3*i / double(3));
		y_accelerations.push_back(5 * i / double(3));
		z_accelerations.push_back(7 * i / double(3));
	}

	return 0;
}





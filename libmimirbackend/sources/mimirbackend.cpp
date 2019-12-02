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



// RAA Mimir: Qt GUI Interface
// Cale Overstreet
// February 7, 2020
// This is the main entrypoint for the RAA Mimir GUI Interface. I have decided to write the interface in C++ and Qt to make it more portable and memory efficient. The exact structure of the GUI program is still to be decided.

#include <iostream>

// Include Mimir Backend Library
#include "../libmimirbackend/sources/mimirbackend.h"

void test_mimirbackend() {
	
	printf("\nTesting Mimir Backend...\n");

	trajectorymodel x;

	printf("\tSetting parameters...\n");
	x.set_timestep_size(0.001);
	x.set_horizontal_direction(0);
	x.set_vertical_direction(80);
	x.set_starting_altitude(0);
	x.set_launch_rail_length(1);
	x.set_initial_mass(0.1);
	x.set_rocket_diameter(0.01);
	x.set_rocket_cd(0.2);
	x.set_parachute_diameter(0.4);
	x.set_parachute_cd(1.2);

	printf("\tAdding Stage Info...\n");
	x.pushback_stage_impulses(5);
	x.pushback_stage_burn_times(2);
	x.pushback_stage_delay_times(1000);
	x.pushback_stage_total_masses(0.1);
	x.pushback_stage_dry_masses(0.07);

	printf("\tIdentifying Model...\n\n");
	x.identify();

	printf("\n\tPreparing model...\n");
	x.prepare_model();	

	printf("\tRunning Trajectory Calculation...\n");
	x.calculate_trajectory();
	printf("\tFinished Calculation\n");
	printf("\n\tResults:\n");
	printf("\t\tApogee: %f\n", x.get_apogee());
	printf("\t\tTime of Apogee: %f\n", x.get_apogee_time());
	
}

int main() {
	printf("RAA Mimir\n");
	printf("Cale Overstreet\n");
	printf("February 7, 2020\n");

	// Test function to make sure library functions correctly
	test_mimirbackend();
	
	return 0;
}

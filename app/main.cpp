#include <iostream>

// Include Mimir Backend Library
#include "../libmimirbackend/sources/mimirbackend.h"

void test_mimirbackend() {
	printf("Testing Mimir Backend...\n");

	trajectorymodel x;
	x.set_timestep_size(0.000001);
	x.set_horizontal_direction(0);
	x.set_vertical_direction(80);
	x.set_starting_altitude(0);
	x.set_launch_rail_length(1);
	x.set_initial_mass(0.1);
	x.set_rocket_diameter(0.01);
	x.set_rocket_cd(0.2);
	x.set_parachute_diameter(0.4);
	x.set_parachute_cd(1.2);
	x.pushback_stage_impulses(5);
	x.pushback_stage_burn_times(2);
	x.pushback_stage_delay_times(1000);
	x.pushback_stage_total_masses(0.1);
	x.pushback_stage_dry_masses(0.07);
	x.prepare_model();	
	x.calculate_trajectory();
	std::cout << x.get_apogee();
}

int main() {
	printf("Hello\n");
	test_mimirbackend();
	
	return 0;
}

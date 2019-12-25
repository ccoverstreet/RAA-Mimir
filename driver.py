import mimirpywrapper.trajectorymodel as mimir
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


def Gen_Test_1():
    print("General Test 1")
    print("\tCreating Model")
    x = mimir.trajectorymodel()
    
    print("\tSetting Parameters")
    # Setting parameters
    timestep = 0.01
    x.set_timestep_size(timestep)
    x.set_stage_impulses([3])
    x.set_stage_burn_times([1])
    x.set_stage_delay_times([999])
    x.set_stage_total_masses([0.100])
    x.set_stage_dry_masses([0.05])
    x.set_rocket_diameter(0.01)
    x.set_rocket_cd(0.2)
    x.set_parachute_diameter(0.2)
    x.set_parachute_cd(1)
    x.set_vertical_direction(85)
    x.set_horizontal_direction(45)
    x.set_initial_mass(0.100)
    x.set_starting_altitude(0)
    x.set_launch_rail_length(1)

    # Running Calculations
    print("\tStarting calculation with timestep {} seconds".format(timestep))
    x.calculate_trajectory()


    # Plotting results
    x.print_results()
    x.plot_results()



def main():
    print("Test driver for Mimir Backend Library and Wrapper")

    Gen_Test_1()

if __name__ == "__main__":
    main()

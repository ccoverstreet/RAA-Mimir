import mimirpywrapper.trajectorymodel as mimir
import matplotlib.pyplot as plt




def main():
    print("Test driver for Mimir Backend Library and Wrapper")
    x = mimir.trajectorymodel()

    # Setting parameters
    x.set_stage_impulses([5])
    x.set_stage_burn_times([1])
    x.set_stage_delay_times([1])
    x.set_stage_total_masses([0.2])
    x.set_stage_dry_masses([0.1])
    x.set_rocket_diameter(0.05)
    x.set_rocket_cd(0.2)
    x.set_parachute_diameter(0.2)
    x.set_parachute_cd(1)
    x.set_vertical_direction(90)
    x.set_horizontal_direction(0)
    x.set_initial_mass(0.2)

    x.set_timestep_size(0.01)

    x.calculate_trajectory()

    print(x.times[len(x.times) - 1])

    plt.plot(x.times, x.z_positions)
    plt.show()

    '''
    for i in range(0, len(x.times)):
        print("{}, {}".format(x.times[i], x.z_positions[i]))
    '''

    x.clear_stage_impulses()
    x.clear_stage_burn_times()
    x.clear_stage_delay_times()
    x.clear_stage_total_masses()
    x.clear_stage_dry_masses()
    x.clear_stage_mass_rate_changes()


if __name__ == "__main__":
    main()

import mimirpywrapper.trajectorymodel as mimir
import matplotlib.pyplot as plt



def main():
    print("Test driver for Mimir Backend Library and Wrapper")
    x = mimir.trajectorymodel()

    fillsize = 20

    print("\nFilling data structures with {} points".format(fillsize))
    x.fill_data(fillsize)

    print("\nLengths of each data structure vector:")
    print("\ttimes: {}".format(len(x.times)))
    print("\thalftimes: {}".format(len(x.halftimes)))
    print("\tx_positions: {}".format(len(x.x_positions)))
    print("\ty_positions: {}".format(len(x.y_positions)))
    print("\tz_positions: {}".format(len(x.z_positions)))
    print("\tx_velocities: {}".format(len(x.x_velocities)))
    print("\ty_velocities: {}".format(len(x.y_velocities)))
    print("\tz_velocities: {}".format(len(x.z_velocities)))
    print("\tx_accelerations: {}".format(len(x.x_accelerations)))
    print("\ty_accelerations: {}".format(len(x.y_accelerations)))
    print("\tz_accelerations: {}".format(len(x.z_accelerations)))

    print("\nIndexing times and x-positions")
    for i in range(0, len(x.x_positions)):
        print("\t{}, {}".format(x.times[i], x.x_positions[i]))

    plt.plot(x.times, x.x_positions)
    plt.xlabel("Time (s)")
    plt.ylabel("X-Position (m)")
    plt.title("Example model output using fill_data member function")
    plt.show()


    x.set_stage_impulses([1, 2.3, 4, 5])
    x.set_stage_burn_times([1, 2, 4, 5])
    x.set_stage_delay_times([1, 2.3, 4, 5])
    x.set_stage_total_masses([1, 2.3, 4, 5])
    x.set_stage_dry_masses([0, 1, 2, 2.5])

    x.set_timestep_size(0.01)

    x.calculate_trajectory()

    x.clear_stage_impulses()
    x.clear_stage_burn_times()
    x.clear_stage_delay_times()
    x.clear_stage_total_masses()
    x.clear_stage_dry_masses()
    x.clear_stage_mass_rate_changes()


if __name__ == "__main__":
    main()

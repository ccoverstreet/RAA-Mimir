from ctypes import *
import os

import matplotlib.pyplot as plt


mimir_dir = os.path.abspath(__file__).replace("/mimirpywrapper/trajectorymodel.py", "")

lib = cdll.LoadLibrary(os.path.abspath(mimir_dir + "/libmimirbackend/libmimirbackend.so"))

# create_trajectorymodel type definitions
lib.create_trajectorymodel.restype = c_void_p

lib.get_times.argtypes = [c_void_p, c_int]
lib.get_times.restype = c_double
lib.len_times.argtypes = [c_void_p]
lib.len_times.restype = c_int

lib.get_x_positions.argtypes = [c_void_p, c_int]
lib.get_x_positions.restype = c_double
lib.len_x_positions.argtypes = [c_void_p]
lib.len_x_positions.restype = c_int

lib.get_y_positions.argtypes = [c_void_p, c_int]
lib.get_y_positions.restype = c_double
lib.len_y_positions.argtypes = [c_void_p]
lib.len_y_positions.restype = c_int

lib.get_z_positions.argtypes = [c_void_p, c_int]
lib.get_z_positions.restype = c_double
lib.len_z_positions.argtypes = [c_void_p]
lib.len_z_positions.restype = c_int

lib.get_x_velocities.argtypes = [c_void_p, c_int]
lib.get_x_velocities.restype = c_double
lib.len_x_velocities.argtypes = [c_void_p]
lib.len_x_velocities.restype = c_int

lib.get_y_velocities.argtypes = [c_void_p, c_int]
lib.get_y_velocities.restype = c_double
lib.len_y_velocities.argtypes = [c_void_p]
lib.len_y_velocities.restype = c_int

lib.get_z_velocities.argtypes = [c_void_p, c_int]
lib.get_z_velocities.restype = c_double
lib.len_z_velocities.argtypes = [c_void_p]
lib.len_z_velocities.restype = c_int

lib.get_halftimes.argtypes = [c_void_p, c_int]
lib.get_halftimes.restype = c_double
lib.len_halftimes.argtypes = [c_void_p]
lib.len_halftimes.restype = c_int

lib.get_x_accelerations.argtypes = [c_void_p, c_int]
lib.get_x_accelerations.restype = c_double
lib.len_x_accelerations.argtypes = [c_void_p]
lib.len_x_accelerations.restype = c_int

lib.get_y_accelerations.argtypes = [c_void_p, c_int]
lib.get_y_accelerations.restype = c_double
lib.len_y_accelerations.argtypes = [c_void_p]
lib.len_y_accelerations.restype = c_int

lib.get_z_accelerations.argtypes = [c_void_p, c_int]
lib.get_z_accelerations.restype = c_double
lib.len_z_accelerations.argtypes = [c_void_p]
lib.len_z_accelerations.restype = c_int

lib.pushback_stage_impulses.argtypes = [c_void_p, c_double]
lib.pushback_stage_impulses.restype = c_int

lib.pushback_stage_burn_times.argtypes = [c_void_p, c_double]
lib.pushback_stage_burn_times.restype = c_int

lib.pushback_stage_delay_times.argtypes = [c_void_p, c_double]
lib.pushback_stage_delay_times.restype = c_int

lib.pushback_stage_total_masses.argtypes = [c_void_p, c_double]
lib.pushback_stage_total_masses.restype = c_int

lib.pushback_stage_dry_masses.argtypes = [c_void_p, c_double]
lib.pushback_stage_dry_masses.restype = c_int

lib.clear_stage_impulses.argtypes = [c_void_p]
lib.clear_stage_impulses.restype = c_int

lib.clear_stage_burn_times.argtypes = [c_void_p]
lib.clear_stage_burn_times.restype = c_int

lib.clear_stage_delay_times.argtypes = [c_void_p]
lib.clear_stage_delay_times.restype = c_int

lib.clear_stage_total_masses.argtypes = [c_void_p]
lib.clear_stage_total_masses.restype = c_int

lib.clear_stage_dry_masses.argtypes = [c_void_p]
lib.clear_stage_dry_masses.restype = c_int

lib.clear_stage_mass_rate_changes.argtypes = [c_void_p]
lib.clear_stage_mass_rate_changes.restype = c_int

lib.set_timestep_size.argtypes = [c_void_p, c_double]
lib.set_timestep_size.restype = c_int

lib.set_horizontal_direction.argtypes = [c_void_p, c_double]
lib.set_horizontal_direction.restype = c_int

lib.set_vertical_direction.argtypes = [c_void_p, c_double]
lib.set_vertical_direction.restype = c_int

lib.set_starting_altitude.argtypes = [c_void_p, c_double]
lib.set_starting_altitude.restype = c_int

lib.set_launch_rail_length.argtypes = [c_void_p, c_double]
lib.set_launch_rail_length.restype = c_int

lib.set_initial_mass.argtypes = [c_void_p, c_double]
lib.set_initial_mass.restype = c_int

lib.set_rocket_diameter.argtypes = [c_void_p, c_double]
lib.set_rocket_diameter.restype = c_int

lib.set_rocket_cd.argtypes = [c_void_p, c_double]
lib.set_rocket_cd.restype = c_int

lib.set_parachute_diameter.argtypes = [c_void_p, c_double]
lib.set_parachute_diameter.restype = c_int

lib.set_parachute_cd.argtypes = [c_void_p, c_double]
lib.set_parachute_cd.restype = c_int

lib.get_timestep_size.argtypes = [c_void_p]
lib.get_timestep_size.restype = c_double

lib.get_horizontal_direction.argtypes = [c_void_p]
lib.get_horizontal_direction.restype = c_double

lib.get_vertical_direction.argtypes = [c_void_p]
lib.get_vertical_direction.restype = c_double

lib.get_starting_altitude.argtypes = [c_void_p]
lib.get_starting_altitude.restype = c_double

lib.get_launch_rail_length.argtypes = [c_void_p]
lib.get_launch_rail_length.restype = c_double

lib.get_initial_mass.argtypes = [c_void_p]
lib.get_initial_mass.restype = c_double

lib.get_rocket_diameter.argtypes = [c_void_p]
lib.get_rocket_diameter.restype = c_double

lib.get_rocket_cd.argtypes = [c_void_p]
lib.get_rocket_cd.restype = c_double

lib.get_parachute_diameter.argtypes = [c_void_p]
lib.get_parachute_diameter.restype = c_double

lib.get_parachute_cd.argtypes = [c_void_p]
lib.get_parachute_cd.restype = c_double

lib.get_max_speed.argtypes = [c_void_p]
lib.get_max_speed.restype = c_double

lib.get_max_speed_time.argtypes = [c_void_p]
lib.get_max_speed_time.restype = c_double

lib.calculate_trajectory.argtypes = [c_void_p]
lib.calculate_trajectory.restype = c_int

lib.trajectorymodel_fill_data.argtypes = [c_void_p, c_int]


class trajectorymodel():
    def __init__(self):
        self.ptr = lib.create_trajectorymodel()

        self.times = times(self.ptr)
        self.x_positions = x_positions(self.ptr)
        self.y_positions = y_positions(self.ptr)
        self.z_positions = z_positions(self.ptr)
        self.x_velocities = x_velocities(self.ptr)
        self.y_velocities = y_velocities(self.ptr)
        self.z_velocities = z_velocities(self.ptr)

        self.halftimes = halftimes(self.ptr)
        self.x_accelerations = x_accelerations(self.ptr)
        self.y_accelerations = y_accelerations(self.ptr)
        self.z_accelerations = z_accelerations(self.ptr)

        # Setting unset discrete values to -1, used to make sure that all values are set beforehand
        self.timestep_size = -1
        self.horizontal_direction = -1
        self.vertical_direction = -1
        self.starting_altitude = -1
        self.launch_rail_length = -1
        self.initial_mass = -1
        self.rocket_diameter = -1
        self.rocket_cd = -1
        self.parachute_diameter = -1
        self.parachute_cd = -1


    def calculate_trajectory(self):
        self.update_initial_values()

        # Checking to see if any values are unset
        for attr in dir(self):
            print(getattr(self, attr))
            if getattr(self, attr) == -1:
                print("Attribute {} not set, please set using the set_{} class method".format(attr, attr))
                return

        lib.calculate_trajectory(self.ptr)

        self.update_initial_values()
        self.update_results()
        print("Calculation finished")

    def print_results(self):
        print("\n\tData Summary:")
        print("\t\tTime of Flight: {}".format(self.times[-1]))
        print("\t\tMax Altitude: {}".format(max(self.z_positions))) # Prints max value
        print("\t\tX Final Position: {}".format(self.x_positions[-1]))    
        print("\t\tY Final Position: {}".format(self.y_positions[-1]))    
        print("\t\tZ Final Position: {}".format(self.z_positions[-1]))    

        print("\t\tX Final Velocity: {}".format(self.x_velocities[-1]))    
        print("\t\tY Final Velocity: {}".format(self.y_velocities[-1]))    
        print("\t\tZ Final Velocity: {}".format(self.z_velocities[-1]))    

        print("\t\tX Final Acceleration: {}".format(self.x_accelerations[-1]))
        print("\t\tY Final Acceleration: {}".format(self.y_accelerations[-1]))
        print("\t\tZ Final Acceleration: {}".format(self.z_accelerations[-1]))

    def plot_results(self):
        # Graphical Output
        fig = plt.figure()
        fig.subplots_adjust(hspace=0.5)
        ax_x_pos = fig.add_subplot(331)
        ax_y_pos = fig.add_subplot(334)
        ax_z_pos = fig.add_subplot(337)

        ax_x_vel = fig.add_subplot(332)
        ax_y_vel = fig.add_subplot(335)
        ax_z_vel = fig.add_subplot(338)

        ax_x_acc = fig.add_subplot(333)
        ax_y_acc = fig.add_subplot(336)
        ax_z_acc = fig.add_subplot(339)

        # Plotting Data
        ax_x_pos.plot(self.times, self.x_positions)
        ax_y_pos.plot(self.times, self.y_positions)
        ax_z_pos.plot(self.times, self.z_positions)

        ax_x_vel.plot(self.times, self.x_velocities)
        ax_y_vel.plot(self.times, self.y_velocities)
        ax_z_vel.plot(self.times, self.z_velocities)

        ax_x_acc.plot(self.halftimes, self.x_accelerations)
        ax_y_acc.plot(self.halftimes, self.y_accelerations)
        ax_z_acc.plot(self.halftimes, self.z_accelerations)

        # Formatting
        ax_x_pos.set_title("X-Position")
        ax_y_pos.set_title("Y-Position")
        ax_z_pos.set_title("Z-Position")

        ax_x_vel.set_title("X-Velocity")
        ax_y_vel.set_title("Y-Velocity")
        ax_z_vel.set_title("Z-Velocity")

        ax_x_acc.set_title("X-Acceleration")
        ax_y_acc.set_title("Y-Acceleration")
        ax_z_acc.set_title("Z-Acceleration")

        ax_x_pos.set_xlabel("Time (s)")
        ax_x_pos.set_ylabel("X-Distance (m)")
        ax_y_pos.set_xlabel("Time (s)")
        ax_y_pos.set_ylabel("Y-Distance (m)")
        ax_z_pos.set_xlabel("Time (s)")
        ax_z_pos.set_ylabel("Altitude (m)")

        ax_x_vel.set_xlabel("Time (s)")
        ax_x_vel.set_ylabel("Velocity (m/s)")
        ax_y_vel.set_xlabel("Time (s)")
        ax_y_vel.set_ylabel("Velocity (m/s)")
        ax_z_vel.set_xlabel("Time (s)")
        ax_z_vel.set_ylabel("Velocity (m/s)")


        ax_x_acc.set_xlabel("Time (s)")
        ax_x_acc.set_ylabel("Acceleration (m/s^2)")
        ax_y_acc.set_xlabel("Time (s)")
        ax_y_acc.set_ylabel("Acceleration (m/s^2)")
        ax_z_acc.set_xlabel("Time (s)")
        ax_z_acc.set_ylabel("Acceleration (m/s^2)")

        # Gets current figure window manager and forces maximized display
        fig_manager = plt.get_current_fig_manager()
        fig_manager.window.showMaximized() 
        plt.show()


    def set_stage_impulses(self, impulses_list):
        self.impulses_list = impulses_list
        for i, value in enumerate(impulses_list):
            lib.pushback_stage_impulses(self.ptr, c_double(value))

    def set_stage_burn_times(self, burn_times_list):
        self.burn_times_list = burn_times_list
        for i, value in enumerate(burn_times_list):
            lib.pushback_stage_burn_times(self.ptr, c_double(value))

    def set_stage_delay_times(self, delay_times_list):
        self.delay_times_list = delay_times_list
        for i, value in enumerate(delay_times_list):
            lib.pushback_stage_delay_times(self.ptr, c_double(value))

    def set_stage_total_masses(self, total_masses_list):
        self.total_masses_list = total_masses_list
        for i, value in enumerate(total_masses_list):
            lib.pushback_stage_total_masses(self.ptr, c_double(value))

    def set_stage_dry_masses(self, dry_masses_list):
        self.dry_masses_list = dry_masses_list
        for i, value in enumerate(dry_masses_list):
            lib.pushback_stage_dry_masses(self.ptr, c_double(value))

    def clear_stage_impulses(self):
        lib.clear_stage_impulses(self.ptr)

    def clear_stage_burn_times(self):
        lib.clear_stage_burn_times(self.ptr)

    def clear_stage_delay_times(self):
        lib.clear_stage_delay_times(self.ptr)

    def clear_stage_total_masses(self):
        lib.clear_stage_total_masses(self.ptr)

    def clear_stage_dry_masses(self):
        lib.clear_stage_dry_masses(self.ptr)

    def clear_stage_mass_rate_changes(self):
        lib.clear_stage_mass_rate_changes(self.ptr)

    def set_timestep_size(self, timestep_size_input):
        lib.set_timestep_size(self.ptr, c_double(timestep_size_input))

    def set_horizontal_direction(self, horizontal_direction_input):
        lib.set_horizontal_direction(self.ptr, c_double(horizontal_direction_input))

    def set_vertical_direction(self, vertical_direction_input):
        lib.set_vertical_direction(self.ptr, c_double(vertical_direction_input))

    def set_starting_altitude(self, starting_altitude_input):
        lib.set_starting_altitude(self.ptr, c_double(starting_altitude_input))

    def set_launch_rail_length(self, launch_rail_length_input):
        lib.set_launch_rail_length(self.ptr, c_double(launch_rail_length_input))

    def set_initial_mass(self, initial_mass_input):
        lib.set_initial_mass(self.ptr, c_double(initial_mass_input))

    def set_rocket_diameter(self, rocket_diameter_input):
        lib.set_rocket_diameter(self.ptr, c_double(rocket_diameter_input))

    def set_rocket_cd(self, rocket_cd_input):
        lib.set_rocket_cd(self.ptr, c_double(rocket_cd_input))

    def set_parachute_diameter(self, parachute_diameter_input):
        lib.set_parachute_diameter(self.ptr, c_double(parachute_diameter_input))

    def set_parachute_cd(self, parachute_cd_input):
        lib.set_parachute_cd(self.ptr, c_double(parachute_cd_input))

    def update_initial_values(self):
        self.timestep_size = lib.get_timestep_size(self.ptr)
        self.horizontal_direction = lib.get_horizontal_direction(self.ptr)
        self.vertical_direction = lib.get_vertical_direction(self.ptr)
        self.starting_altitude = lib.get_starting_altitude(self.ptr)
        self.launch_rail_length = lib.get_launch_rail_length(self.ptr)
        self.initial_mass = lib.get_initial_mass(self.ptr)
        self.rocket_diameter = lib.get_rocket_diameter(self.ptr)
        self.rocket_cd = lib.get_rocket_cd(self.ptr)
        self.parachute_diameter = lib.get_parachute_diameter(self.ptr)
        self.parachute_cd = lib.get_parachute_cd(self.ptr)

    def update_results(self):
        print(lib.get_max_speed_time(self.ptr))
        self.max_speed = (lib.get_max_speed(self.ptr), lib.get_max_speed_time(self.ptr))


    def __del__(self):
        print("\ntrajectorymodel object being deleted")
        lib.delete_trajectorymodel()


class times():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_times(self.parent_ptr, i)

    def __len__(self):
        return lib.len_times(self.parent_ptr)

    def __getitem__(self, index):
        if index >= 0:
            return lib.get_times(self.parent_ptr, index)
        else:
            return lib.get_times(self.parent_ptr, self.__len__() + index)

class x_positions():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_x_positions(self.parent_ptr, i)

    def __len__(self):
        return lib.len_x_positions(self.parent_ptr)

    def __getitem__(self, index):
        if index >= 0:
            return lib.get_x_positions(self.parent_ptr, index)
        else:
            return lib.get_x_positions(self.parent_ptr, self.__len__() + index)

class y_positions():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_y_positions(self.parent_ptr, i)

    def __len__(self):
        return lib.len_y_positions(self.parent_ptr)

    def __getitem__(self, index):
        if index >= 0:
            return lib.get_y_positions(self.parent_ptr, index)
        else:
            return lib.get_y_positions(self.parent_ptr, self.__len__() + index)

class z_positions():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_z_positions(self.parent_ptr, i)

    def __len__(self):
        return lib.len_z_positions(self.parent_ptr)

    def __getitem__(self, index):
        if index >= 0:
            return lib.get_z_positions(self.parent_ptr, index)
        else:
            return lib.get_z_positions(self.parent_ptr, self.__len__() + index)

class x_velocities():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_x_velocities(self.parent_ptr, i)

    def __len__(self):
        return lib.len_x_velocities(self.parent_ptr)

    def __getitem__(self, index):
        if index >= 0:
            return lib.get_x_velocities(self.parent_ptr, index)
        else:
            return lib.get_x_velocities(self.parent_ptr, self.__len__() + index)

class y_velocities():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_y_velocities(self.parent_ptr, i)

    def __len__(self):
        return lib.len_y_velocities(self.parent_ptr)

    def __getitem__(self, index):
        if index >= 0:
            return lib.get_y_velocities(self.parent_ptr, index)
        else:
            return lib.get_y_velocities(self.parent_ptr, self.__len__() + index)

class z_velocities():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_z_velocities(self.parent_ptr, i)

    def __len__(self):
        return lib.len_z_velocities(self.parent_ptr)

    def __getitem__(self, index):
        if index >= 0:
            return lib.get_z_velocities(self.parent_ptr, index)
        else:
            return lib.get_z_velocities(self.parent_ptr, self.__len__() + index)
    

class halftimes():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_halftimes(self.parent_ptr, i)

    def __len__(self):
        return lib.len_halftimes(self.parent_ptr)

    def __getitem__(self, index):
        if index >= 0:
            return lib.get_halftimes(self.parent_ptr, index)
        else:
            return lib.get_z_velocities(self.parent_ptr, self.__len__() + index)

class x_accelerations():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_x_accelerations(self.parent_ptr, i)

    def __len__(self):
        return lib.len_x_accelerations(self.parent_ptr)

    def __getitem__(self, index):
        if index >= 0:
            return lib.get_x_accelerations(self.parent_ptr, index)
        else:
            return lib.get_x_accelerations(self.parent_ptr, self.__len__() + index)

class y_accelerations():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_y_accelerations(self.parent_ptr, i)

    def __len__(self):
        return lib.len_y_accelerations(self.parent_ptr)

    def __getitem__(self, index):
        if index >= 0:
            return lib.get_y_accelerations(self.parent_ptr, index)
        else:
            return lib.get_y_accelerations(self.parent_ptr, self.__len__() + index)

class z_accelerations():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_z_accelerations(self.parent_ptr, i)

    def __len__(self):
        return lib.len_z_accelerations(self.parent_ptr)

    def __getitem__(self, index):
        if index >= 0:
            return lib.get_z_accelerations(self.parent_ptr, index)
        else:
            return lib.get_z_accelerations(self.parent_ptr, self.__len__() + index)


if __name__ == "__main__":
    print("Mimir Python Wrapper Test")

    x = trajectorymodel()

    x.set_stage_impulses([1.2, 3.4, 5.6])
    x.clear_stage_impulses()
    x.set_stage_burn_times([1, 2, 3.3, 4])

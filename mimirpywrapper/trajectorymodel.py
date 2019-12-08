from ctypes import *
import os

lib = cdll.LoadLibrary(os.path.abspath("libmimirbackend/libmimirbackend.so"))

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

lib.pushback_stage_mass_rate_changes.argtypes = [c_void_p, c_double]
lib.pushback_stage_mass_rate_changes.restype = c_int

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

    def set_stage_mass_rate_changes(self, mass_rate_changes_list):
        self.mass_rate_changes_list = mass_rate_changes_list
        for i, value in enumerate(mass_rate_changes_list):
            print(value)
            lib.pushback_stage_mass_rate_changes(self.ptr, c_double(value))

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

    def fill_data(self, size):
        lib.trajectorymodel_fill_data(self.ptr, c_int(size))


    def __del__(self):
        print("trajectorymodel object being deleted")
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
        return lib.get_times(self.parent_ptr, index)

class x_positions():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_x_positions(self.parent_ptr, i)

    def __len__(self):
        return lib.len_x_positions(self.parent_ptr)

    def __getitem__(self, index):
        return lib.get_x_positions(self.parent_ptr, index)

class y_positions():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_y_positions(self.parent_ptr, i)

    def __len__(self):
        return lib.len_y_positions(self.parent_ptr)

    def __getitem__(self, index):
        return lib.get_y_positions(self.parent_ptr, index)

class z_positions():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_z_positions(self.parent_ptr, i)

    def __len__(self):
        return lib.len_z_positions(self.parent_ptr)

    def __getitem__(self, index):
        return lib.get_z_positions(self.parent_ptr, index)

class x_velocities():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_x_velocities(self.parent_ptr, i)

    def __len__(self):
        return lib.len_x_velocities(self.parent_ptr)

    def __getitem__(self, index):
        return lib.get_x_velocities(self.parent_ptr, index)

class y_velocities():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_y_velocities(self.parent_ptr, i)

    def __len__(self):
        return lib.len_y_velocities(self.parent_ptr)

    def __getitem__(self, index):
        return lib.get_y_velocities(self.parent_ptr, index)

class z_velocities():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_z_velocities(self.parent_ptr, i)

    def __len__(self):
        return lib.len_z_velocities(self.parent_ptr)

    def __getitem__(self, index):
        return lib.get_z_velocities(self.parent_ptr, index)
    

class halftimes():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_halftimes(self.parent_ptr, i)

    def __len__(self):
        return lib.len_halftimes(self.parent_ptr)

    def __getitem__(self, index):
        return lib.get_halftimes(self.parent_ptr, index)

class x_accelerations():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_x_accelerations(self.parent_ptr, i)

    def __len__(self):
        return lib.len_x_accelerations(self.parent_ptr)

    def __getitem__(self, index):
        return lib.get_x_accelerations(self.parent_ptr, index)

class y_accelerations():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_y_accelerations(self.parent_ptr, i)

    def __len__(self):
        return lib.len_y_accelerations(self.parent_ptr)

    def __getitem__(self, index):
        return lib.get_y_accelerations(self.parent_ptr, index)

class z_accelerations():
    def __init__(self, ptr):
        self.parent_ptr = ptr

    def __iter__(self):
        for i in range(0, self.__len__()):
            yield lib.get_z_accelerations(self.parent_ptr, i)

    def __len__(self):
        return lib.len_z_accelerations(self.parent_ptr)

    def __getitem__(self, index):
        return lib.get_z_accelerations(self.parent_ptr, index)





if __name__ == "__main__":
    print("Mimir Python Wrapper Test")

    x = trajectorymodel()

    x.set_stage_impulses([1.2, 3.4, 5.6])
    x.clear_stage_impulses()
    x.set_stage_burn_times([1, 2, 3.3, 4])

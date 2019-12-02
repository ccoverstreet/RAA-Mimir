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

lib.trajectorymodel_fill_data.argtypes = [c_void_p, c_int]


class trajectorymodel():
    def __init__(self):
        self.ptr = lib.create_trajectorymodel()

    def get_times(self, index):
        return lib.get_times(self.ptr, index)

    def len_times(self):
        return lib.len_times(self.ptr)


    # POSITIONS INTERACTIONS
    def get_x_positions(self, index):
        return lib.get_x_positions(self.ptr, index)

    def len_x_positions(self):
        return lib.len_x_positions(self.ptr)

    def get_y_positions(self, index):
        return lib.get_y_positions(self.ptr, index)

    def len_y_positions(self):
        return lib.len_y_positions(self.ptr)

    def get_z_positions(self, index):
        return lib.get_z_positions(self.ptr, index)

    def len_z_positions(self):
        return lib.len_z_positions(self.ptr)

    
    # VELOCITY INTERACTIONS
    def get_x_velocities(self, index):
        return lib.get_x_velocities(self.ptr, index)

    def len_x_velocities(self):
        return lib.len_x_velocities(self.ptr)

    def get_y_velocities(self, index):
        return lib.get_y_velocities(self.ptr, index)

    def len_y_velocities(self):
        return lib.len_y_velocities(self.ptr)

    def get_z_velocities(self, index):
        return lib.get_z_velocities(self.ptr, index)

    def len_z_velocities(self):
        return lib.len_z_velocities(self.ptr)


    # HALFTIMES
    def get_halftimes(self, index):
        return lib.get_halftimes(self.ptr, index)

    def len_halftimes(self, index):
        return lib.len_halftimes(self.ptr)


    # ACCELERATION INTERACTIONS
    def get_x_accelerations(self, index):
        return lib.get_x_accelerations(self.ptr, index)

    def len_x_accelerations(self):
        return lib.len_x_accelerations(self.ptr)

    def get_y_accelerations(self, index):
        return lib.get_y_accelerations(self.ptr, index)

    def len_y_accelerations(self):
        return lib.len_y_accelerations(self.ptr)

    def get_z_accelerations(self, index):
        return lib.get_z_accelerations(self.ptr, index)

    def len_z_accelerations(self):
        return lib.len_z_accelerations(self.ptr)




    def fill_data(self, size):
        lib.trajectorymodel_fill_data(self.ptr, c_int(size))


    def __del__(self):
        print("trajectorymodel object being deleted")
        lib.delete_trajectorymodel()


if __name__ == "__main__":
    print("Mimir Python Wrapper Test")

    testobject = trajectorymodel()

    print(testobject.len_x_positions())
    testobject.fill_data(10)

    print("Times and x, y, z positions")
    for i in range(0, testobject.len_x_positions()):
        print("{:.3f}, {:.3f}, {:.3f}, {:.3f}".format(testobject.get_times(i), testobject.get_x_positions(i), testobject.get_y_positions(i), testobject.get_z_positions(i)))

    print("\nTimes and x, y, z velocities")
    for i in range(0, testobject.len_x_velocities()):
        print("{:.3f}, {:.3f}, {:.3f}, {:.3f}".format(testobject.get_times(i), testobject.get_x_velocities(i), testobject.get_y_velocities(i), testobject.get_z_velocities(i)))

    print("\nTimes and x, y, z accelerations")
    for i in range(0, testobject.len_x_accelerations()):
        print("{:.3f}, {:.3f}, {:.3f}, {:.3f}".format(testobject.get_halftimes(i), testobject.get_x_accelerations(i), testobject.get_y_accelerations(i), testobject.get_z_accelerations(i)))

        




     


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

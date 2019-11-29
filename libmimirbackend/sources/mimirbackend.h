// mimirbackend.h
// Cale Overstreet 11/27/2019
// Interface for mimir backend. Interface itself uses "C" to externalize C++ functions to be used by Python Ctypes.

#pragma once

#include <iostream>

class trajectorymodel {
	public:
		void identify() {
			printf("This object is a trajectorymodel object\n");
		}
}

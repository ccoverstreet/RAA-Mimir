# RAA-Mimir

___
# Building RAA-Mimir and libmimirbackend
## Major Dependencies
- Python 3.7 (should work with any Python3 version, but was built with python 3.7.4).
- PyQt5
    - Install using the route recommended for your platform.
- See Windows section for build environment setup. This can be a pain to troubleshoot, so hopefully the directions help. I will make a longer post (StackOverflow or Github) addressing how I fixed build issues on Windows and using the library with ctypes.
## Linux

My preferred development and build platform. Everything just works.

## Windows

This was a pain in the *** to set up correctly due to the nature of C/C++ build systems on windows and issues with Python ctypes finding DLLs utilized by the library. The first issue I encountered was that the build system I was using was creating a 32-bit library, which is incompatible with a 64-bit python. Once I fixed that, the second issue was that Python Ctypes was unable to find the DLLs required by libmimirbackend.so (I'm currently using the Linux naming convention, but will correct for each platform in the future). After about 3 days of troubleshooting, I found that adding the `static` flag to the final compilation of libmimirbackend eliminates any issues at the cost of increasing the library size. The library is still fairly small (11 mb) and should not cause problems for end users.

The setup I currently have is Cygwin with the devel options for the 64 bit gcc/g++ installed. The make system used is the one included in the installation options for Cygwin.

To build and run test driver:
1. Navigate to root of project and run `make`
    - Should build succesfully. libmimirbackend.so is linked static using the `-static` flag, since building on Windows and importing the library through Python resulted in the linked DLLs not being found. Unfortunately this does create a larger executable size.
2. Now that 

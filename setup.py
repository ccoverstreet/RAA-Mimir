import os
from cx_Freeze import setup, Executable
import sys
import matplotlib

base = None

setup(
    name = "TEST",
    version = "1.0",
    description = "Building",
    executables = [Executable("driver.py")],
    options = {"build_exe": {
        "includes": [],
        "include_files": [("libmimirbackend/libmimirbackend.so", "libc/libmimirbackend/libmimirbackend.so")],
        "packages": ["mimirpywrapper", "tkinter", "tkinter.filedialog", "matplotlib"]
    }}
)

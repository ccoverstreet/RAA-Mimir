all: libmimirbackend.so
	echo "Ready to run"

libmimirbackend.so: 
	cd libmimirbackend && make -f makefile

LIBFLAGS = -shared

ifeq ($(OS), Windows_NT)
	LIBFLAGS += -static
endif


libmimirbackend.so: objects/mimirbackend.o
	g++ $(LIBFLAGS) -o libmimirbackend.so objects/mimirbackend.o

objects/mimirinterface.o: sources/mimirinterface.cpp sources/mimirbackend.h
	g++ -fPIC -o objects/mimirinterface.o -c sources/mimirinterface.cpp

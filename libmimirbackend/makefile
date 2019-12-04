LIBFLAGS = -shared

ifeq ($(OS), Windows_NT)
	LIBFLAGS += -static
endif


libmimirbackend.so: objects/mimirbackend.o
	g++ $(LIBFLAGS) -o libmimirbackend.so objects/mimirbackend.o

objects/mimirbackend.o: sources/mimirbackend.cpp sources/mimirbackend.h
	g++ -fPIC -o objects/mimirbackend.o -c sources/mimirbackend.cpp

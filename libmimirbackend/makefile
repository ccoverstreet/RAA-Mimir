LIBFLAGS = -shared

object_dir=objects

ifeq ($(OS), Windows_NT)
	LIBFLAGS += -static
endif


libmimirbackend.so: objects/mimirinterface.o
	g++ $(LIBFLAGS) -o libmimirbackend.so objects/mimirinterface.o

objects/mimirinterface.o: sources/mimirinterface.cpp sources/mimirbackend.h 
	[ -d $(object_dir) ] || mkdir -p $(object_dir)
	g++ -fPIC -o objects/mimirinterface.o -c sources/mimirinterface.cpp


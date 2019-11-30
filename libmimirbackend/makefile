libmimirbackend.so: objects/mimirbackend.o
	g++ -shared -o libmimirbackend.so objects/mimirbackend.o

objects/mimirbackend.o: sources/mimirbackend.cpp sources/mimirbackend.h
	g++ -fPIC -o objects/mimirbackend.o -c sources/mimirbackend.cpp

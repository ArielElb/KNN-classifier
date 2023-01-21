CXX = g++
CPPFLAGS = -I ../
CXXFLAGS = -std=c++11

OBJ = \
	  FileIO.o \
	  SocketIO.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

FileIO.o: FileIO.h

FileIO.h: DefaultIO.h

SocketIO.o: SocketIO.h

SocketIO.h: DefaultIO.h

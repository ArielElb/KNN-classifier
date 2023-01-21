CXX = g++
CPPFLAGS = -I ../
CXXFLAGS = -std=c++11

OBJ = \
	  Comparator.o \
	  Database.o \
	  Server.o \
	  Vector.o \
	  client.o \
	  server.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

Client.o: Client.h

Client.h: ../IO/SocketIO.h Vector.h ../ClientCLI/ClientCLI.h

Command.o: Command.h

Command.h: ../IO/DefaultIO.h Database.h ../IO/FileIO.h

Comparator.o: Comparator.h

Comparator.h: Vector.h

Database.o: Database.h

Database.h: Vector.h ../Distances/CHB.h ../Distances/AUC.h \
	../Distances/MIN.h ../Distances/MAN.h ../Distances/CAN.h \
	Comparator.h

Server.o: Server.h

Server.h: Database.h Vector.h ../ServerCLI/ServerCLI.h \
	../IO/DefaultIO.h ../IO/SocketIO.h

Vector.o: Vector.h

client.o: Client.h

server.o: Server.h ../ServerCLI/ConnectionHandler.h

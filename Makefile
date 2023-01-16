
make: testServer.o testClient.o SocketIO.o
	g++ -std=c++11 -o server.out testServer.o SocketIO.o
	g++ -std=c++11 -o client.out testClient.o SocketIO.o

# just create an object file
testServer.o : testServer.cpp
	g++ -std=c++11 -c testServer.cpp

testClient.o : testClient.cpp
	g++ -std=c++11 -c testClient.cpp

# compile into object file
SocketIO.o: SocketIO.cpp
	g++ -std=c++11 -c SocketIO.cpp

#delete all the object files
clean:
	rm *.o server.out client.out

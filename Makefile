
make: server.o client.o Vector.o Database.o AUC.o CHB.o CHB.o CAN.o MIN.o MAN.o Comparator.o
	g++ -std=c++11 -o server.out server.o Vector.o Database.o AUC.o CHB.o MAN.o MIN.o CAN.o Comparator.o
	g++ -std=c++11 -o client.out client.o Vector.o 

# just create an object file
server.o : server.cpp
	g++ -std=c++11 -c server.cpp

client.o : client.cpp
	g++ -std=c++11 -c client.cpp

# compile into object file
Vector.o: Vector.cpp
	g++ -std=c++11 -c Vector.cpp
Database.o: Database.cpp
	g++ -std=c++11 -c Database.cpp
CHB.o: Distances/CHB.cpp
	g++ -std=c++11 -c CHB.cpp
CAN.o: Distances/CAN.cpp
	g++ -std=c++11 -c CAN.cpp
MAN.o: Distances/MAN.cpp
	g++ -std=c++11 -c MAN.cpp
MIN.o: Distances/MIN.cpp
	g++ -std=c++11 -c MIN.cpp
AUC.o: Distances/AUC.cpp
	g++ -std=c++11 -c AUC.cpp
Comparator.o: Comparator.cpp
	g++ -std=c++11 -c Comparator.cpp

#delete all the object files
clean:
	rm *.o server.out client.out

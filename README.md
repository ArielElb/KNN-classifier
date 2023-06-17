# Knn classifier

## In this repo
- ClientCLI : directory containing client files
- Distances: directory containing distance files 
- General : directory containing files required by both client and server programs
- ServerCLI : directory dontaining server files

### Building
```bash
$make
```

###  Running
#### Server
```bash
$ ./server.out <file_name_classified> <port_number>
```
#### Client
```bash 
$ ./client.out <ipv_4> <port_number>
```
#### Expected input (client)
User inputs number corresponding to options in the menu. '-1' closes socket and terminates program

### Cleaning
```bash
$make clean
```

## Project Walkthrough

###  Distance class - functor
This class defines virtual functions which every distance must implement. Each distance is implemented as an object, which gives us the ability to switch distance functions at runtime for database functionality. This is an object-oriented solution to calculating the distance between database vectors and the input vector. Rather than passing a distance function (distance code from user input), we pass an object that contains the relevant distance method. Each class (AUC, CAN, CHB, MAN, MIN) holds its unique implementation in the () operator which allows us to write simpler, more elegant code. and we hold a map<string,Distances> when the key is the distance function name and the value is a functor object as mentioned above keeping it cleaner instead of using a lot of if/elif conditions.
### Database class
Processes the user-chosen CSV files and turns them into a database, which is internally implemented as a vector. Every line from the csv file is parsed by commas and each component converted to a double. The class supports processing both classified an unclassified vectors. (For vector length issues, see 'Misc'). 
### Vector class
Same as assignment 1
### Comparator class - functor
Compares two vectors based on their distFromArg member variable. Comparator object is passed to the sorting function in the K-nearest algorithm in Database. This is an object-oriented solution to passing a reference to a static function, which we would normally do when trying to implement a custom comparator. The Comparator function gives us the ability to pass a reference to an initialized object rather than a static function.
### DefaultIO
SocketIO and FileIO inherit this abstract class and implement its virtual methods write() and read(). This wraps the unsightly socket and file handling in a class and makes sockets and files easy to write to and read from.
### ClientCLI
This class wraps the client functionality. It runs the main menu and executes commands based on user input.
The client is based on the implementation seen in the lecture presentation. Client prompts user option, sends the data to the server and exectures the commmand. Once it receives a response from the server, the client will print it to the console if appropriate or perform some additional logic (depending on the server message). When the client receives '-1' from the user, it disconnects from the server. All communication uses the TCP protocol.
### Server
Multithreaded server can handle multiple clients at once. Opens a ServerCLI for each client on a new thread
### ServerCLI
The server is based on the implementation seen in the lecture presentation. Reads user choice and executes approppriate command. All communication uses the TCP protocol.

## Misc
- Program recognizes valid numerical input, such as integers, decimal numbers, and scientific notation. Any invalid input in one of the vectors, whether read from a file or received as input from the user at runtime, will cause the program to read another vector.
- Classification of the vector must be a non-numerical string. If the user attempts to classify a vector with a number, the program will interpret it as vector of length n+1 (i.e. if given vector of length 4 with a numerical classification, it will read an unclassified vector of length 5).
- Database must contain vectors of the same length. Program will not run if all vectors in the database don't match the length of the first.
- Database must contain at least 1 vector. An empty database will cause the program to exit.
- 1 <= k <= size of database. Failure to meet this requirement will cause the program to exit.
- if k is a decimal number e.g 2.2 , it will consider as k = 2.
- If there is a tie for majority classification of the nearest neighbors, (i.e. k = 3, and the 3 closest vectors have different lengths) the program will take the first maximum it comes across in the Map structure.

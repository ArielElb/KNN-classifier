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

### Used the command design pattern
![image](https://github.com/ArielElb/KNN-classifier/assets/94087682/4fec53e7-f208-4fd4-9521-8d3338c97e6a)

	
In this assignment our server can handle many client in parallelism using threads.<br>
When a new client exceutes the program the server sent him this text: <br>

![alt text](https://github.com/TopazAvraham/IntroductionToCS-University-C-programming/blob/master/Screenshots/205.png?raw=true)


#### Option 1- Upload CSV 
If the user pressed this option he will be given the option to enter a path to a local CSV file in this computer and after
pressing enter, our client code will send the content of that file to the server. This file that will contain the classified vectors. After sending the file, the server will send to the client "upload complete". If the path is not legal we will print in the user's terminal "invalid input".

This process will be done twice, the first one for the classified vectors and the second one for the vectors the needs to be classified.  
After the 2 files are uploaded we will show the user the main menu again.

![alt text](https://github.com/TopazAvraham/IntroductionToCS-University-C-programming/blob/master/Screenshots/204.png?raw=true)


#### Option 2- Algorithm Settings
If the user pressed this option he will be given the option to change the K number of neighbors the algorithm will use, or to change the distance metric the algorithms will be basing its calculations.

First we will show the user the cureent KNN parameters - the K and the distance metric and afterwards he will be given the oppurtunity to change the settings, if he wishes to do so.

If the user will enter wrong parameters for K or for the metric distance, then the server will send him an error indicating that there is an "invalid input for K" or "invalid input for metric" accordingly.

![alt text](https://github.com/TopazAvraham/IntroductionToCS-University-C-programming/blob/master/Screenshots/203.png?raw=true)


#### Option 3- Classify Data
If the user pressed this option the server will start the KNN algorithm calculation based on the files uploaded and the current settings of the algorithm.
If the user hasn't uploaded any files, or uploaded only the training file or the test file, the server will send an error to the client, saying he should upload the data.


#### Option 4- Display Results
If the user pressed this option the server will send the client the KNN algorithm calculation results based on the files uploaded and the current settings of the algorithm.

If the user hasn't uploaded any files, or uploaded only the training file or the test file, the server will send an error to the client, saying he should upload the data.

Also, if the user hasn't classified the data, meaning he didn't pressed option 3- classify data before, so the server will send him an error indicating that he needs to classify the data.

![alt text](https://github.com/TopazAvraham/IntroductionToCS-University-C-programming/blob/master/Screenshots/202.png?raw=true)


#### Option 5- Download Results
If the user pressed this option he will be given the option to enter a path in his computer in which the program will create a CSV file in that path with the results of the classification inside the file.

If the path is not correct we will show the user an error messege.

If the user hasn't uploaded any files, or uploaded only the training file or the test file, the server will send an error to the client, saying he should upload the data.

Also, if the user hasn't classified the data, meaning he didn't pressed option 3- classify data before, so the server will send him an error indicating that he needs to classify the data.


#### Option 8- Exit
If the user pressed this option we will exit the program, right after releasing all resources as sockets and thread that are beign used.




The excecution is straight forward: we run the client and server code in different terminals. The client asks to connect to the server and the server host assigns him a designated socket and a designated thread. Then, in the client code, we are reading the input from the user, and send it to the server<br><br>
In the server code we calculate the result based on the classes we implemented from previous assignments, using OOP principles.<br><br>
We implemented a distance class where each metric is a different method, and We implemented a Knn class to calculate distance of the given vector from the vectors in the file, to updating the distances accordingly, to bubble sort the vectors from the file based on the distance we just calculated. Then we use a method which calculates from the given K number from the client, what was the most frequent name and returns it, as the Knn algorithm result.
It does that for all the unclassified vectors in the that the client sent.
If needed, the server sends the result to the client using the designated client_socket and thread that was created for him.
<br><br>

## Misc
- Program recognizes valid numerical input, such as integers, decimal numbers, and scientific notation. Any invalid input in one of the vectors, whether read from a file or received as input from the user at runtime, will cause the program to read another vector.
- Classification of the vector must be a non-numerical string. If the user attempts to classify a vector with a number, the program will interpret it as vector of length n+1 (i.e. if given vector of length 4 with a numerical classification, it will read an unclassified vector of length 5).
- Database must contain vectors of the same length. Program will not run if all vectors in the database don't match the length of the first.
- Database must contain at least 1 vector. An empty database will cause the program to exit.
- 1 <= k <= size of database. Failure to meet this requirement will cause the program to exit.
- if k is a decimal number e.g 2.2 , it will consider as k = 2.
- If there is a tie for majority classification of the nearest neighbors, (i.e. k = 3, and the 3 closest vectors have different lengths) the program will take the first maximum it comes across in the Map structure.

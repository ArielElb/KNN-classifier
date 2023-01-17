cmake_minimum_required(VERSION 3.17)
project(ass4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ass4 serverMain.cpp ServerCLI/ConnectionHandler.cpp ServerCLI/ConnectionHandler.h
        Distances/AUC.cpp
        Distances/AUC.h
        Distances/CAN.cpp
        Distances/CAN.h
        Distances/CHB.cpp
        Distances/CHB.h
        Command.h
        Comparator.cpp
        Comparator.h
        Database.cpp
        Database.h
        Distances/Distances.h
        Distances/MAN.cpp
        Distances/MAN.h
        Distances/MIN.cpp
        Distances/MIN.h
        server.cpp
        Server.h
        Vector.cpp
        Vector.h
        IO/DefaultIO.h
        IO/SocketIO.h IO/SocketIO.cpp ServerCLI/ServerCLI.cpp ServerCLI/DisplayCommand.cpp ServerCLI/UploadCommand.cpp
        ServerCLI/SettingsCommand.cpp ServerCLI/ClassifyCommand.cpp ServerCLI/DownloadCommand.cpp
        ServerCLI/ClassifyCommand.cpp ClientCLI/DownloadFile.cpp ClientCLI/UploadFile.h)


add_executable(client clientMain.cpp  client.cpp Client.h IO/DefaultIO.h IO/SocketIO.h IO/SocketIO.cpp
        ClientCLI/ClientCLI.cpp ClientCLI/ClientCLI.h  IO/FileCSVIO.h  Vector.cpp Vector.h ClientCLI/DisplayClassiffications.cpp
 ClientCLI/DownloadFile.cpp ClientCLI/DownloadFile.h IO/FileCSVIO.cpp IO/FileCSVIO.h ClientCLI/UploadFile.cpp ClientCLI/UploadFile.h)
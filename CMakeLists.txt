cmake_minimum_required(VERSION 3.17)
project(ass4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ass4
        src/serverMain.cpp
        src/ServerCLI/ConnectionHandler.cpp
        src/ServerCLI/ConnectionHandler.h
        src/Distances/AUC.cpp
        src/Distances/AUC.h
        src/Distances/CAN.cpp
        src/Distances/CAN.h
        src/Distances/CHB.cpp
        src/Distances/CHB.h
        src/General/Command.h
        src/General/Comparator.cpp
        src/General/Comparator.h
        src/General/Database.cpp
        src/General/Database.h
        src/Distances/Distances.h
        src/Distances/MAN.cpp
        src/Distances/MAN.h
        src/Distances/MIN.cpp
        src/Distances/MIN.h
        src/General/server.cpp
        src/General/Server.h
        src/General/Vector.cpp
        src/General/Vector.h
        src/ServerCLI/util.h
        src/ServerCLI/util.cpp
        src/IO/DefaultIO.h
        src/IO/SocketIO.h
        src/IO/SocketIO.cpp
        src/ServerCLI/ServerCLI.cpp
        src/ServerCLI/DisplayCommand.cpp
        src/ServerCLI/UploadCommand.cpp
        src/ServerCLI/SettingsCommand.cpp
        src/ServerCLI/ClassifyCommand.cpp
        src/ServerCLI/DownloadCommand.cpp
        src/ServerCLI/ClassifyCommand.cpp
        src/ClientCLI/DownloadFile.cpp
        src/ClientCLI/UploadFile.h
        src/ClientCLI/ClassificationKnn.cpp)


add_executable(client
        src/clientMain.cpp
        src/General/client.cpp
        src/General/Client.h
        src/IO/DefaultIO.h
        src/IO/SocketIO.h
        src/IO/SocketIO.cpp
        src/ClientCLI/Downloader.h
        src/ClientCLI/Downloader.cpp
        src/ClientCLI/ClientCLI.cpp
        src/ClientCLI/ClientCLI.h
        src/IO/FileIO.h
        src/General/Vector.cpp
        src/General/Vector.h
        src/ClientCLI/DisplayClassiffications.cpp
        src/ClientCLI/DownloadFile.cpp
        src/ClientCLI/DownloadFile.h
        src/IO/FileIO.cpp
        src/IO/FileIO.h
        src/ClientCLI/UploadFile.cpp
        src/ClientCLI/UploadFile.h
        src/ClientCLI/ClassificationKnn.cpp
        src/ClientCLI/ClassificationKnn.h
        src/ClientCLI/ClassificationKnn.h
        src/ClientCLI/AlgorithmSettings.h
        src/ClientCLI/AlgorithmSettings.cpp )


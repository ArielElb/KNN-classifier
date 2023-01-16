cmake_minimum_required(VERSION 3.17)
project(ass4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ass4 serverMain.cpp server.cpp
        Server.h Distances ServerCLI IO
        Command.h
        Comparator.cpp
        Comparator.h
        Database.cpp
        Database.h
        Vector.cpp
        Vector.h)


add_executable(client client.cpp IO ClientCLI)
cmake_minimum_required(VERSION 3.17)
project(ass4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ass4  Distances
        ServerCLI IO
        Command.h
        Comparator.cpp
        Comparator.h
        Vector.cpp
        Vector.h ConnectionHandler.cpp serverMain.cpp server.cpp   Server.h)


add_executable(client  clientMain.cpp client.cpp  Client.h  IO ClientCLI )
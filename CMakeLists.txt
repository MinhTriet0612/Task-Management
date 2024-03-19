cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        model/Task.cpp
        model/Task.h
        model/User.cpp
        model/User.h
        service/TaskService.cpp
        service/TaskService.h
)

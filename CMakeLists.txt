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
        util/Util.cpp
        util/Util.h
)

# configure how to connect to the mysql

find_package(PkgConfig REQUIRED)
pkg_check_modules(MYSQL REQUIRED mysqlclient)

include_directories(${MYSQL_INCLUDE_DIRS})
target_link_libraries(untitled ${MYSQL_LIBRARIES})

#config that don't have error : undefind refenrece to sql::mysql::get_driver_instance()
target_link_libraries(untitled mysqlcppconn)

#config that don't have error : undefined reference to `sql::mysql::get_driver_instance()'

#target_link_libraries(untitled mysqlcppconn8)

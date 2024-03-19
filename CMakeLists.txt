cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled src/main.cpp
        src/model/Task.cpp
        src/model/Task.h
        src/model/User.cpp
        src/model/User.h
        src/service/TaskService.cpp
        src/service/TaskService.h
        src/util/Util.cpp
        src/util/Util.h
        src/service/UserService.cpp
        src/service/UserService.h
        src/repository/UserRepository.cpp
        src/repository/UserRepository.h
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

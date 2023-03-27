cmake_minimum_required(VERSION 3.5)

project(Puplisher VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(Boost 1.40 REQUIRED)

add_executable(${PROJECT_NAME}
        main.cpp
        Point.cpp
        Point.h
        Vector
        Types
)

#target_link_libraries(${PROJECT_NAME} PRIVATE Boost::boost)

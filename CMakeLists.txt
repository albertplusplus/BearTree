cmake_minimum_required(VERSION 3.10)
project(RBTreeProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory
include_directories(include)

# Add the executable
add_executable(rbtree src/main.cpp)

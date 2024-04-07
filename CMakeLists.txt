cmake_minimum_required(VERSION 3.27)
project(Server)

set(CMAKE_CXX_STANDARD 17)

add_executable(main src/main.cpp)

# Include project directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Include the directories for the Inja library
include_directories(${PROJECT_SOURCE_DIR}/extern)

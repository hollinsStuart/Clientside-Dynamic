cmake_minimum_required(VERSION 3.27)

project(Cpp_Server
        VERSION 0.0.1
        #        PROJECT_DESCRIPTION "A simple C++ server"
        #        PROJECT_HOMEPAGE_URL "https://github.com/hollinsStuart/Clientside-Dynamic"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

file(GLOB ROUTES "src/routes/*.cpp")

add_executable(main src/main.cpp ${ROUTES})

# Check if the compiler is GCC or Clang
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wconversion -Werror -O3)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # Equivalent options for MSVC
    add_compile_options(/W4 /O2)
endif ()

include_directories(${BOOST_PATH})
set(BOOST_ROOT "/opt/homebrew/Cellar/boost/1.84.0_1")
set(Boost_INCLUDE_DIR "/opt/homebrew/Cellar/boost/1.84.0_1/include")
set(Boost_LIBRARY_DIR "/opt/homebrew/Cellar/boost/1.84.0_1/lib")
find_package(Boost 1.66.0 REQUIRED COMPONENTS system thread PATHS ${BOOST_ROOT} NO_DEFAULT_PATH)

find_package(OpenSSL REQUIRED)

# link main with sqlite3
find_package(SQLite3 REQUIRED)
target_link_libraries(main SQLite::SQLite3)

# Include project directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Include external libraries
include_directories(${PROJECT_SOURCE_DIR}/extern)
include_directories(${PROJECT_SOURCE_DIR}/extern/crow)

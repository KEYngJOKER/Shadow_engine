cmake_minimum_required(VERSION 3.10)
project(shadow-engine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(shadow-engine
    src/main.cpp
)

find_package(Threads REQUIRED)
target_link_libraries(shadow-engine PRIVATE Threads::Threads)
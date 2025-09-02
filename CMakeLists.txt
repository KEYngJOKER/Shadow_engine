cmake_minimum_required(VERSION 3.10)
project(shiny-spoon VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(shiny-spoon
    src/main.cpp
)

find_package(Threads REQUIRED)
target_link_libraries(shiny-spoon PRIVATE Threads::Threads)
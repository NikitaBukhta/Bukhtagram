#--------------------------- MAIN CONFIGURATION ---------------------------#

cmake_minimum_required(VERSION 3.6.0)
set(PROJECT_NAME messager_client)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

file(GLOB_RECURSE CPP_SOURCES "*.cpp")
list(FILTER CPP_SOURCES EXCLUDE REGEX "build/.*")

add_executable(
    ${PROJECT_NAME}
    ${CPP_SOURCES}
)
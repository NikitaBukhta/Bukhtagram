cmake_minimum_required(VERSION 3.6.0)
set(PROJECT_NAME client-server-messenger)
project(${PROJECT_NAME})

add_subdirectory(Logger)
add_subdirectory(Messenger-Common)
add_subdirectory(Messenger-Client)
add_subdirectory(Messenger-Server)
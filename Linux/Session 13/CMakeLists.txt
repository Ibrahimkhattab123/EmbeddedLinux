cmake_minimum_required(VERSION 3.12)
project(MyApp)


set(CMAKE_CXX_STANDARD 11)


add_subdirectory(myLib)


add_executable(myapp main.cpp)
target_link_libraries(myapp mylib)

target_include_directories(myapp PRIVATE mylib)
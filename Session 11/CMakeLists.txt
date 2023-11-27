cmake_minimum_required(VERSION 3.21)

project(
    ControlPC
    VERSION 0.1
    DESCRIPTION "Control laptop remotely using a mobile application."
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  # Optionally set things like CMAKE_CXX_STANDARD,
  # CMAKE_POSITION_INDEPENDENT_CODE here

  # Let's ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDE's
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
  
endif()

#include_directories(include)

add_subdirectory(src)


#set(SOURCE_FILES
#    controlPC.cpp
#)

add_executable(main controlPC.cpp)


target_link_libraries(main PRIVATE controlPC_lib)


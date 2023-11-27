
add_library(controlPC_lib client_handler.cpp server.cpp)




# Include the "include" directory for header files

target_include_directories(controlPC_lib PUBLIC ../)


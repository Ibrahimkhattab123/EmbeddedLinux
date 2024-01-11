add_library(mylib SHARED mylib.cpp mylib.hpp)

set_target_properties(mylib PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../build)

target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

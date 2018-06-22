cmake_minimum_required(VERSION 3.5.1)

include_directories(${CMAKE_SOURCE_DIR}/include/data-structures-cpp)

add_library(fraction SHARED fraction.cpp)
# set_target_properties(
#     fraction 
#     PROPERTIES 
#     PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/include/fraction.h
#     LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(complex SHARED complex.cpp)

install(TARGETS fraction complex
LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR})
cmake_minimum_required(VERSION 3.5.1)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(fraction SHARED fraction.cpp)
set_target_properties(
    fraction 
    PROPERTIES 
    PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/include/fraction.h
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

install(TARGETS fraction
LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
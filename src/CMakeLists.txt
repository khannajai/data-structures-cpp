cmake_minimum_required(VERSION 3.5.1)

include_directories(${CMAKE_SOURCE_DIR}/include/data-structures-cpp)

set(LIB_LIST fraction complex)

foreach(LIB ${LIB_LIST})
    add_library(${LIB} SHARED "${LIB}.cpp")
    set(PRIVATE_LIBS "${PRIVATE_LIBS} -l${LIB}")
endforeach()

# add_library(fraction SHARED fraction.cpp)
# add_library(complex SHARED complex.cpp)

install(TARGETS ${LIB_LIST}
LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR})
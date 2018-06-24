cmake_minimum_required(VERSION 3.5.1)

foreach(LIB ${LIB_LIST})
    add_library(${LIB} SHARED "${LIB}.cpp")
    #set(PRIVATE_LIBS "${PRIVATE_LIBS} -l${LIB}")
endforeach()

install(TARGETS ${LIB_LIST}
LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR})
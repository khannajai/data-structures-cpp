cmake_minimum_required(VERSION 3.5.1)
project(data-structures-cpp DESCRIPTION "elementary data structures" VERSION 1.0.1)

#compiler
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")

include(GNUInstallDirs)

#including directories for headers and libraries
set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include/data-structures-cpp)
set(PROJECT_LIB ${CMAKE_SOURCE_DIR}/lib)
set(EXTERNAL_INCLUDE ${CMAKE_BINARY_DIR}/external/${CMAKE_INSTALL_INCLUDEDIR})
set(EXTERNAL_LIB ${CMAKE_BINARY_DIR}/external/${CMAKE_INSTALL_LIBDIR})
include_directories(${PROJECT_INCLUDE})


#generate .pc file and install it
set(LIB_LIST fraction complex)
foreach(LIB ${LIB_LIST})
    set(PRIVATE_LIBS "${PRIVATE_LIBS} -l${LIB}")
endforeach()
configure_file(cmake/data-structures-cpp.pc.in ${CMAKE_BINARY_DIR}/data-structures-cpp.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/data-structures-cpp.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)

#install headers
install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/data-structures-cpp
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h*")

# uninstall target
if(NOT TARGET uninstall)
configure_file(
    "${CMAKE_SOURCE_DIR}/cmake/uninstall.cmake.in"
    "${CMAKE_BINARY_DIR}/uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/uninstall.cmake)
set_target_properties(uninstall PROPERTIES EXCLUDE_FROM_ALL TRUE)
endif()





enable_testing()

#add subdirectories
add_subdirectory(src)
add_subdirectory(test)
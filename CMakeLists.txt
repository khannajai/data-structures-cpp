cmake_minimum_required(VERSION 3.5.1)
project(data-structures-cpp DESCRIPTION "elementary data structures" VERSION 1.0.1)

enable_testing()

#compiler
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")

include(GNUInstallDirs)

#add subdirectories
add_subdirectory(src)
add_subdirectory(test)

configure_file(cmake/data-structures-cpp.pc.in ${CMAKE_BINARY_DIR}/data-structures-cpp.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/data-structures-cpp.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
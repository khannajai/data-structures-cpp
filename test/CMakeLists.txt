cmake_minimum_required(VERSION 3.5.1)


enable_testing()

include(ExternalProject)
ExternalProject_Add(googletest
    PREFIX "${CMAKE_BINARY_DIR}/lib"
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG "master"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/lib/installed
)
# Prevent build on all targets build
set_target_properties(googletest PROPERTIES EXCLUDE_FROM_ALL TRUE)

# Specify where third-party libraries are located
link_directories(${CMAKE_BINARY_DIR}/lib/installed/${CMAKE_INSTALL_LIBDIR})
include_directories(${CMAKE_BINARY_DIR}/lib/installed/${CMAKE_INSTALL_INCLUDEDIR})

# This is required for googletest
find_package(Threads REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(test-all test-fraction.cpp)
target_link_libraries(test-all fraction gtest Threads::Threads)
# Make sure third-party is built before executable
add_dependencies(test-all googletest)
set_target_properties(test-all PROPERTIES EXCLUDE_FROM_ALL TRUE)

add_test(testFraction test-all)
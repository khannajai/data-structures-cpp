cmake_minimum_required(VERSION 3.5.1)

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

include_directories(${CMAKE_SOURCE_DIR}/include/data-structures-cpp)

add_executable(test-fraction test-fraction.cpp)
target_link_libraries(test-fraction fraction gtest Threads::Threads)
add_dependencies(test-fraction googletest)
#set_target_properties(test-fraction PROPERTIES EXCLUDE_FROM_ALL TRUE)
add_test(testFraction test-fraction)

add_executable(test-complex test-complex.cpp)
target_link_libraries(test-complex complex gtest Threads::Threads)
add_dependencies(test-complex googletest)
#set_target_properties(test-complex PROPERTIES EXCLUDE_FROM_ALL TRUE)
add_test(testComplex test-complex)

add_executable(test-stack test-stack.cpp)
target_link_libraries(test-stack gtest Threads::Threads)
add_dependencies(test-stack googletest)
#set_target_properties(test-stack PROPERTIES EXCLUDE_FROM_ALL TRUE)
add_test(testStack test-stack)

add_executable(test-dlist test-dlist.cpp)
target_link_libraries(test-dlist gtest Threads::Threads)
add_dependencies(test-dlist googletest)
#set_target_properties(test-dlist PROPERTIES EXCLUDE_FROM_ALL TRUE)
add_test(testDlist test-dlist)
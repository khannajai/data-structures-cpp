cmake_minimum_required(VERSION 3.5.1)

include(ExternalProject)
ExternalProject_Add(googletest
    PREFIX "${CMAKE_BINARY_DIR}/external/"
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG "master"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/external
)
# Prevent build on all targets build
set_target_properties(googletest PROPERTIES EXCLUDE_FROM_ALL TRUE)

include_directories(${EXTERNAL_INCLUDE})
link_directories(${EXTERNAL_LIB})

# This is required for googletest
find_package(Threads REQUIRED)

#generating tests for libraries and headers only
set(TEST_LIBS fraction complex)
set(TEST_HEADERS stack dlist)

foreach(LIB ${TEST_LIBS})
    add_executable("test-${LIB}" "test-${LIB}.cpp")
    target_link_libraries("test-${LIB}" "${LIB}" gtest Threads::Threads)
    add_dependencies("test-${LIB}" googletest)
    add_test("test-${LIB}" "test-${LIB}")
endforeach()

foreach(HEADER ${TEST_HEADERS})
    add_executable("test-${HEADER}" "test-${HEADER}.cpp")
    target_link_libraries("test-${HEADER}" gtest Threads::Threads)
    add_dependencies("test-${HEADER}" googletest)
    add_test("test-${HEADER}" "test-${HEADER}")
endforeach()
cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME_STR cmake-bootstrap)
project(${PROJECT_NAME_STR} C CXX)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost REQUIRED)

include_directories(../../include ${Boost_INCLUDE_DIR})

find_package(Threads REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=gnu++11 -Wall -Weffc++ -Wno-deprecated -pthread)
endif()

if(MSVC)
    set(MSVC_COMPILER_DEFS "-D_CRT_SECURE_NO_DEPRECATE -D_SCL_SECURE_NO_WARNINGS -D_VARIADIC_MAX=10")
    add_definitions(${MSVC_COMPILER_DEFS})
    add_definitions(/MP)
endif()

set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)
set(LIB_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/lib)
set(BIN_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/bin)
set(TEST_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/test)

add_subdirectory(${EXT_PROJECTS_DIR}/gtest)
add_subdirectory(${LIB_PROJECTS_DIR}/hello)
add_subdirectory(${BIN_PROJECTS_DIR}/greet)
add_subdirectory(${TEST_PROJECTS_DIR}/hello-test)

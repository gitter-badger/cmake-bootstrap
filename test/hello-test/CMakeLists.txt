enable_testing()
set(PROJECT_TEST_NAME hello-test)
include_directories(SYSTEM ${GTEST_INCLUDE_DIRS})

file(GLOB TEST_SRC_FILES src/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
add_dependencies(${PROJECT_TEST_NAME} googletest)

# Test project's libraries (NOTE, that the order is important)
set(PROJECT_TEST_LIBS
    # Project libraries
    hello
    # Google Test libraries
    ${GTEST_LIBS}
    # System libs
    ${CMAKE_THREAD_LIBS_INIT}
    )

target_link_libraries(${PROJECT_TEST_NAME} ${PROJECT_TEST_LIBS})

add_test(${PROJECT_TEST_NAME} ${PROJECT_TEST_NAME})

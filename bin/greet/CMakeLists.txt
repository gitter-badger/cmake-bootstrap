set(BINARY_NAME greet)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB BINARY_SRC_FILES src/*.cpp)

add_executable(${BINARY_NAME} ${BINARY_SRC_FILES})

# Test project's libraries (NOTE, that the order is important)
set(BINARY_LINK_LIBS
    # Project libs
    hello
    # Boost libs
    boost_system
    boost_program_options
    # System libs
    ${CMAKE_THREAD_LIBS_INIT}
    )

target_link_libraries(${BINARY_NAME} ${BINARY_LINK_LIBS})

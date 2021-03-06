cmake_minimum_required(VERSION 2.8)
project(Executors)

set(BINARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}" CACHE PATH "")
set(CMAKE_INSTALL_PREFIX "${OUTPUT_DIR}" CACHE PATH "") 

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(extern/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${EXECUTOR_INCLUDE_DIR})
enable_testing()
macro(add_executor_test _TEST_NAME)
    add_executable(${_TEST_NAME}_tests
            test/${_TEST_NAME}_test.cpp)
    target_link_libraries(${_TEST_NAME}_tests
            gtest_main ${EXECUTOR_LIB} ${CMAKE_THREAD_LIBS_INIT})
    add_test(NAME ${_TEST_NAME}_tests COMMAND ${_TEST_NAME}_tests)
    set_property(TARGET ${_TEST_NAME}_tests PROPERTY FOLDER "tests")
endmacro()

add_executor_test(thread_per_task_executor)
add_executor_test(thread_pool_executor)


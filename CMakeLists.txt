cmake_minimum_required(VERSION 3.1)
project(futureexecutors)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCE_FILES main.cpp src/executor.h src/executor_helper.h src/limited_thread_per_task_executor.h src/local_queue_thread_pool_executor.h src/loop_executor.h src/randomized_thread_pool_executor.h src/serial_executor.h src/system_executor.h src/thread_per_task_executor.h src/thread_per_task_executor_test.h)

add_library(futureexecutors SHARED ${SOURCE_FILES})


enable_testing()
add_executable(foo test/thread_pool_executor_test.cpp)
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
find_package(Threads REQUIRED)
target_link_libraries(foo gtest gtest_main futureexecutors ${CMAKE_THREAD_LIBS_INIT})
add_test(test1 foo)


add_executable(threat_per_task_executor_test test/thread_per_task_executor_test.cpp)
target_link_libraries(threat_per_task_executor_test gtest gtest_main futureexecutors ${CMAKE_THREAD_LIBS_INIT})
add_test(threat_per_task_executor_test threat_per_task_executor_test)

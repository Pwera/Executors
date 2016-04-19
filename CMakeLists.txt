cmake_minimum_required(VERSION 3.1)
project(futureexecutors)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp executor.h executor_helper.h limited_thread_per_task_executor.h local_queue_thread_pool_executor.h loop_executor.h randomized_thread_pool_executor.h serial_executor.h system_executor.h thread_per_task_executor.h thread_pool_executor.h)
add_executable(futureexecutors ${SOURCE_FILES})
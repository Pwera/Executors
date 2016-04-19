cmake_minimum_required(VERSION 3.1)
project(futureexecutors)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp src/executor.h src/executor_helper.h src/limited_thread_per_task_executor.h src/local_queue_thread_pool_executor.h src/loop_executor.h src/randomized_thread_pool_executor.h src/serial_executor.h src/system_executor.h src/thread_per_task_executor.h src/thread_pool_executor.h)
add_executable(futureexecutors ${SOURCE_FILES})
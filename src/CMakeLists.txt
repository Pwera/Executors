set(EXECUTOR_LIB "futureexecutors" CACHE FORCE "")
set(EXECUTOR_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" CACHE FORCE "")
project(${EXECUTOR_LIB} CXX)

set(SOURCE_FILES executor.h  futureexecutors.cpp executor_helper.h  limited_thread_per_task_executor.h  local_queue_thread_pool_executor.h  loop_executor.h  randomized_thread_pool_executor.h  serial_executor.h  system_executor.h  thread_per_task_executor.h  thread_per_task_executor_test.h)
add_library(${EXECUTOR_LIB} SHARED ${SOURCE_FILES})

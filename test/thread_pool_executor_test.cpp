#include "../headers.h"
#include <atomic>
#include <functional>
#include <future>
#include <set>
#include <thread>
#include <utility>
#include <vector>
#include <thread>
#include <chrono>
#include <gtest/gtest.h>


class ThreadPoolExecutor : public ::testing::Test {
public:
    thread_pool_executor executor;

    ThreadPoolExecutor() : executor(2) {}

protected:

    virtual void SetUp() {

    }

    virtual void TearDown() {

    }
};


class WorkToDo {
public:
    void operator()() {
        std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
    }
};

class TimeWastedWork {
public:
    void operator()() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "### Hello from thread " << std::this_thread::get_id() << std::endl;
    }
};

class YetAnotherTimeWastedWork {
public:
    void operator()() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "::: Hello from thread " << std::this_thread::get_id() << std::endl;
    }
};

TEST_F(ThreadPoolExecutor, ThreadPoolExecutorLambda) {
    auto anotherLambda2 = []() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "### Hello from thread " << std::this_thread::get_id() << std::endl;
    };

    executor.spawn(std::move(anotherLambda2));
}

TEST_F(ThreadPoolExecutor, ThreadPoolExecutorFunctor) {
    executor.spawn(std::move(TimeWastedWork()));
    executor.spawn(std::move(YetAnotherTimeWastedWork()));
}



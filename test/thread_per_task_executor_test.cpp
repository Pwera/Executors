#include <headers.h>
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


class ThreadPerTaskExecutorFixture : public ::testing::Test {
public:
    thread_per_task_executor &exector;

    ThreadPerTaskExecutorFixture() : exector(thread_per_task_executor::get_executor()) {}

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

TEST_F(ThreadPerTaskExecutorFixture, ThreadPerTaskExecutorLambda) {

    exector.spawn([]() {
        std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
    });
    auto anotherLambda = []() { std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl; };
    exector.spawn(anotherLambda);

}
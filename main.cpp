#include "headers.h"
#include <atomic>
#include <functional>
#include <future>
#include <set>
#include <thread>
#include <utility>
#include <vector>
#include <thread>
#include <chrono>
#Commit
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

int main() {
    /*              thread_per_task_executor                */
    thread_per_task_executor &exector = thread_per_task_executor::get_executor();
    exector.spawn(std::move(WorkToDo()));
    exector.spawn([]() {
        std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
    });
    auto anotherLambda = []() { std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl; };
    exector.spawn(anotherLambda);

    /*              thread_pool_executor                */

    thread_pool_executor executor2(2);
    auto anotherLambda2 = []() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "### Hello from thread " << std::this_thread::get_id() << std::endl;
    };
    executor2.spawn(std::move(TimeWastedWork()));
    executor2.spawn(std::move(anotherLambda2));
    executor2.spawn(std::move(TimeWastedWork()));
    executor2.spawn(std::move(anotherLambda2));
    executor2.spawn(std::move(TimeWastedWork()));
    executor2.spawn(std::move(anotherLambda2));
    //just for terminal clearance
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    /*              system_executor           */
    system_executor &system_executor = system_executor::get_executor();
    system_executor.spawn(std::move(YetAnotherTimeWastedWork()));
    system_executor.spawn(std::move(YetAnotherTimeWastedWork()));
    system_executor.spawn(std::move(YetAnotherTimeWastedWork()));
    system_executor.spawn(std::move(YetAnotherTimeWastedWork()));
    system_executor.spawn(std::move(YetAnotherTimeWastedWork()));

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return 0;

}



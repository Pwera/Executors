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
int main(){
    //just for terminal clearance
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    //              system_executor           
    system_executor &system_executor = system_executor::get_executor();
//    system_executor.spawn(std::move(YetAnotherTimeWastedWork()));
//    system_executor.spawn(std::move(YetAnotherTimeWastedWork()));
//    system_executor.spawn(std::move(YetAnotherTimeWastedWork()));
//    system_executor.spawn(std::move(YetAnotherTimeWastedWork()));
//    system_executor.spawn(std::move(YetAnotherTimeWastedWork()));

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return 0;

}



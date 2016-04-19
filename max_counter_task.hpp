#ifndef FUTUREEXECUTORS_MAX_COUNTER_TASK_HPP
#define FUTUREEXECUTORS_MAX_COUNTER_TASK_HPP
#include "headers.h"
using namespace std;
class max_counter_task{
private:
    mutex mut;
    condition_variable cv;
    int concurrency;
    int max_concurrency;
    int release_count;
    int start_count;
    set<thread::id> threads;
public:
    max_counter_task(int task_num): concurrency(0), max_concurrency(0), release_count(0), start_count(0) {
    }
    void operator()(){
        unique_lock<mutex> count_lock(mut);
        threads.insert(this_thread::get_id());
        concurrency++;
        if(concurrency > max_concurrency)
            max_concurrency = concurrency;
        if(!release_internal()){

        }
        count_lock.unlock();
    }
    void release(){
        unique_lock<mutex> count_lock(mut);
        release_internal();
    }
    void release_internal(){}

};
#endif //FUTUREEXECUTORS_MAX_COUNTER_TASK_HPP

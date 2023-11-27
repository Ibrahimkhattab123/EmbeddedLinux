#include <algorithm>
#include <exception>
#include <functional>
#include <future>
#include <iostream>
#include <list>
#include <mutex>
#include <stdexcept>
#include <thread>

// Due to the race condition while accessing the
// shared data between two asynchronous running
// threads.

// So, it’s important to use a locking mechanism to
// protect the data from the corruption.

// The mutex class is a synchronization
// primitive that can be used to protect shared
// data from being simultaneously accessed by
// multiple threads.

std::list<int> data;
std::mutex mtx;

void operate(int count){
    std::cout << "Operate thread Start." << std::endl;
    for (int i = 0; i < count ; i++){
        if (i % 10 == 0){
            std::cout << i << " ";
        }
        // mtx.lock();
        //     data.push_back(i);
        // mtx.unlock();
        // or
        // The class lock_guard is a mutex
        // wrapper that provides a convenient
        // RAII-style mechanism for owning a
        // mutex for the duration of a scoped
        // block.
        std::lock_guard<std::mutex> l_mtx(mtx);
        data.push_back(i);
        
    }
    std::cout << std::endl;
}

int main(){
    std::future<void> fu1 = std::async(std::launch::async, operate, 1000);
    std::future<void> fu2= std::async(std::launch::async, operate, 1000);

    fu1.wait();
    fu2.wait();

    std::cout << "Count is: " << data.size() << std::endl;

    return 0;

}

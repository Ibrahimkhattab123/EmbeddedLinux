#include <algorithm>
#include <functional>
#include <future>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

// Future and Promise are used for the
// synchronization and sharing data between
// Concurrent threads running in the same program.

// In other word, std::promise refers to the guarantee
// or commitment made by the object to provide a
// value or an exception at some point in the future.

int sum(std::promise<int> &p_count){
    int count, sum = 0;
    std::cout << "Sum thread started." << std::endl;

    std::future<int> fu = p_count.get_future();
    std::cout << "Sum thread is unblocked and will continue to operate." << std::endl;

    count = fu.get();
    for (int i = 0; i < count; i++) {
        std::cout << i << " ";
        sum += i;
    }
    std::cout << std::endl << "sum is: " << sum << std::endl;
    return sum;
}

int main(){
    std::promise<int> data;
    // std::ref() is a function template provided
    // by the C++ Standard Library that is used
    // to create a reference wrapper. It is
    // primarily used to pass references as
    // arguments to functions or algorithms
    // that expect objects by value.
    std::future<int> fu = std::async(sum, std::ref(data));
    std::this_thread::sleep_for(3s);
    data.set_value(10);
    int sum = fu.get();
    std::cout << "Sum is = " << sum << std::endl;
    return 0; 
}
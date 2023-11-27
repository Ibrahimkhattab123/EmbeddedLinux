#include <algorithm>
#include <future>
#include <iostream>
#include <thread>

int sum(int count){
    int sum = 0;
    for (int i = 0; i < count; i++) {
        std::cout << i << " ";
        sum += i;
    }
    std::cout << std::endl << "sum is: " << sum << std::endl;
    return sum;
}

int main(){
    // template std::packaged_task wraps any Callable target (function, lambda expression, bind expression, or another function object) 
    // so that it can be invoked asynchronously.
    // Its return value or exception thrown is stored in a shared state which can be accessed through std::future objects.
    std::packaged_task<int(int)> pck_t(sum);
    // or std::packaged_task<int()> pck_t(std::bind(sum, 10));

    // std::future provides a mechanism to access the result of asynchronous operations.
    // If you don't capture or store the std::future
    // returned by std::async and don't call any
    // member function on it, the std::future object will
    // be destroyed immediately and will be blocked
    // as it’s happened if one of three actions ,get(),
    // wait() or destructor of object
    std::future<int> fu = pck_t.get_future();
    std::thread th(std::move(pck_t), 10);
    // when seconed way: std::thread th(std::move(pck_t));
    std::cout << "Begin of thread" << std::endl;
    int returned = fu.get();

    std::cout << "sum is returned: " << returned  << std::endl;

    if (th.joinable()){
        th.join();
    }
    return 0;
}
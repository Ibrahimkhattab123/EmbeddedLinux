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
    
    // std::future<int> fu = std::async(sum, 10);
    // It starts asynchronously once the thread is created.
    // std::future<int> fu = std::async(std::launch::async, sum, 10);
    // It starts synchronously upon request through future::get.
    std::future<int> fu = std::async(std::launch::deferred, sum, 10);


    std::cout << "Begin of thread" << std::endl;
    int returned = fu.get();

    std::cout << "sum is returned: " << returned  << std::endl;

    return 0;
}
#include <algorithm>
#include <future>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

int sum(int count){
    int sum = 0;
    for (int i = 0; i < count; i++) {
        // Blocks the execution of the current
        // thread for at least the specified
        // sleep_duration.
        std::this_thread::sleep_for(500ms);
        std::cout << i << " ";
        sum += i;
    }
    std::cout << std::endl << "sum is: " << sum << std::endl;
    return sum;
}

int main(){
    std::future fu = std::async(sum, 10);
    // Blocks until the result becomes available. 
    fu.wait();
}
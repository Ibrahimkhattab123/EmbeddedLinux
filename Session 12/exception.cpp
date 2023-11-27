#include <algorithm>
#include <exception>
#include <functional>
#include <future>
#include <iostream>
#include <stdexcept>
#include <thread>

using namespace std::chrono_literals;

// Along side of sharing data between
// threads std::promise also provides the
// option of propagating exceptions that
// thrones in parent thread to be caught by
// the other thread catch.

int sum(std::promise<int> &p_count){
    int count, sum = 0;
    try
    {
        std::cout << "Sum thread started." << std::endl;

    std::future<int> fu = p_count.get_future();
    count = fu.get();
    std::cout << "Sum thread is unblocked and will continue to operate." << std::endl;

    for (int i = 0; i < count; i++) {
        std::cout << i << " ";
        sum += i;
    }
    std::cout << std::endl << "sum is: " << sum << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << "Exception came from main ...> " << ex.what() << std::endl;
    }
    return sum;
    
}

int main(){
    std::promise<int> data;
    std::future<int> fu = std::async(sum, std::ref(data));
    std::this_thread::sleep_for(3s);
    try {
        // data.set_value(10);
        throw std::runtime_error{"Data not available"};
        int sum = fu.get();
        std::cout << "Sum is = " << sum << std::endl;
    } catch (std::exception& ex) {
        data.set_exception(std::make_exception_ptr(ex));
    }

    return 0;
}
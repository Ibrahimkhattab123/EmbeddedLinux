// create a function to find the maximum number of array
#include "include_file.hpp"

constexpr std::size_t arrSize = 5;

// Return type is lvalue of T ref  
template<typename T, std::size_t SIZE>
T& maximumNumberInArray(std::array<T, SIZE> arr) {

    // std::mac:alement returns  an iterator to the max element in given range (Pointer)
    // max is lvalue ref = rvalue --> valid 
    auto&  max = *std::max_element(arr.begin(), arr.end());
    // returns lvalue ref
    return max;
}

int main (){
    std::array<int, arrSize> arr{112, 2,46,8,12};

    auto max = maximumNumberInArray(arr);
    std::cout << "max number of given array:  " << max << std::endl;

    return 0;
}
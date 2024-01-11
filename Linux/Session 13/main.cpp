#include "mylib.hpp"
#include <iostream>
#include <vector>

int main() {
    MyLib mylib;

    // Example vector to accumulate
    std::vector<int> values = {1, 2, 3, 4, 5};

    // Accumulate vector using MyLib
    mylib.accumulateVector(values);

    // Get the sum and display it
    std::cout << "Sum of the vector elements: " << mylib.getSum() << std::endl;

    return 0;
}
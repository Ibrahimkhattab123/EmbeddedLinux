// find the even and odd numbers in the array

#include "include_file.hpp"


constexpr std::size_t arrSize = 5;

template <typename T, size_t N>
void separateEvenOdd(const std::array<T, N>& arr, std::array<T, N>& even, std::array<T, N>& odd, size_t& evenSize, size_t& oddSize) {
    auto isEven = [](const T& num) { return num % 2 == 0; };

    // use partition_copy to seprate the numbers into two array
    // return tepe --> std::pair<_OutputIterator1, _OutputIterator2>
    // n A pair designating the ends of the resulting sequences. Copies each element in the range @p [__first,__last) for which
    auto partitionPoint = std::partition_copy(arr.begin(), arr.end(), even.begin(), odd.begin(), isEven);

    // To calculte the size of the new arrays, which are sent back using the ref param 
    evenSize = std::distance(even.begin(), partitionPoint.first);
    oddSize = std::distance(odd.begin(), partitionPoint.second);
}

int main() {
    std::array<int, arrSize> arr2{11,22,33,44,55};
    std::array<int, arrSize> evenNumbers;
    std::array<int, arrSize> oddNumbers;
    size_t evenSize = 0;
    size_t oddSize = 0;

    separateEvenOdd(arr2, evenNumbers, oddNumbers, evenSize, oddSize);

   
    // normal for loops, and not ranged, becuase ranged will print out 5 elements and not the calculated elements
    std::cout << "Even numbers:";
    for (auto element: evenNumbers) {
        std::cout << " " << element;
    }
    std::cout << std::endl;

    std::cout << "Odd numbers:";
    for (size_t i = 0; i < oddSize; ++i) {
        std::cout << " " << oddNumbers[i];
    }
    std::cout << std::endl;

    return 0;
}

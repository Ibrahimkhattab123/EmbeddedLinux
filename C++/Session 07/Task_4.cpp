// merge two arrays together

#include "include_file.hpp"
#include <array>

constexpr std::size_t arrSize = 5;

template <typename T, std::size_t SIZE>
std::array<T, 2 * SIZE> mergeTwoArrays(std::array<T, SIZE> arr1,
                                       std::array<T, SIZE> arr2) {
  std::array<T, 2 * SIZE> merged;
  std::merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(),
             merged.begin());
  return merged;
}

int main() {
  std::array<int, arrSize> arr1{12, 2, 46, 8, 12};
  std::array<int, arrSize> arr2{11, 22, 33, 44, 55};

  constexpr std::size_t newRange = 2 * arrSize;
  std::array<int, newRange> arrMerged = mergeTwoArrays(arr1, arr2);

  std::cout << "Merged array:";
  for (auto element : arrMerged) {
    std::cout << " " << element;
  }
  std::cout << std::endl;
}
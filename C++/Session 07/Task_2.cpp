// create a function to search to the number in the array which number is taken

#include "include_file.hpp"
#include <algorithm>
#include <array>
#include <cstddef>

constexpr std::size_t arrSize = 5;

template <typename T, std::size_t SIZE>
bool searchGivenNumInArray(std::array<T, SIZE> arr, T givenNum) {

  auto number = std::find_if(
      arr.begin(),
      arr.end(), [givenNum](T num) -> auto{ return num == givenNum; });
  return number != arr.end();
}

int main() {

  std::array<int, arrSize> arr{112, 2, 46, 8, 12};

  int givenNum;
  std::cout << "Enter a number to search for: ";
  std::cin >> givenNum;

  if (searchGivenNumInArray(arr, givenNum)) {
    std::cout << givenNum << " was found in the array" << std::endl;
  } else {
    std::cout << givenNum << " was not found in the array" << std::endl;
  }

  return 0;
}
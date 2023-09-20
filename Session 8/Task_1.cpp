// Check if character is digit
// Check if all the array is even
// check if there is any value ofarray is even

#include "include_file.hpp"

constexpr std::size_t arrSize = 5;

void printIsTrue(bool value) {
  if (value) {
    std::cout << "arr is even" << std::endl;
  } else {
    std::cout << "arr is not even" << std::endl;
  }
}
int main() {
  // subtask 1
  auto checkDigit = [](char a) {
    if (isdigit(a)) {
      std::cout << "char " << a << " is digit" << std::endl;
    } else {
      std::cout << "char " << a << " is  not digit" << std::endl;
    }
  };
  char a = 'q';
  checkDigit(a);
  checkDigit(std::move('5'));

  // subtask 2
  auto checkEvenArray = [&](int a) {
    if (a % 2 == 0) {
      return true;
    } else
      return false;
  };

  std::array<int, arrSize> arr1{11, 22, 33, 44, 55};
  auto isEven = std::all_of(arr1.begin(), arr1.end(),
                            [](const int &num) { return num % 2 == 0; });
  printIsTrue(isEven);
  std::array<int, arrSize> arr2{22, 44, 66, 88, 100};
  auto isEven1 = std::all_of(arr2.begin(), arr2.end(),
                             [](const int &num) { return num % 2 == 0; });
  printIsTrue(isEven1);

  auto isAnyVlaueEven = std::all_of(
      arr1.begin(), arr1.end(), [](const int &num) { return num % 2 == 0; });
  printIsTrue(isAnyVlaueEven);
  auto isAnyVlaueEven2 = std::all_of(
      arr2.begin(), arr2.end(), [](const int &num) { return num % 2 == 0; });
  printIsTrue(isAnyVlaueEven2);
}
#include <iostream>

int main() {
  int height;

  std::cout << "Enter the height of the right-angle triangle: ";
  std::cin >> height;

  for (int i = 1; i <= height; ++i) {
    for (int j = 1; j <= height - i; ++j) {
      std::cout << " ";
    }

    for (int k = 1; k <= 1; ++k) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }
  return 0;
}
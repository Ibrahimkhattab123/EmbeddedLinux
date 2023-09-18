#include <bitset>
#include <iostream>
#include <sstream>

bool isBinary(const std::string &input) {
  for (char c : input) {
    if (c != '0' && c != '1') {
      return false;
    }
  }
  return true;
}

int main() {
  std::string input;

  std::cout << "Enter a number : ";
  std::cin >> input;

  if (isBinary(input)) {
    std::bitset<32> binary(input);
    int decimalNumber = static_cast<int>(binary.to_ulong());
    std::cout << "Decimal representation: " << decimalNumber << std::endl;
  } else {
    int decimalNumber;
    std::istringstream(input) >> decimalNumber;
    std::bitset<32> binary(decimalNumber);
    std::cout << "Binary representation: " << binary << std::endl;
  }

  return 0;
}

// Create a string class
#include "Task_2.hpp"
#include <chrono>

namespace CustomizedString {
MyString::MyString() : str(nullptr), length(0) {}

MyString::MyString(const char *_str) : length(strlen(_str)) {
  this->str = std::shared_ptr<char>(new char[length + 1]);
  std::strcpy(str.get(), _str);
}

MyString::MyString(const MyString &second) : length(second.length) {
  str = std::shared_ptr<char>(new char[length + 1]);
  std::strcpy(str.get(), second.str.get());
}

MyString &MyString::operator=(const MyString &second) {
  if (this != &second) {
    this->length = second.length;
    this->str = std::shared_ptr<char>(new char[length + 1]);
    std::strcpy(str.get(), second.str.get());
  }
  return *this;
}

MyString::MyString(MyString &&second) noexcept
    : str(std::move(second.str)), length(second.length) {
  second.length = 0;
}

MyString &MyString::operator=(MyString &&second) noexcept {
  if (this != &second) {
    this->length = second.length;
    this->str = std::move(second.str);
    second.length = 0;
  }
  return *this;
}

MyString MyString::operator+(const MyString &second) const {

  size_t combinedLength = strlen(str.get()) + strlen(second.str.get());
  char *combinedData = new char[combinedLength + 1];
  strcpy(combinedData, str.get());
  strcat(combinedData, second.str.get());
  return MyString(combinedData);
}
MyString::~MyString() {}

const char *MyString::getString() const { return (str.get()); }
} // namespace CustomizedString

int main() {

  CustomizedString::MyString str1("Hello ");

  CustomizedString::MyString str2("World!");

  CustomizedString::MyString strAdd = str1 + str2;

  CustomizedString::MyString str3 = str1;

  CustomizedString::MyString str4;
  str4 = str2;

  // if you want to test this: comment the first 4 std::cout
  // The Length of str1 and str2 after move is 0,
  // CustomizedString::MyString str5 = std::move(str1);
  //
  // CustomizedString::MyString str6;
  // str6 = std::move(str2);

  std::cout << str1.getString() << std::endl;
  std::cout << str2.getString() << std::endl;
  std::cout << strAdd.getString() << std::endl;
  std::cout << str3.getString() << std::endl;
  std::cout << str4.getString() << std::endl;
  // std::cout << str5.getString() << std::endl;
  // std::cout << str6.getString() << std::endl;

  return 0;
}

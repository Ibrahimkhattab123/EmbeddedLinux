#pragma once

#include <cstring>
#include <iostream>
#include <memory>

namespace CustomizedString {
class MyString {
public:
  MyString();
  MyString(const char *_str);

  // Copy construtor
  MyString(const MyString &second);

  // copy assugnment
  MyString &operator=(const MyString &second);

  // move constructor
  MyString(MyString &&second) noexcept;

  // move assignment
  MyString &operator=(MyString &&second) noexcept;
  MyString operator+(const MyString &other) const;

  // destructor
  ~MyString();

  const char *getString() const;

private:
  std::size_t length;
  std::shared_ptr<char> str;
};
} // namespace CustomizedString

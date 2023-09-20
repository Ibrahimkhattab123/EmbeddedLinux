// handle programm
// fill Array from 10 to 10000
// use and / or
// calculate accumlate array
#include <algorithm>
#include <array>
#include <csignal>
#include <iostream>
#include <numeric>
#include <unistd.h>

bool keepRunning = true;
void signalHandler(int signal) {
  if (signal == SIGINT) {
    std::cout << "Temination signal received." << std::endl;
    keepRunning = false;
  }
}

template <size_t N> void fillArraySequentially(std::array<int, N> &arr) {
  int value = 10;
  for (size_t i = 0; i < N; ++i) {
    arr[i] = value;
    ++value;
  }
}

void CheckNumSign(int x, int y) {

  if (x > 0 and y > 0) {
    std::cout << "Both x and y are greater than 0." << std::endl;
  } else {
    std::cout << "At least one of x or y is not greater than 0." << std::endl;
  }

  if (x < 0 or y < 0) {
    std::cout << "At least one of x or y is less than 0." << std::endl;
  } else {
    std::cout << "Neither x nor y is less than 0." << std::endl;
  }
}
int main() {
  signal(SIGINT, signalHandler);
  const size_t size = 9991;
  std::array<int, size> myArray;

  fillArraySequentially(myArray);

  int x = 10;
  int y = 20;

  std::array<int, 5> arr = {1, 2, 3, 4, 5};
  while (keepRunning) {
    CheckNumSign(x, y);
    int sum = std::accumulate(arr.begin(), arr.end(), 0);
    std::cout << "accumlate array = " << sum << std::endl;
    for (auto elem : myArray) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
    sleep(1);
  }
}
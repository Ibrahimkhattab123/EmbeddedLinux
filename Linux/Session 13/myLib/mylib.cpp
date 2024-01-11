#include "mylib.hpp"

MyLib::MyLib(): sum(0) {}

void MyLib::accumulateVector(const std::vector<int>& values)
{
    for (int value : values) {
        sum += value;
    }
}

int MyLib::getSum() const
{
    return sum;
}


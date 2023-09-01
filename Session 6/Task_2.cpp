#include <iostream>
#include <set>

int main () {
    std::set<int> numbers;
    int num1, num2, num3;

    std::cout << "Enter three Numbers: ";
    std::cin >> num1 >> num2 >> num3;

    numbers.insert(num1);
    numbers.insert(num2);
    numbers.insert(num3);

    int maxNum = *(--numbers.end());
    
    std::cout << "The max value: " << maxNum << std::endl;
    return 0;
}
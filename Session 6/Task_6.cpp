#include <iostream>

int main (){
    int num, digit, sum = 0;

    std::cout << "Enter an integer: ";
    std::cin >> num;

    int originalNum = num;

    while (num != 0) {
        digit = num % 10;
        sum += digit;
        num /= 10;
    }

    std::cout <<"The sum of digits in " << originalNum << " is: " << sum << std::endl;

    return 0; 

}
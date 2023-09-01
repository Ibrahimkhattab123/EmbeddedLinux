#include <iostream>
#include <cctype>
#include <ostream>

int main() {
    char letter;

    std::cout << "Enter a letter: ";
    std::cin >> letter;

    letter = std::tolower(letter);

    if (std::isalpha(letter)) {
        if (letter == 'a' || letter == 'e' || letter == 'o' || letter == 'u' || letter == 'i'){
            std::cout << "The Letter" <<  letter << " is a vowel" << std::endl;
        } else {
            std::cout << "The Letter" <<  letter << "is not a vowel" << std::endl;
        }
    } else {
        std::cout << "Invalid input, Please enter a valid charcter" << std::endl;
    }

    return 0;
}
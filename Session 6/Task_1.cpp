#include <iostream>

int main() {
    std::cout << "ASCII Code\t ASCII Character\n";

    for (int i = 0; i< 128; ++i) {
        std::cout << static_cast<char>(i) << "\t\t" << i << "\n";
    }

    return 0;
}
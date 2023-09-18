// delete number in array

#include "include_file.hpp"
#include <algorithm>

constexpr std::size_t arrSize = 5;


template<typename T, std::size_t SIZE>
bool searchGivenNumInArray(std::array<T, SIZE> arr, T givenNum){

    auto number = std::find_if(arr.begin(),arr.end(), [givenNum](T num) -> auto{
        return num==givenNum;
    });
    return number!= arr.end();
}

template<typename T, std::size_t SIZE>
bool deleteGivenNumInArray(std::array<T, SIZE> arr, T givenNum){
    if (searchGivenNumInArray(arr, givenNum)){
        auto ToDeleteAtTheEnd = std::remove(arr.begin(),arr.end(), givenNum);
        return true;
    } else {
        return false;
    }

}

int main (){
    std::array<int, arrSize> arr{112, 2,46,8,12};

    int givenNum;
    std::cout << "Enter a number to search for: ";
    std::cin >> givenNum;

    if (deleteGivenNumInArray(arr, givenNum)) {
        std::cout << givenNum << " was found and deleted from the array" << std::endl;
    } else {
        std::cout << givenNum << " is not in the array" << std::endl;
    }


}
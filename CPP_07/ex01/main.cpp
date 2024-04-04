#include "iter.hpp"

int main() {
    //Test with an integer array
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Integer array: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    //Test with a double array
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "Double array: ";
    iter(doubleArray, 5, printElement<double>);
    std::cout << std::endl;

    //Test with a character array
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    std::cout << "Character array: ";
    iter(charArray, 5, printElement<char>);
    std::cout << std::endl;

    return 0;
}

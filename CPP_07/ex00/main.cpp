#include "whatever.hpp"


int main(){

    //Tests for max
    int intMax = max(5, 10);
    std::cout << "Maximum of 5 and 10 is: " << intMax << std::endl; 
    double doubleMax = max(3.14, 2.71);
    std::cout << "Maximum of 3.14 and 2.71 is: " << doubleMax << std::endl; 
    //Tests for min
    int intMin = min(5, 10);
    std::cout << "Minimum of 5 and 10 is: " << intMin << std::endl; 
    double doubleMin = min(3.14, 2.71);
    std::cout << "Minimum of 3.14 and 2.71 is: " << doubleMin << std::endl; 
    //Tests to prove the second parameter is returned on equality
    int* ptr1 = new int;
    if (ptr1 != nullptr) {
        *ptr1 = 42;
    } else {
        std::cout << "Memory allocation failed." << std::endl;
    }
    int* ptr2 = new int;
    if (ptr2 != nullptr) {
        *ptr2 = 42;
    } else {
        std::cout << "Memory allocation failed." << std::endl;
    }
    int* minPtr = min(ptr1, ptr2);
    std::cout << "Address of ptr1: " << ptr1 << std::endl;
    std::cout << "Address of ptr2: " << ptr2 << std::endl;
    std::cout << "Address of min pointer: " << minPtr << std::endl;

    //Tests for swap
    *ptr2 = 24;
    std::cout << "Before swap:" << std::endl;
    std::cout << "Value of ptr1: " << *ptr1 << std::endl;
    std::cout << "Value of ptr2: " << *ptr2 << std::endl;
    swap(ptr1, ptr2);
    std::cout << "After swap:" << std::endl;
    std::cout << "Value of ptr1: " << *ptr1 << std::endl;
    std::cout << "Value of ptr2: " << *ptr2 << std::endl;

    delete ptr1;
    delete ptr2;
    return 0;
}

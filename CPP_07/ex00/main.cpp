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

    // //tests from subject
    // int a = 2;
    // int b = 3;
    // ::swap( a, b );
    // std::cout << "a = " << a << ", b = " << b << std::endl;
    // std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    // std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    // std::string c = "chaine1";
    // std::string d = "chaine2";
    // ::swap(c, d);
    // std::cout << "c = " << c << ", d = " << d << std::endl;
    // std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    // std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return 0;
}

#include "Array.hpp"

int main() {
    try {
        Array<int> arr1;
        std::cout << "Size of arr1: " << arr1.size() << std::endl;

        Array<int> arr2(5);
        std::cout << "Size of arr2: " << arr2.size() << std::endl;

        Array<int> arr3 = arr2;
        Array<int> arr4;
        arr4 = arr3;

        arr4[2] = 100;
        std::cout << "Element at index 2 in arr3: " << arr3[2] << std::endl;
        std::cout << "Element at index 2 in arr4: " << arr4[2] << std::endl;

        std::cout << "Trying to access out-of-bounds index: ";
        std::cout << arr2[6] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

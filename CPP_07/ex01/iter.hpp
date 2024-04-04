#pragma once
#include <iostream>

template<typename T, typename Func>
void iter(T* array, size_t length, Func func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template<typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

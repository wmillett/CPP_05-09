#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found in container");
    }
    return it;
}

template<typename Container>
void testEasyFind(Container& container, int value) {
    try {
        typename Container::iterator it = easyfind(container, value);
        std::cout << "Value found at index: " << std::distance(container.begin(), it) << std::endl;
    } catch (std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

#endif
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    testEasyFind(vec, 3); 
    testEasyFind(vec, 6);

    return 0;
}

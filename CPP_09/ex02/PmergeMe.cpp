#include "PmergeMe.hpp"




merge::merge(){
}

merge::merge(const std::string input){
    
}

merge::merge(const merge& other){
    *this = other;
}

merge& merge::operator=(const merge& other){
    if (this != &other) {
        _vector = other._vector;
        _list = other._list;
    }
    return *this;
}
merge::~merge(){
}



void merge::calculate(void){





}

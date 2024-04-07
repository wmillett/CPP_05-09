#include "Span.hpp"

Span::Span(unsigned int N) : _maxCapacity(N) {}

Span::Span(const Span& other) : _numbersList(other._numbersList), _maxCapacity(other._maxCapacity) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _numbersList = other._numbersList;
        _maxCapacity = other._maxCapacity;
    }
    return *this;
}

Span::~Span() {
}

void Span::addNumber(int num) {
    if (_numbersList.size() >= _maxCapacity) {
        throw std::overflow_error("Span is full, cannot add more _numbersList.");
    }
    _numbersList.push_back(num);
}

// template void Span::add_numbersList<std::__1::__wrap_iter<int*> >(std::__1::__wrap_iter<int*>, std::__1::__wrap_iter<int*>);

int Span::shortestSpan() const {
    if (_numbersList.size() < 2) {
        throw std::runtime_error("Cannot find span with less than 2 _numbersList.");
    }
    std::vector<int> sorted_numbersList = _numbersList;
    std::sort(sorted_numbersList.begin(), sorted_numbersList.end());

    int shortest = sorted_numbersList[1] - sorted_numbersList[0];
    for (size_t i = 2; i < sorted_numbersList.size(); ++i) {
        int span = sorted_numbersList[i] - sorted_numbersList[i - 1];
        if (span < shortest) {
            shortest = span;
        }
    }
    return shortest;
}

// Method to find the longest span
int Span::longestSpan() const {
    if (_numbersList.size() < 2) {
        throw std::runtime_error("Cannot find span with less than 2 _numbersList.");
    }
    int min = *std::min_element(_numbersList.begin(), _numbersList.end());
    int max = *std::max_element(_numbersList.begin(), _numbersList.end());
    return max - min;
}

void Span::makeVector(int nb){
  int max = getMax() - this->_numbersList.size();
  for (int i = 0; i < max; i++) {
    addNumber(nb + i);
  }
}

 unsigned int Span::getMax() const{
    return _maxCapacity;
 }

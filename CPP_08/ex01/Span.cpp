#include "Span.hpp"

// Constructor implementation
Span::Span(unsigned int N) : max_capacity(N) {}

// Copy constructor implementation
Span::Span(const Span& other) : numbers(other.numbers), max_capacity(other.max_capacity) {}

// Copy assignment operator implementation
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        numbers = other.numbers;
        max_capacity = other.max_capacity;
    }
    return *this;
}

// Destructor implementation
Span::~Span() {
    // Any necessary cleanup can be performed here
}

// Method to add a single number to the Span
void Span::addNumber(int num) {
    if (numbers.size() >= max_capacity) {
        throw std::overflow_error("Span is full, cannot add more numbers.");
    }
    numbers.push_back(num);
}

// Explicit instantiation for std::__1::__wrap_iter<int*>
template void Span::addNumbers<std::__1::__wrap_iter<int*> >(std::__1::__wrap_iter<int*>, std::__1::__wrap_iter<int*>);

// Method to find the shortest span
int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::runtime_error("Cannot find span with less than 2 numbers.");
    }
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int shortest = sortedNumbers[1] - sortedNumbers[0];
    for (size_t i = 2; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < shortest) {
            shortest = span;
        }
    }
    return shortest;
}

// Method to find the longest span
int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::runtime_error("Cannot find span with less than 2 numbers.");
    }
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return max - min;
}

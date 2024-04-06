// #ifndef SPAN_HPP
// #define SPAN_HPP

// #include <vector>
// #include <stdexcept>
// #include <algorithm>

// class Span {
// private:
//     Span();
//     std::vector<int> numbers;
//     unsigned int max_capacity;

// public:
//     Span(unsigned int N);
//     Span(const Span& other);
//     Span& operator=(const Span& other);
//     ~Span();
//     void addNumber(int num);
//     void addNumbers(const std::vector<int>& nums);
//     template <typename InputIterator>
//     void addNumbers(InputIterator begin, InputIterator end);
//     int shortestSpan() const;
//     int longestSpan() const;
// };

// #endif
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
private:
    std::vector<int> numbers;
    unsigned int max_capacity;
    Span();
public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span(); // Destructor declaration
    void addNumber(int num);
    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end);
    int shortestSpan() const;
    int longestSpan() const;
};


// Definition of addNumbers function template
template <typename InputIterator>
void Span::addNumbers(InputIterator begin, InputIterator end) {
    while (begin != end) {
        addNumber(*begin);
        ++begin;
    }
}

#endif // SPAN_HPP

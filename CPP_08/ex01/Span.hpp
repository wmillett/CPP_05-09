// #ifndef SPAN_HPP
// #define SPAN_HPP

// #include <vector>
// #include <stdexcept>
// #include <algorithm>

// class Span {
// private:
//     Span();
//     std::vector<int> _numbersList;
//     unsigned int _maxCapacity;

// public:
//     Span(unsigned int N);
//     Span(const Span& other);
//     Span& operator=(const Span& other);
//     ~Span();
//     void addNumber(int num);
//     void add_numbersList(const std::vector<int>& nums);
//     template <typename InputIterator>
//     void add_numbersList(InputIterator begin, InputIterator end);
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
    std::vector<int> _numbersList;
    unsigned int _maxCapacity;
    Span();
public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    void addNumber(int num);
    void makeVector(int nb);
    // template <typename InputIterator>
    // void add_numbersList(InputIterator begin, InputIterator end);
    unsigned int getMax() const;
    int shortestSpan() const;
    int longestSpan() const;
};

// template <typename InputIterator>
// void Span::add_numbersList(InputIterator begin, InputIterator end) {
//     while (begin != end) {
//         addNumber(*begin);
//         ++begin;
//     }
// }

#endif

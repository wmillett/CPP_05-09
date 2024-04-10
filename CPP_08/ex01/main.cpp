
#include <iostream>
#include "Span.hpp"

int main() {
    try {
        Span sp = Span(10);

        //Test from subject
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        //Test with multiple numbers in same call
        std::cout << "Test with one call" << std::endl;
        Span spt = Span(10000);
        spt.makeVector(10000);
        std::cout << "size: " << spt.getNumbers().size() << std::endl;
        std::cout << "shortest: " << spt.shortestSpan() << std::endl;
        std::cout << "longest : " << spt.longestSpan() << std::endl;
    } catch (const std::overflow_error& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught unknown exception: " << e.what() << std::endl;
    }

    return 0;
}

// #include <iostream>
// #include "Span.hpp"

// int main() {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;

   
//     std::vector<int> moreNumbers;
//     moreNumbers.push_back(4);
//     moreNumbers.push_back(8);
//     moreNumbers.push_back(12);
//     moreNumbers.push_back(15);
//     sp.addNumbers(moreNumbers.begin(), moreNumbers.end());

//     try {
//         std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
//         std::cout << "Longest span: " << sp.longestSpan() << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }
//     return 0;
// }

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

        //Test with multiple numbers in same call
        std::vector<int> moreNumbers;
        moreNumbers.push_back(4);
        moreNumbers.push_back(8);
        moreNumbers.push_back(12);
        moreNumbers.push_back(15);
        sp.addNumbers(moreNumbers.begin(), moreNumbers.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::overflow_error& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught unknown exception: " << e.what() << std::endl;
    }

    return 0;
}

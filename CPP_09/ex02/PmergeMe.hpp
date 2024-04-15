#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

# include <vector>
# include <list>
# include <chrono>
# include <algorithm>
# include <ctime>
# include <iomanip>

class merge{
    private:
        std::vector<int>_vector;
        std::list<int>_list;

        void sort(std::vector<int>& A, int p, int r);
        void sortList(std::list<int>& A, int p, int r);
    public:
        merge();
        merge(const std::string input);
        merge(const merge& other);
        merge& operator=(const merge& other);
        ~merge();

        void calculate(std::vector<int>input, std::list<int>inputList);
};


#endif
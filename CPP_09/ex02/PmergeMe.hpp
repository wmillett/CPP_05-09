#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

# include <vector>
# include <list>


class merge{
    private:
        std::vector<int>_vector;
        std::list<int>_list;

    public:
        merge();
        merge(const std::string input);
        merge(const merge& other);
        merge& operator=(const merge& other);
        ~merge();

        void calculate(std::vector<int>input);
};


#endif
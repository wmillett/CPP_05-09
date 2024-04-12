#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>




class revPol{

    private:
        std::stack<int>_stack;
        std::string _line;
        std::string res;

    public:
        revPol();
        revPol(const std::string input);
        revPol(const revPol& other);
        revPol& operator=(const revPol& other);
        ~revPol();

        void calculate(void);



};


#endif
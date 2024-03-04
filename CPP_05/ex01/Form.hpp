#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Form{
    private:
        const std::string _name;
        const int _toSign;
        const int _toExec;
        bool _signed;
    public:
        Form();
        Form(const std::string name, const int toSign, const int toExec);
        Form(Form& other);
        Form& operator=(const Form& other);
        ~Form();

        class GradeTooLowException: public std::exception{
            public:
                virtual const char* what() const throw();
        };

        const std::string getName(void);
        const int getToSign(void);
        const int getToExec(void);
        bool getSigned(void);

        bool beSigned(const Bureaucrat& signer);

}; 

std::ostream& operator<<(std::ostream& os, const Form& other); 

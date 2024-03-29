#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string _name;
        const int _toSign;
        const int _toExec;
        bool _signed;
        // void beSigned(Bureaucrat*bureaucrat);
    public:
        Form();
        Form(const std::string name, const int toSign, const int toExec);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        
        void checkGrade(int toSign, int toExec);
        class GradeTooHighException: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException: public std::exception{
            public:
                virtual const char* what() const throw();
        };

        std::string getName(void) const;
        int getToSign(void) const;
        int getToExec(void) const;
        bool getSigned(void) const;
        bool beSigned(Bureaucrat* signer);

}; 

std::ostream& operator<<(std::ostream& os, const Form& other); 
#endif

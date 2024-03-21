#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        const std::string _name;
        const int _toSign;
        const int _toExec;
        bool _signed;
        // void beSigned(Bureaucrat*bureaucrat);
    public:
        AForm();
        AForm(const std::string name, const int toSign, const int toExec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        
        void checkGrade(int toSign, int toExec);
        class GradeTooHighException: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class HasNotBeenSigned: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        virtual bool execute(Bureaucrat const & executor) const = 0;
        
        std::string getName(void) const;
        int getToSign(void) const;
        int getToExec(void) const;
        bool getSigned(void) const;
        bool beSigned(Bureaucrat* signer);

}; 

std::ostream& operator<<(std::ostream& os, const AForm& other); 
#endif

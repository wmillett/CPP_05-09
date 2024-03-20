#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class Bureaucrat{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        
        class GradeTooHighException: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        


        const std::string getName(void) const;
        int getGrade(void) const;
        void signAForm(AForm *toSign);
        void checkGrade(int grade);
        void increaseGrade(unsigned int amount);
        void decreaseGrade(unsigned int amount);

        bool executeForm(AForm const & form);
}; 

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif
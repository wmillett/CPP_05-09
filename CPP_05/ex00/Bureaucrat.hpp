#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>



class Bureaucrat{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat& other);
        ~Bureaucrat();

        void operator<<(Bureaucrat& message);
        void increaseGrade();
        void decreaseGrade();
        const std::string getName();
        int getGrade();
};



#endif
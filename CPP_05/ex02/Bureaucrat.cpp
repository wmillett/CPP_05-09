#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): _name("No name"), _grade(150){
    std::cout << "Default bureaucrat constructor called" << std::endl;
};

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(150){
    std::cout << "Bureaucrat constructor called with name " << name << " and grade " << grade << " called" << std::endl;
    checkGrade(grade);
    _grade = grade;
};

Bureaucrat::Bureaucrat(Bureaucrat& other){
    std::cout << "Copy constructor bureaucrat called" << std::endl;
    *this = other;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if (this != &other)
        this->_grade = other._grade;
    std::cout << "Bureaucrat copy operator called" << std::endl;
    return *this;
};

Bureaucrat::~Bureaucrat(void){
    std::cout << "Bureaucrat destructor called" << std::endl;
};

int Bureaucrat::getGrade(void) const{
    return _grade;
};

const std::string Bureaucrat::getName(void) const{
    return _name;
};

void Bureaucrat::increaseGrade(unsigned int amount = 1){
    _grade -= amount;
    if (_grade < 1)
        throw(GradeTooHighException());
};

void Bureaucrat::decreaseGrade(unsigned int amount = 1){
    _grade += amount;
    if (_grade > 150)
        throw(GradeTooLowException());
};

void Bureaucrat::checkGrade(int grade){
    if (grade > 150)
        throw(GradeTooLowException());
    if (grade < 1)
        throw(GradeTooHighException());
};

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return("Grade too low");
};

const char* Bureaucrat::GradeTooHighException::what() const throw(){
     return("Grade too high");
};

void Bureaucrat::signAForm(AForm *a){
    if (a->getSigned()){
        std::cout << this->_name << " couldn't sign " << a->getName() << " because it was already signed." << std::endl;
        return ;
    }
    else
    {
        try{
            a->beSigned(this);
        }
        catch(std::exception & e){
            std::cout << this->_name << " couldn't sign " << a->getName() << " because their grade was too low." << std::endl;
            throw(GradeTooLowException());
        }
        std::cout << this->_name << " has signed the form " << a->getName() << " ." << std::endl;
    }
};

bool Bureaucrat::executeForm(AForm const & form){

    try{
    form.execute(*this);

    }
    catch(std::exception & e){
        std::cout << this->_name << " couldn't execute " << form.getName() << " because their grade was too low." << std::endl;
        return 0;
    }
    std::cout << this->_name << " executed " << form.getName() << std::endl;
    return 1;
};


std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade();
	return os;
};

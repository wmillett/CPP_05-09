#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target("Default"){
  std::cout << "RobotomyRequestForm default constructor called." << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45),_target(target){
    std::cout << "RobotomyRequestForm parameter constructor called." << std::endl;
};

RobotomyRequestForm::~RobotomyRequestForm(void){
    std::cout << "RobotomyRequestForm destructor called." << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other){
    std::cout << "Copy constructor RobotomyRequestForm called" << std::endl;
    *this = other;
};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    if (this != &other){
        this->_target = other._target;
    }
    return *this;
};

std::string RobotomyRequestForm::getTarget(void) const{
    return _target;
};

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const{

    if(executor.getGrade() > this->getToExec()){
        throw(GradeTooLowException());
    }
    else{
        std::cout << "* Drilling noises *" << std::endl;
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int randomNumber = std::rand() % 2;
        if(randomNumber)
            std::cout << _target << " has been robotomized." << std::endl;
        else
            std::cout << _target << " has failed to be robotomized." << std::endl;
        return 1;
    }
};
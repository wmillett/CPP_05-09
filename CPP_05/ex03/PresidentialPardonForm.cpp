#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("presidential pardon", 25, 5),_target("Default"){
  std::cout << "PresidentialPardonForm default constructor called." << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("presidential pardon", 25, 5),_target(target){
    std::cout << "PresidentialPardonForm parameter constructor called." << std::endl;
};

PresidentialPardonForm::~PresidentialPardonForm(void){
    std::cout << "PresidentialPardonForm destructor called." << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other){
    std::cout << "Copy constructor PresidentialPardonForm called" << std::endl;
    *this = other;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    if (this != &other){
        this->_target = other._target;
    }
    return *this;
};

std::string PresidentialPardonForm::getTarget(void) const{
    return _target;
};

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const{
    
    if(executor.getGrade() > this->getToExec()){
        throw(GradeTooLowException());
    }
    else{
        std::cout << _target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
        return 1;
    }
};

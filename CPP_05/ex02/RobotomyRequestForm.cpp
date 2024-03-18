#include "RobotomyCreationForm.hpp"



RobotomyCreationForm::RobotomyCreationForm(void): _target("Default"){
  std::cout << "RobotomyCreationForm default constructor called." << std::endl;
};


RobotomyCreationForm::RobotomyCreationForm(std::string target): _target(target){
    std::cout << "RobotomyCreationForm parameter constructor called." << std::endl;
};

RobotomyCreationForm::~RobotomyCreationForm(void){
    std::cout << "RobotomyCreationForm destructor called." << std::endl;
};

RobotomyCreationForm::RobotomyCreationForm(const RobotomyCreationForm& other){
    std::cout << "Copy constructor RobotomyCreationForm called" << std::endl;
    *this = other;
};

RobotomyCreationForm& RobotomyCreationForm::operator=(const RobotomyCreationForm& other){
    if (this != &other){
        this->_target = other._target;
    }
    return *this;
};


std::string RobotomyCreationForm::getTarget(void) const{
    return _target;
};

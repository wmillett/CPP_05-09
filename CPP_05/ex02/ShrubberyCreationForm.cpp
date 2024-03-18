#include "ShrubberyCreationForm.hpp"



ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), _target("Default"){
  std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
};


ShrubberyCreationForm::ShrubberyCreationForm(std::string target):  AForm("ShrubberyCreationForm", 145, 137), _target("Default"){
    std::cout << "ShrubberyCreationForm parameter constructor called." << std::endl;
};

ShrubberyCreationForm::~ShrubberyCreationForm(void){
    std::cout << "ShrubberyCreationForm destructor called." << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other){
    std::cout << "Copy constructor ShrubberyCreationForm called" << std::endl;
    *this = other;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    if (this != &other){
        this->_target = other._target;
    }
    return *this;
};

std::string ShrubberyCreationForm::getTarget(void) const{
    return _target;
};

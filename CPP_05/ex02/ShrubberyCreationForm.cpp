#include "ShrubberyCreationForm.hpp"



ShrubberyCreationForm::ShrubberyCreationForm(void): _target("Default"){
  std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
};


ShrubberyCreationForm::ShrubberyCreationForm(std::string target): _target(target){
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

#include "ShrubberyCreationForm.hpp"



ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), _target("Default"){
  std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
};


ShrubberyCreationForm::ShrubberyCreationForm(std::string target):  AForm("ShrubberyCreationForm", 145, 137), _target(target){
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

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
  
    if(executor.getGrade() > this->getToExec()){
        throw(GradeTooLowException());
    }
    else{
        std::ofstream outputFile;
    outputFile.open(_target + "_shrubbery");

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 0;//throw
    }
    outputFile << "     /\\\n"
              "    //\\\\\n"
              "   //  \\\\\n"
              "  //    \\\\\n"
              " //______\\\\\n"
              "     ||" << std::endl;

    outputFile.close();
    return 1;
    }
};
    //  else if(!this->getSigned()){
    //     throw(HasNotBeenSigned());
    //     // std::cout << "Form for " << _target << " has not been signed." << std::endl;
    //     // return 0;
    // }

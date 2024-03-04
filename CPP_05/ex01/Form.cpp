#include "Form.hpp"



Form::Form(): _name("No name"), _toSign(150), _toExec(150), _signed(0){
    std::cout << "Default Form constructor called" << std::endl;
};

Form::Form(const std::string name, const int toSign, const int toExec): _name(name), _toSign(toSign), _toExec(toExec), _signed(0){
     std::cout << "Form constructor called with parameters" << std::endl;
};

Form::Form(Form& other){
    std::cout << "Copy constructor Form called" << std::endl;
    *this->other;
};

Form& Form::operator=(const Form& other){
    if (this != &other){
        this->_signed = other._signed;
    }
    return *this;
};

Form::~Form(){
    std::cout << "Form destructor called" << std::endl;
};


const char* Form::GradeTooLowException::what() const throw(){
    return("Grade too low to sign/execute the form");
};

bool Form::beSigned(const Bureaucrat& signer){
    if (signer->getGrade > _signed){
        throw(GradeTooLowException());
        return 0;
    }
    _signed = 1;
    return 1;
};


std::ostream& operator<<(std::ostream& os, const Form& other)
{
	os << other.getName() << ", Format grade to sign: " << other.getToSign() << ", Format grade to execute: " << other.getToExec() << "Format is signed: " << other.getSigned() << std::endl;
	return os;
};
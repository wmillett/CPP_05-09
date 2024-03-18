
#include "Form.hpp"

Form::Form(): _name("No name"), _toSign(150), _toExec(150), _signed(0){
    std::cout << "Default Form constructor called" << std::endl;
};

Form::Form(const std::string name, const int toSign, const int toExec): _name(name), _toSign(toSign), _toExec(toExec), _signed(0){
     std::cout << "Form constructor called with parameters" << std::endl;
     checkGrade(_toSign, _toExec);
};

Form::Form(const Form& other): _toSign(other._toSign), _toExec(other._toExec){
    std::cout << "Copy constructor Form called" << std::endl;
    *this = other;
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

const char* Form::GradeTooHighException::what() const throw(){
    return("Grade too low to sign/execute the form");
};

const char* Form::GradeTooLowException::what() const throw(){
    return("Grade too low to sign/execute the form");
};

void Form::checkGrade(int toSign, int toExec){
    if (toSign > 150 || toExec > 150)
        throw(GradeTooLowException());
    if (toSign < 1 || toExec < 1)
        throw(GradeTooHighException());
};

bool Form::beSigned(Bureaucrat* signer){
    if (signer->getGrade() > _toSign){
        throw(GradeTooLowException());
    }
    _signed = 1;
    return 1;
};

std::string Form::getName(void) const{
    return this->_name;
};

int Form::getToSign(void) const{
    return _toSign;
};

int Form::getToExec(void) const{
    return _toExec;
};

bool Form::getSigned(void) const{
    return _signed;
};

std::ostream& operator<<(std::ostream& os, const Form& other)
{
	os << other.getName() << ", Format grade to sign: " << other.getToSign() << ", Format grade to execute: " << other.getToExec() << "Format is signed: " << other.getSigned() << std::endl;
	return os;
};

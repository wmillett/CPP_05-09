
#include "AForm.hpp"

AForm::AForm(): _name("No name"), _toSign(150), _toExec(150), _signed(0){
    std::cout << "Default AForm constructor called" << std::endl;
};

AForm::AForm(const std::string name, const int toSign, const int toExec): _name(name), _toSign(toSign), _toExec(toExec), _signed(0){
     std::cout << "AForm constructor called with parameters" << std::endl;
     checkGrade(_toSign, _toExec);
};

AForm::AForm(const AForm& other): _toSign(other._toSign), _toExec(other._toExec){
    std::cout << "Copy constructor AForm called" << std::endl;
    *this = other;
};

AForm& AForm::operator=(const AForm& other){
    if (this != &other){
        this->_signed = other._signed;
    }
    return *this;
};

AForm::~AForm(){
    std::cout << "AForm destructor called" << std::endl;
};

const char* AForm::GradeTooHighException::what() const throw(){
    return("Grade too low to sign/execute the AForm");
};

const char* AForm::GradeTooLowException::what() const throw(){
    return("Grade too low to sign/execute the AForm");
};

void AForm::checkGrade(int toSign, int toExec){
    if (toSign > 150 || toExec > 150)
        throw(GradeTooLowException());
    if (toSign < 1 || toExec < 1)
        throw(GradeTooHighException());
};

bool AForm::beSigned(Bureaucrat* signer){
    if (signer->getGrade() > _toSign){
        throw(GradeTooLowException());
    }
    _signed = 1;
    return 1;
};

std::string AForm::getName(void) const{
    return this->_name;
};

int AForm::getToSign(void) const{
    return _toSign;
};

int AForm::getToExec(void) const{
    return _toExec;
};

bool AForm::getSigned(void) const{
    return _signed;
};

std::ostream& operator<<(std::ostream& os, const AForm& other)
{
	os << other.getName() << ", AFormat grade to sign: " << other.getToSign() << ", AFormat grade to execute: " << other.getToExec() << "AFormat is signed: " << other.getSigned() << std::endl;
	return os;
};

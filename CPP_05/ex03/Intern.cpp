#include "Intern.hpp"
#include <vector>


Intern::Intern(){
    std::cout << "Default Intern constructor called" << std::endl;
};



Intern::Intern(const Intern& other){
    std::cout << "Copy constructor Intern called" << std::endl;
    *this = other;
};

Intern& Intern::operator=(const Intern& other){
    if (this != &other){
        *this = other;
    }
    return *this;
};

Intern::~Intern(){
    std::cout << "Intern destructor called" << std::endl;
};



AForm* Intern::makeForm(std::string name, std::string target){
    const std::string formNames[] = {"shrubbery creation", "presidential pardon", "robotomy request"};
    AForm* returnForm = nullptr;
    int findForm;
    // void (AForm::*listForms[3])(void) = {&ShrubberyCreationForm(target), &PresidentialPardonForm(target), &RobotomyRequestForm(target)};
    for(int i = 0; i < 3; i++){
        if(name == formNames[i])
            findForm = i;
    }
    switch(findForm){

        case 0:
            returnForm = new ShrubberyCreationForm(target);
            std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
            break;
        case 1:
            returnForm = new PresidentialPardonForm(target);
            std::cout << "Intern creates PresidentialPardonForm" << std::endl;
            break;
        case 2:
            returnForm = new RobotomyRequestForm(target);
            std::cout << "Intern creates RobotomyRequestForm" << std::endl;
            break;
        default:
            std::cout << "Error: empty name" << std::endl;
            break;
    }
    return returnForm;
};


// #include "Intern.hpp"
// #include <vector>

// AForm* Intern::makeForm(std::string name, std::string target) {
//     const std::vector<std::string> formList = FORMS;
//     AForm* returnForm = nullptr;



//     // Define a typedef for constructor functions
//     typedef AForm* (*FormConstructor)(std::string);

//     // Create an array of function pointers to constructors
//     FormConstructor constructors[3] = {
//         &ShrubberyCreationForm::createNewInstance,
//         &PresidentialPardonForm::createNewInstance,
//         &RobotomyRequestForm::createNewInstance
//     };

//     for (int i = 0; i < 3; i++) {
//         if (name == formList[i]) {
//             // Call the constructor function and store the result
//             returnForm = constructors[i](target);
//             break;
//         }
//     }

//     return returnForm;
// }

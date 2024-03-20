#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
int main(){


  std::cout << "-------------- Testing for errors ------------" << std::endl;
	// {
	// 	try {
	// 		Bureaucrat tooHigh("Too High", 0);
	// 	} 
	// 	catch (std::exception & e) {
	// 		std::cout << "Error " << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		Bureaucrat tooLow("tooLow", 151);
	// 	} 
	// 	catch (std::exception & e) {
	// 		std::cout << "Error " << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	Bureaucrat decrease("decrease", 148);
	// 	try {
	// 		decrease.decreaseGrade(5);
	// 	} 
	// 	catch (std::exception & e) {
	// 		std::cout << "Error " << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	Bureaucrat incease("incease", 3);
	// 	try {
	// 		incease.increaseGrade(4);
	// 	} 
	// 	catch (std::exception & e) {
	// 		std::cout << "Error " << e.what() << std::endl;
	// 	}
	// }

    // std::cout << "---- End of error testing for Bureaucrat ----" << std::endl << std::endl; 
	// Bureaucrat a;
	// std::cout << a << std::endl;
	// std::cout << "Grade before: " << a.getGrade() << std::endl;
	// a.increaseGrade(149);
	// std::cout << "Grade after: " << a.getGrade() << std::endl;
	// std::cout << "Name: " << a.getName() << std::endl;
	// Bureaucrat b("Bob", 5);
	// std::cout << "Grade: "  << b.getGrade() << std::endl;
	// std::cout << "Name: " << b.getName() << std::endl;
	// Bureaucrat c(a);
	// Bureaucrat d;
	// d = a;
	// std::cout << "Grade before: " << c.getGrade() << std::endl;
	// c.decreaseGrade(149);
	// std::cout << "Grade after: " << c.getGrade() << std::endl;
	std::cout << "--------- End of Bureaucrat testing ------------" << std::endl;
	Bureaucrat a("Useless", 150);
	Bureaucrat b("President", 1);
	Bureaucrat c("Can only sign shrub", 138);
	Bureaucrat d("can only exec shrub", 136);

	PresidentialPardonForm president("Bob");
	RobotomyRequestForm robot("Greg");
	ShrubberyCreationForm shrub("Forest");
	{
		try {
			a.executeForm(president);
		} 
		catch (std::exception & e) {
			std::cout << "Error " << e.what() << std::endl;
		}
	}
	{
		try {
			b.executeForm(president);
			// b.executeForm(shrub);
			// b.executeForm(robot);
		}
		catch (std::exception & e) {
			std::cout << "Error " << e.what() << std::endl;
		}
		try {
			b.signAForm(&president);
			b.executeForm(president);
			b.signAForm(&robot);
			b.signAForm(&shrub);
			b.executeForm(shrub);
			b.executeForm(robot);
			a.executeForm(robot);
		}
		catch (std::exception & e) {
			std::cout << "Error " << e.what() << std::endl;
		}
	}
	// {
	// 	std::cout << "cannot sign test" << std::endl;
	// 	AForm soeasy("easy AForm", 149, 149);
	// 	Bureaucrat useless("Useless", 150);
	// 	try {
	// 		useless.signAForm(&soeasy);
	// 	} 
	// 	catch (std::exception & e) {
	// 		std::cout << "Error " << e.what() << std::endl;
	// 	}
	// 	std::cout << "Useless bureaucrat decides to better his skills." << std::endl;
	// 	useless.increaseGrade(149);
	// 	AForm sohard("hard AForm", 1, 1);
	// 	useless.signAForm(&sohard);
	// }
	
	std::cout << "------- End of tests ----------" << std::endl;
    return 0;
}


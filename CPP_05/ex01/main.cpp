#include "Form.hpp"
#include "Bureaucrat.hpp"
int main(){


  std::cout << "-------------- Testing for errors ------------" << std::endl;
	{
		try {
			Bureaucrat tooHigh("Too High", 0);
		} 
		catch (std::exception & e) {
			std::cout << "Error " << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat tooLow("tooLow", 151);
		} 
		catch (std::exception & e) {
			std::cout << "Error " << e.what() << std::endl;
		}
	}
	{
		Bureaucrat decrease("decrease", 148);
		try {
			decrease.decreaseGrade(5);
		} 
		catch (std::exception & e) {
			std::cout << "Error " << e.what() << std::endl;
		}
	}
	{
		Bureaucrat incease("incease", 3);
		try {
			incease.increaseGrade(4);
		} 
		catch (std::exception & e) {
			std::cout << "Error " << e.what() << std::endl;
		}
	}

    std::cout << "---- End of error testing for Bureaucrat ----" << std::endl << std::endl; 
	Bureaucrat a;
	std::cout << a << std::endl;
	std::cout << "Grade before: " << a.getGrade() << std::endl;
	a.increaseGrade(149);
	std::cout << "Grade after: " << a.getGrade() << std::endl;
	std::cout << "Name: " << a.getName() << std::endl;
	Bureaucrat b("Bob", 5);
	std::cout << "Grade: "  << b.getGrade() << std::endl;
	std::cout << "Name: " << b.getName() << std::endl;
	Bureaucrat c(a);
	Bureaucrat d;
	d = a;
	std::cout << "Grade before: " << c.getGrade() << std::endl;
	c.decreaseGrade(149);
	std::cout << "Grade after: " << c.getGrade() << std::endl;
	std::cout << "--------- End of Bureaucrat testing ------------" << std::endl;
	{
		try {
			Form tooHigh("Too High", 0, 0);
		} 
		catch (std::exception & e) {
			std::cout << "Error " << e.what() << std::endl;
		}
	}
	{
		try {
			Form tooLow("Too low", 151, 151);
		} 
		catch (std::exception & e) {
			std::cout << "Error " << e.what() << std::endl;
		}
	}
	{
		std::cout << "cannot sign test" << std::endl;
		Form soeasy("easy form", 149, 149);
		Bureaucrat useless("Useless", 150);
		try {
			useless.signForm(&soeasy);
		} 
		catch (std::exception & e) {
			std::cout << "Error " << e.what() << std::endl;
		}
		std::cout << "Useless bureaucrat decides to better his skills." << std::endl;
		useless.increaseGrade(149);
		Form sohard("hard form", 1, 1);
		useless.signForm(&sohard);
	}
	
	std::cout << "------- End of tests ----------" << std::endl;
    return 0;
}


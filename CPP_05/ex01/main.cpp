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

    std::cout << "---- End of error testing ----" << std::endl << std::endl; 
	Bureaucrat a;
	std::cout << a << std::endl;
	std::cout << "Grade before: " << a.getGrade() << std::endl;
	a.increaseGrade(149);
	std::cout << "Grade after: " << a.getGrade() << std::endl;
	std::cout << "Name: " << a.getName() << std::endl;
	Bureaucrat d("Bob", 5);
	std::cout << "Grade: "  << d.getGrade() << std::endl;
	std::cout << "Name: " << d.getName() << std::endl;
	Bureaucrat b(a);
	Bureaucrat c;
	c = a;
	std::cout << "Grade before: " << c.getGrade() << std::endl;
	c.decreaseGrade(149);
	std::cout << "Grade after: " << c.getGrade() << std::endl;

    return 0;
}


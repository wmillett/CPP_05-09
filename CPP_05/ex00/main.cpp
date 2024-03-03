#include "Bureaucrat.hpp"


int main(){


  std::cout << "Errors testing" << std::endl;
	{
		try {
			Bureaucrat tooHigh("Too High", 0);

			std::cout << tooHigh << std::endl;
		} catch (std::exception& e) {
			std::cout << "Error " << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat tooLow("tooLow", 151);

			std::cout << tooLow << std::endl;
		} catch (std::exception& e) {
			std::cout << "Error " << e.what() << std::endl;
		}
	}
	{
		Bureaucrat incease("incease", 3);
		try {
			incease.increaseGrade(4);
			std::cout << incease << std::endl;
		} catch (std::exception& e) {
			std::cout << "Error " << e.what() << std::endl;
		}
	}
	{
		Bureaucrat decrease("decrease", 148);
		try {
			decrease.decreaseGrade(5);
			std::cout << decrease << std::endl;
		} catch (std::exception& e) {
			std::cout << "Error " << e.what() << std::endl;
		}
	}






    return 0;
}


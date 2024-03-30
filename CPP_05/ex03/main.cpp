#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
int main(){


  std::cout << "-------------- Testing error------------" << std::endl;



	Intern someRandomIntern;

	AForm* rrf;
	rrf = someRandomIntern.makeForm("", "bedner");
	std::cout << "-------------- Testing valid------------" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	Bureaucrat bob("Bob", 2);
	
	bob.signAForm(rrf);
	bob.executeForm(*rrf);
	delete rrf;
	// std::cout << "--------- End of Bureaucrat testing ------------" << std::endl;
	// Bureaucrat a("Useless", 150);
	// Bureaucrat b("President", 1);
	// Bureaucrat c("Can only sign shrub", 138);
	// Bureaucrat d("can only exec shrub", 136);

	// PresidentialPardonForm president("Bob");
	// RobotomyRequestForm robot("Greg");
	// ShrubberyCreationForm shrub("Forest");
	// {
	// 	try {
	// 		a.executeForm(president);
	// 	} 
	// 	catch (std::exception & e) {
	// 		std::cout << "Error " << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		b.executeForm(president);
	// 		// b.executeForm(shrub);
	// 		// b.executeForm(robot);
	// 	}
	// 	catch (std::exception & e) {
	// 		std::cout << "Error " << e.what() << std::endl;
	// 	}
	// 	try {
	// 		b.signAForm(&president);
	// 		b.executeForm(president);
	// 		b.signAForm(&robot);
	// 		b.signAForm(&shrub);
	// 		b.executeForm(shrub);
	// 		b.executeForm(robot);
	// 		a.executeForm(robot);
	// 	}
	// 	catch (std::exception & e) {
	// 		std::cout << "Error " << e.what() << std::endl;
	// 	}
	// }
	
	std::cout << "------- End of tests ----------" << std::endl;
    return 0;
}


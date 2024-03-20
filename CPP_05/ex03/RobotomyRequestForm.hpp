#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class AForm;

class RobotomyRequestForm: public AForm{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        std::string getTarget(void) const;

        bool execute(Bureaucrat const & executor) const;
};









#endif

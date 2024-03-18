#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class AForm;

class ShrubberyCreationForm: public AForm{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        std::string getTarget(void) const;

        bool execute(Bureaucrat const & executor) const;
};









#endif

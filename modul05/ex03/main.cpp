#include "./Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
    {
		Bureaucrat obj("president", 1);
        Intern intern_obj;
        AForm *form = NULL;
		std::cout << "***************************************" << std::endl;
        form = intern_obj.makeForm("PresidentialPardonForm", "alvares");

		obj.signForm(*form);
		obj.executeForm(*form);
		delete form;
		std::cout << "***************************************" << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	return (0);
}

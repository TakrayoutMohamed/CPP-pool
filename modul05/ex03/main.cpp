#include "./Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
    {
		Bureaucrat obj("CEO", 1);
        Intern intern_obj;
        AForm *form;
		std::cout << "***************************************" << std::endl;
        form = intern_obj.makeForm("robotomy request", "Bender");
        try
        {
    		obj.signForm(*form);        
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
    		obj.executeForm(*form);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
		delete form;
		std::cout << "***************************************" << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	return (0);
}

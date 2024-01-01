#include "./Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try
    {
        Bureaucrat obj("Counselor", 3);
        ShrubberyCreationForm shrubbery("Home");
        std::cout << obj << std::endl;
        shrubbery.shrubberyAction();
        // form.beSigned(obj);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	return (0);
}

#include "./Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try
    {
        Bureaucrat obj("Counselor", 3);
        ShrubberyCreationForm shrubbery("Home");
        std::cout << obj << std::endl;
        shrubbery.beSigned(obj);
        shrubbery.execute(obj);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	return (0);
}

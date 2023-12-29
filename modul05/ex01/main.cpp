#include "./Bureaucrat.hpp"

int main(void)
{
	try
    {
        Bureaucrat obj("Counselor", 1);
        Form form("Judge", 2, 50);
        std::cout << obj << std::endl;
        std::cout << form << std::endl;
        form.beSigned(obj);
        obj.signForm(form);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	return (0);
}

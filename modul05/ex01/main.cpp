#include "./Bureaucrat.hpp"

int main(void)
{
	try
    {
        Bureaucrat obj("Counselor", 1);
        Form form("Judge", 1, 50);
        form.beSigned(obj);
        obj.signForm(form);
        std::cout << form;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	return (0);
}

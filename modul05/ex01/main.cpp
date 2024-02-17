#include "./Bureaucrat.hpp"

int main(void)
{
	try
    {
        Bureaucrat Counselor("Counselor", 3);
        Form form1("Form1", 3, 50);
        Form form2("Form2", 2, 2);
        std::cout << Counselor << std::endl;
        std::cout << form1 << std::endl;
        form1.beSigned(Counselor);
        Counselor.signForm(form1);
        Counselor.signForm(form2);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	return (0);
}

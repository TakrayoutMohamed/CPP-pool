#include "./Bureaucrat.hpp"

int main(void)
{
	Bureaucrat	a("negro", 3);
	Bureaucrat b(a);
	Bureaucrat c("test bureau", 145);
	c = a;
	Bureaucrat d("alvares", 1);

	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << a;
	std::cout << d;
	std::cout << "++++++++++++++++++++++decrement++++" << std::endl;
	d.decrementGrade();
	std::cout << d;
	std::cout << "+++++++++++++++++++++increment+++++" << std::endl;
	d.incrementGrade();
	std::cout << d;
	std::cout << "+++++++++++++++++++++increment+++++" << std::endl;
	d.incrementGrade();
	std::cout << d;

	return (0);
}

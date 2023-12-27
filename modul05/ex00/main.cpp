#include "./Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat Bloc0;
		Bureaucrat Bloc1("Governor", 145);
		std::cout << Bloc1;
		Bloc1.decrementGrade();
		std::cout << Bloc1;
		Bloc1.incrementGrade();
		std::cout << Bloc1;
		Bloc0.decrementGrade();
	}
	catch(std::exception &gradeExceptions)
	{
		std::cout << gradeExceptions.what() << std::endl;
	}
	return (0);
}

#include "./Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat B0("alvares", 1);
		std::cout << "Bureaucrat named "<< B0.getName() << " has grade " <<B0.getGrade() << std::endl;
		Bureaucrat Bloc1("Governor", 145);
		std::cout << Bloc1;
		Bloc1.decrementGrade();
		std::cout << Bloc1;
		Bloc1.incrementGrade();
		std::cout << Bloc1;
		B0.decrementGrade();
	}
	catch(std::exception &gradeExceptions)
	{
		std::cout << gradeExceptions.what() << std::endl;
	}
	return (0);
}

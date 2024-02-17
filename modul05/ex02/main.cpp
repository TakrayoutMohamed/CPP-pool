#include "./Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	try
	{
		std::cout << "********************* CONSTRUCTORS **********************" << std::endl;
		
		Bureaucrat Counselor("Counselor", 20);
		
		PresidentialPardonForm ppf("PresidentialPardonForm");
		RobotomyRequestForm	rrf("RobotomyRequestForm");
		ShrubberyCreationForm scf("home");

		std::cout << "***************** FORMS DEMONSTRATION ******************" << std::endl;
		
		try
		{
			ppf.beSigned(Counselor);		
		}
		catch(const std::exception& e)
		{
			std::cerr << Counselor.getName() << " couldn't sign "<< ppf.getName() <<" Because : " << e.what() << std::endl;
		}
		try
		{
			ppf.execute(Counselor);
		}
		catch(const std::exception& e)
		{
			std::cerr << Counselor.getName() << " couldn't execute "<< ppf.getName() <<" Because : " << e.what() << std::endl;
		}
		try
		{
			rrf.beSigned(Counselor);
		}
		catch(const std::exception& e)
		{
			std::cerr << Counselor.getName() << " couldn't sign "<< rrf.getName() <<" Because : " << e.what() << std::endl;
		}
		try
		{
			rrf.execute(Counselor);
		}
		catch(const std::exception& e)
		{
			std::cerr << Counselor.getName() << " couldn't execute "<< rrf.getName() <<" Because : " << e.what() << std::endl;
		}
		try
		{
			scf.beSigned(Counselor);
		}
		catch(const std::exception& e)
		{
			std::cerr << Counselor.getName() << " couldn't sign "<< scf.getName() <<" Because : " << e.what() << std::endl;
		}
		try
		{
			scf.execute(Counselor);
		}
		catch(const std::exception& e)
		{
			std::cerr << Counselor.getName() << " couldn't sign "<< scf.getName() <<" Because : " << e.what() << std::endl;
		}
		
		
		
		std::cout << "************** BUREAUCRAT FORMS EXECUTION **************" << std::endl;
		
		AForm *form;
		
		form = &rrf;
		form->beSigned(Counselor);
		Counselor.executeForm(*form);
		
		std::cout << "********************* DESTRUCTORS **********************" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

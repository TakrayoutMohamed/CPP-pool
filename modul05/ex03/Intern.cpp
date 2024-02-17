#include "Intern.hpp"

Intern::Intern(/* args */)
{
	std::cout << "Default constructor for intern has been called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
	std::cout << "Copy constructor for intern has been called" << std::endl;
	if (this != &obj)
	{
		*this = obj;
	}
}

const Intern &Intern::operator=(const Intern &obj)
{
	(void) obj;
	std::cout << "Copy assignement operator for intern has been called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Destructor for intern has been called" << std::endl;
}

/*member function exception*/
const char *Intern::FormNotExistException::what(void) const throw()
{
	return ("FormNotExistException from Intern");
}

AForm	* Intern::makeForm(std::string formName, std::string formTarget) const
{
	int	i;
	const std::string forms[] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	i = 0;
	for (i = 0; i < 3; i++)
	{
		if (!forms[i].compare(formName))
			break ;
	}
	switch (i)
	{
		case 0:
			return (new RobotomyRequestForm(formTarget));
			break;
		case 1:
			return (new PresidentialPardonForm(formTarget));
			break;
		case 2:
			return (new ShrubberyCreationForm(formTarget));
			break;
		default:
			throw Intern::FormNotExistException;
	}
	
}

#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(/* args */) : _name("Bureacrat default"), _grade(150)
{
	std::cout << "Default constructor for the bureaucrat has been created" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade)
{
	std::cout << "constructor(name, grade) has been created" << std::endl;

}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor for the bureaucrat has been created" << std::endl;
}


std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

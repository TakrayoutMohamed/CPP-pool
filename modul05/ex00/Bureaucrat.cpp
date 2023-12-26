#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(/* args */) : _name("BureacratDefaultName"), _grade(150)
{
	std::cout << "{Default constructor for the bureaucrat named ["<< getName() << "] has been called}" << std::endl;
}

/*copy constructor*/
Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj.getName())
{
	std::cout << "{copy constructor to copy from the bureaucrat named [" << obj.getName() <<"] has been called}" << std::endl;
	*this = obj;
}
/*copy assignment operator*/
const Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	std::cout << "{copy assignment operator has been called to copy the data of bureaucrat named :["<< obj.getName()<< "]}" << std::endl;
	this->_grade = obj.getGrade();
	// this->_name = obj.getName();
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade)
{
	std::cout << "{constructor for [" << getName() << "] has been called with grade " << getGrade() <<"}" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException;
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "{Destructor for the bureaucrat named ["<< getName() <<"] has been called }" << std::endl;
}


std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}


void	Bureaucrat::incrementGrade(void)
{
	try
	{
		if (getGrade() <= 1)
			throw GradeTooHighException;
		this->_grade = getGrade() - 1;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		if (getGrade() >= 150)
			throw GradeTooLowException;
		this->_grade = getGrade() + 1;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHigh");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLow");
}

/*here overloading the output stream*/
std::ostream	&operator<< (std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return (os);
}



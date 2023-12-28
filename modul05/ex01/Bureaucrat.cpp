#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(/* args */) : _name("BureacratDefaultName"), _grade(150)
{
	std::cout << "{Default constructor for the bureaucrat named ["<< getName() << "] has been called}" << std::endl;
}

/*copy constructor*/
Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	std::cout << "{copy constructor to copy from the bureaucrat named [" << obj.getName() <<"] has been called}" << std::endl;
	if (this != &obj)
		*this = obj;
}
/*copy assignment operator*/
const Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	std::cout << "{copy assignment operator has been called to copy the data of bureaucrat named :["<< obj.getName()<< "]}" << std::endl;
	if (this != &obj)
	{
		this->_grade = obj.getGrade();
		(std::string)this->_name = obj.getName();
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException;
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException;
	std::cout << "{constructor for [" << getName() << "] has been called with grade " << getGrade() <<"}" << std::endl;
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
	if (getGrade() <= 1)
		throw Bureaucrat::GradeTooHighException;
	this->_grade = getGrade() - 1;
}

void	Bureaucrat::decrementGrade(void)
{
	if (getGrade() >= 150)
		throw Bureaucrat::GradeTooLowException;
	this->_grade = getGrade() + 1;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName() << "because " << e.what() << std::endl;

	}

}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHigh from Bureaucrat");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLow from Bureaucrat");
}

/*here overloading the output stream*/
std::ostream	&operator<< (std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return (os);
}



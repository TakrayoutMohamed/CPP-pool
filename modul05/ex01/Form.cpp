#include "./Form.hpp"

Form::Form(/* args */) : _name("DefaultNameForm"), _gradeToSign(150), _gradeToExecute(150)
{
	this->_isSigned = false;
	if (_gradeToSign > 150)
		throw Form::GradeTooLowException;
	if (_gradeToExecute > 150)
		throw Form::GradeTooLowException;
	if (_gradeToSign < 1)
		throw Form::GradeTooHighException;
	if (_gradeToExecute < 1)
		throw Form::GradeTooHighException;
	// std::cout << "Default constructor for Form named {"<< this->getName() << "} has been called" << std::endl;
}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	this->_isSigned = false;
	if (_gradeToSign > 150)
		throw Form::GradeTooLowException;
	if (_gradeToExecute > 150)
		throw Form::GradeTooLowException;
	if (_gradeToSign < 1)
		throw Form::GradeTooHighException;
	if (_gradeToExecute < 1)
		throw Form::GradeTooHighException;
	// std::cout << "paramitrized constructor for Form named {"<< this->getName() << "} has been called" << std::endl;
}

Form::Form(const Form &obj)  : _name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
	// std::cout << "Copy constructor has been called" << std::endl;
	if (this != &obj)
		*this = obj;
}

const Form &Form::operator=(const Form &obj)
{
	// std::cout << "Copy assignment operator has been called" << std::endl;
	if (this != &obj)
	{
		this->_isSigned = obj.getIsSigned();
	}
	return (*this);	
}

Form::~Form()
{
	// std::cout << "Destructor has been called for the form named {"<< getName() << "}" << std::endl;
}

/*getters*/
const std::string &Form::getName(void) const
{
	return (this->_name);
}

bool Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

/***********form exceptions***********************************/
const char *Form::GradeTooHighException::what() const throw()
{
	return ("GradeTooHigh From Form");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("GradeTooLow From Form");
}

/***********member functions***********************************/
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException;
	_isSigned = true;
}

std::ostream &operator<<(std::ostream &os,const Form &form)
{
	os << "************the form information:**************" << std::endl;
	os << "** form name                     : "<< form.getName() << std::endl;
	os << "** form grade required to sign   : "<< form.getGradeToSign() << std::endl;
	os << "** form grade required to execute: "<< form.getGradeToExecute() << std::endl;
	if (form.getIsSigned() == true)
		os << "** form is Signed"<< std::endl;
	else
		os << "** form not Signed "<< std::endl;
	os << "***********************************************"<< std::endl;
	return (os);
}

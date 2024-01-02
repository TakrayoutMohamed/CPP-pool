#include "./AForm.hpp"

AForm::AForm(/* args */) : _name("DefaultNameAForm"), _gradeToSign(150), _gradeToExecute(150)
{
	this->_isSigned = false;
	if (_gradeToSign > 150)
		throw AForm::GradeTooLowException;
	if (_gradeToExecute > 150)
		throw AForm::GradeTooLowException;
	if (_gradeToSign < 1)
		throw AForm::GradeTooHighException;
	if (_gradeToExecute < 1)
		throw AForm::GradeTooHighException;
	std::cout << "Default constructor for AForm named {"<< this->getName() << "} has been called" << std::endl;
}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	this->_isSigned = false;
	if (_gradeToSign > 150)
		throw AForm::GradeTooLowException;
	if (_gradeToExecute > 150)
		throw AForm::GradeTooLowException;
	if (_gradeToSign < 1)
		throw AForm::GradeTooHighException;
	if (_gradeToExecute < 1)
		throw AForm::GradeTooHighException;
	std::cout << "paramitrized constructor for AForm named {"<< this->getName() << "} has been called" << std::endl;
}

AForm::AForm(const AForm &obj)  : _name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
	std::cout << "Copy constructor has been called" << std::endl;
	if (this != &obj)
		*this = obj;
}

const AForm &AForm::operator=(const AForm &obj)
{
	std::cout << "Copy assignment operator has been called" << std::endl;
	if (this != &obj)
	{
		this->_isSigned = obj.getIsSigned();
	}
	return (*this);	
}

AForm::~AForm()
{
	std::cout << "Destructor has been called for the Aform named {"<< getName() << "}" << std::endl;
}

/*getters*/
const std::string &AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

/***********Aform exceptions***********************************/
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("GradeTooHigh From AForm");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("GradeTooLow From AForm");
}

const char *AForm::GradeNotSignedException::what() const throw()
{
	return ("GradeNotSigned From AForm");
}

/***********member functions***********************************/
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException;
	_isSigned = true;
}

void AForm::checkExecutRequirment(const Bureaucrat& executor) const
{
	if (getIsSigned() != true)
		throw AForm::GradeNotSignedException;
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException;
}

std::ostream &operator<<(std::ostream &os,const AForm &Aform)
{
	os << "************the Aform inAformation:**************" << std::endl;
	os << "** Aform name                     : "<< Aform.getName() << std::endl;
	os << "** Aform grade required to sign   : "<< Aform.getGradeToSign() << std::endl;
	os << "** Aform grade required to execute: "<< Aform.getGradeToExecute() << std::endl;
	if (Aform.getIsSigned() == true)
		os << "** Aform is Signed"<< std::endl;
	else
		os << "** Aform not Signed "<< std::endl;
	os << "***********************************************"<< std::endl;
	return (os);
}

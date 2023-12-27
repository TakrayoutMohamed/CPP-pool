#include "./Form.hpp"

Form::Form(/* args */) : _name("DefaultNameForm"), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Default constructor has been called" << std::endl;
}

Form::Form(const Form &obj)  : _name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
	std::cout << "Copy constructor has been called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Form &Form::operator=(const Form &obj)
{
	std::cout << "Copy assignment operator has been called" << std::endl;
	if (this != &obj)
	{
		this->_isSigned = obj.getIsSigned();
	}
	return (*this);	
}

Form::~Form()
{
	std::cout << "Destructor has been called" << std::endl;
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

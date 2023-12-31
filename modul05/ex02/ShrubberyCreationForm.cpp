#include "./ShrubberyCreationForm.hpp"


/*default constructor*/
ShrubberyCreationForm::ShrubberyCreationForm(/* args */) : _target("defaultShrubbery") , AForm("defaultAFormShru", 145, 137)
{
	std::cout << "Default Constructor for the shrubbery target named {"<< getTarget() <<"} has been called!"<< std::endl;
}

/*paramitrized constructor with string*/
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : _target(target) , AForm("defaultAFormShru", 145, 137)
{
	std::cout << "paramitrized Constructor for the shrubbery target named {"<< getTarget() <<"} has been called!"<< std::endl;
}

/*copy constructor*/
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute())
{
	if (this != &obj)
	{
		*this = obj;
	}
	std::cout << "Copy Constructor for the shrubbery target named {"<< obj.getTarget() << "} has been called!"<< std::endl;
}


/*copy assignment operator*/
const ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	std::cout << "Copy assignment operator for the shrubbery target named {"<< obj.getTarget() << "} has been called!"<< std::endl;
	if (this != &obj)
	{
		this->_target = obj.getTarget();
	}
	return (*this);
}

/*destructor*/
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor for the shrubbery target named {"<< getTarget() << "}  has been called!"<< std::endl;
}

/*getters*/

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

/*member functions */

void	ShrubberyCreationForm::shrubberyAction(const std::string &target) const
{
	
}

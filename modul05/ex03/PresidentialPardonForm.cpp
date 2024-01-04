#include "./PresidentialPardonForm.hpp"

/*default constructor*/
PresidentialPardonForm::PresidentialPardonForm(/* args */) : AForm("defaultAFormPrisPard", 25, 5)
{
	_target = "defaultpresidentialPardon";
	std::cout << "Default Constructor for the presidentialPardon target named {"<< getTarget() <<"} has been called!"<< std::endl;
}

/*paramitrized constructor with string*/
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("defaultAFormPrisPard", 25, 5)
{
	_target = target;
	std::cout << "paramitrized Constructor for the presidentialPardon target named {"<< getTarget() <<"} has been called!"<< std::endl;
}

/*copy constructor*/
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute())
{
	if (this != &obj)
	{
		*this = obj;
	}
	std::cout << "Copy Constructor for the presidentialPardon target named {"<< obj.getTarget() << "} has been called!"<< std::endl;
}


/*copy assignment operator*/
const PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	std::cout << "Copy assignment operator for the presidentialPardon target named {"<< obj.getTarget() << "} has been called!"<< std::endl;
	if (this != &obj)
	{
		this->_target = obj.getTarget();
	}
	return (*this);
}

/*destructor*/
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor for the presidentialPardon target named {"<< getTarget() << "}  has been called!"<< std::endl;
}

/*getters*/

std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

/*member functions */

void	PresidentialPardonForm::presidentialPardonAction(void) const
{

	std::cout << getTarget() <<  " has been pardoned by Zaphod Beeblerox." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkExecutRequirment(executor);
    presidentialPardonAction();
}
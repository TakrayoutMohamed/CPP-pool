#include "./RobotomyRequestForm.hpp"

/*default constructor*/
RobotomyRequestForm::RobotomyRequestForm(/* args */) : AForm("defaultAFormRoboReq", 72, 45)
{
	_target = "defaultrobotomyRequest";
	// std::cout << "Default Constructor for the robotomyRequest target named {"<< getTarget() <<"} has been called!"<< std::endl;
}

/*paramitrized constructor with string*/
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("defaultAFormRoboReq", 72, 45)
{
	_target = target;
	// std::cout << "paramitrized Constructor for the robotomyRequest target named {"<< getTarget() <<"} has been called!"<< std::endl;
}

/*copy constructor*/
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute())
{
	if (this != &obj)
	{
		*this = obj;
	}
	// std::cout << "Copy Constructor for the robotomyRequest target named {"<< obj.getTarget() << "} has been called!"<< std::endl;
}


/*copy assignment operator*/
const RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	// std::cout << "Copy assignment operator for the robotomyRequest target named {"<< obj.getTarget() << "} has been called!"<< std::endl;
	if (this != &obj)
	{
		this->_target = obj.getTarget();
	}
	return (*this);
}

/*destructor*/
RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "Destructor for the robotomyRequest target named {"<< getTarget() << "}  has been called!"<< std::endl;
}

/*getters*/

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

/*member functions */

void	RobotomyRequestForm::robotomyRequestAction(void) const
{
    int random = rand();
	std::cout << getTarget() <<  " Some driling noises." << std::endl;
    if (random % 2 == 0)
        std::cout << getTarget() << "has been robotomized successfully" << std::endl;
    else
        std::cout << getTarget() << " the robotomy failed" << std::endl;

}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExecutRequirment(executor);
    robotomyRequestAction();
}

#include "./ShrubberyCreationForm.hpp"


/*default constructor*/
ShrubberyCreationForm::ShrubberyCreationForm(/* args */) : AForm("defaultAFormShru", 145, 137)
{
	_target = "defaultShrubbery";
	std::cout << "Default Constructor for the shrubbery target named {"<< getTarget() <<"} has been called!"<< std::endl;
}

/*paramitrized constructor with string*/
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("defaultAFormShru", 145, 137)
{
	_target = target;
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

/*exceptions classes member function*/
const char *ShrubberyCreationForm::FileCreationException::what() const throw()
{
	return ("FileCreationException from ShrubberyCreationForm");
}

/*getters*/

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

/*member functions */

void traceAsciiTree(std::ofstream &os)
{
	os << "              v .   ._, |_  .,        " << std::endl;
	os << "           `-._\\/  .  \\ /    |/_      " << std::endl;
	os << "               \\  _\\, y | \\//        " << std::endl;
	os << "         _\\_.___\\, \\/ -.\\||         " << std::endl;
	os << "           `7-,--.`._||  / / ,        " << std::endl;
	os << "           /'     `-. `./ / |/_.'     " << std::endl;
	os << "                     |    |//         " << std::endl;
	os << "                     |_    /          " << std::endl;
	os << "                     |-   |           " << std::endl;
	os << "                     |   =|           " << std::endl;
	os << "                     |    |           " << std::endl;
	os << "--------------------/ ,  . \\--------._" << std::endl;
}

void	ShrubberyCreationForm::shrubberyAction(void) const 
	throw(ShrubberyCreationForm::FileCreationException)
{
	std::ofstream	outFile;

	outFile.open((getTarget() + "_shrubbery"));
	if (!outFile.is_open())
	{
		std::cout << "the file :{"<< getTarget() + "_shrubbery" << "} could not be created " << std::endl;
		throw ShrubberyCreationForm::FileCreationException();
	}
	traceAsciiTree(outFile);
	outFile.close();
	std::cout << "the file{"<< getTarget() <<"_shrubbery} has been created successfully and filled with an ascii tree" << std::endl;
	std::cout << "the shrubbery has been planted at " << getTarget() << " successfully" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkExecutRequirment(executor);
	try
	{
		shrubberyAction();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}
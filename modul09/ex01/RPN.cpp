#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "Default constructor RPN" << std::endl;
}

RPN::RPN(const RPN &obj)
{
	std::cout << "Copy constructor RPN" << std::endl;
	if (this != &obj)
	{
		*this = obj;
	}
}

const RPN &RPN::operator=(const RPN &obj)
{
	std::cout << "Copy assingnment operator RPN" << std::endl;
	if (this != &obj)
	{

	}
	return (*this);
}

~RPN::RPN()
{
	std::cout << "Destructor RPN" << std::endl;
}


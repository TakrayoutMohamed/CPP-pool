#include "./ConvertToInt.hpp"

ConvertToInt::ConvertToInt(/* args */)
{
	std::cout << "Default constructor for class ConvertToInt" << std::endl;
}

ConvertToInt::ConvertToInt(const std::string &str)
{
	std::cout << "Constructor(std::string &str) for class ConvertToInt" << std::endl;
}

ConvertToInt::ConvertToInt(const ConvertToInt &obj)
{
	std::cout << "Copy constructor for class ConvertToInt" << std::endl;
	*this = obj;
}

const ConvertToInt &ConvertToInt::operator=(const ConvertToInt &obj)
{
	std::cout << "copy assignment operator for class ConvertToInt" << std::endl;
	return (*this);
}

ConvertToInt::~ConvertToInt()
{
	std::cout << "Destructor for class ConvertToInt" << std::endl;
}

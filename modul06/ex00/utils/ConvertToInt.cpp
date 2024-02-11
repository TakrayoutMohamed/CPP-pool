#include "./ConvertToInt.hpp"

ConvertToInt::ConvertToInt(/* args */) : nbr (-1337)
{
	std::cout << "Default constructor for class ConvertToInt" << std::endl;
}

ConvertToInt::ConvertToInt(const std::string &str)
{
	std::stringstream(str) << this->nbr;
	std::cout << "Constructor(std::string &str) for class ConvertToInt" << std::endl;
}

ConvertToInt::ConvertToInt(float nbrFloat) : nbr(nbrFloat)
{
	std::cout << "Constructor(float nbrFloat) for class ConvertToInt" << std::endl;
}

ConvertToInt::ConvertToInt(double nbrDouble) : nbr(nbrDouble)
{
	std::cout << "Constructor(double nbrDouble) for class ConvertToInt" << std::endl;
}

ConvertToInt::ConvertToInt(char nbrChar) : nbr(nbrChar)
{
	std::cout << "Constructor(char nbrChar) for class ConvertToInt" << std::endl;
}

ConvertToInt::ConvertToInt(const ConvertToInt &obj)
{
	std::cout << "Copy constructor for class ConvertToInt" << std::endl;
	*this = obj;
}

const ConvertToInt &ConvertToInt::operator=(const ConvertToInt &obj)
{
	std::cout << "copy assignment operator for class ConvertToInt" << std::endl;
	if (this != &obj)
		this->nbr = obj.nbr;
	return (*this);
}

ConvertToInt::~ConvertToInt()
{
	std::cout << "Destructor for class ConvertToInt" << std::endl;
}

/*methods */
ConvertToInt::operator int()
{
	std::cout << "Convertion operator for class ConvertToInt" << std::endl;
	return (nbr);
}

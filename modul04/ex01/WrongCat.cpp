#include "WrongCat.hpp"

WrongCat::WrongCat(/* args */)
{
	std::cout << "Default constructor of the WrongCat class" << std::endl;
	this->type = "WrongCat";
}

const WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	std::cout << "Copy assignment operator of the WrongCat class" << std::endl;
	if (this == &obj)
		return (*this);
	this->type = obj.type;
	return (*this);
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj)
{
	std::cout << "Copy constructor of the WrongCat class" << std::endl;
	if (this != &obj)
		*this = obj;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor of the WrongCat class" << std::endl;
}

/*member functions*/

void WrongCat::makeSound(void) const
{
	std::cout << "myaw myaw" << std::endl;
}

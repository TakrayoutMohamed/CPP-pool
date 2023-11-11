#include "./WrongAnimal.hpp"

/*orthodox canonical form*/
WrongAnimal::WrongAnimal(/* args */)
{
	std::cout << "Default constructor of the WrongAnimal class" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	std::cout << "Copy constructor of the WrongAnimal class" << std::endl;
	if (this != &obj)
		*this = obj;
}
const WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	std::cout << "Copy assignment operator of the WrongAnimal class" << std::endl;
	if (this == &obj)
		return (*this);
	this->type = obj.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of the WrongAnimal class" << std::endl;
}

/*member functions*/
void WrongAnimal::makeSound(void) const
{
	std::cout << "{WrongAnimal sound}" << std::endl;
}

/*getters*/

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

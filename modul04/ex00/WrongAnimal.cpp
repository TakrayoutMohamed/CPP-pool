#include "./WrongAnimal.hpp"

/*orthodox canonical form*/
WrongAnimal::WrongAnimal(/* args */)
{
    this->type = "WrongAnimal";
    std::cout << "Default constructor of the WrongAnimal class" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
    *this = obj;
    std::cout << "Copy constructor of the WrongAnimal class" << std::endl;
}
const WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
    this->type = obj.type;
    std::cout << "Copy assignment operator of the WrongAnimal class" << std::endl;
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

#include "./Animal.hpp"

/*orthodox canonical form*/
Animal::Animal(/* args */)
{
    this->type = "Animal";
    std::cout << "Default constructor of the Animal class" << std::endl;
}

Animal::Animal(const Animal& obj)
{
    *this = obj;
    std::cout << "Copy constructor of the Animal class" << std::endl;
}
const Animal& Animal::operator=(const Animal& obj)
{
    this->type = obj.type;
    std::cout << "Copy assignment operator of the Animal class" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Destructor of the Animal class" << std::endl;
}

/*member functions*/
void Animal::makeSound(void) const
{
    std::cout << "{animal sound}" << std::endl;
}

/*getters*/

std::string Animal::getType(void) const
{
    return (this->type);
}

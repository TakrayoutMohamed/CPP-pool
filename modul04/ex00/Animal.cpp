#include "./Animal.hpp"

/*orthodox canonical form*/
Animal::Animal(/* args */)
{
    std::cout << "Default constructor of the Animal class" << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal& obj)
{
    std::cout << "Copy constructor of the Animal class" << std::endl;
    if (this != &obj)
        *this = obj;
}
const Animal& Animal::operator=(const Animal& obj)
{
    std::cout << "Copy assignment operator of the Animal class" << std::endl;
    if (this == &obj)
        return (*this);
    this->type = obj.type;
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

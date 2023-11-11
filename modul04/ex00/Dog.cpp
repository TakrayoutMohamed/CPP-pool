#include "Dog.hpp"

Dog::Dog(/* args */) : Animal()
{
    this->type = "Dog";
    std::cout << "Default constructor of the Dog class" << std::endl;
}

const Dog& Dog::operator=(const Dog& obj)
{
    this->type = obj.type;
    std::cout << "Copy assignment operator of the Dog class" << std::endl;
    return (*this);
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
    *this = obj;
    std::cout << "Copy constructor of the Dog class" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Destructor of the Dog class" << std::endl;
}

/*member functions*/

void Dog::makeSound(void) const
{
    std::cout << "barking" << std::endl;
}

#include "Dog.hpp"

Dog::Dog(/* args */) : Animal()
{
    std::cout << "Default constructor of the Dog class" << std::endl;
    this->brain = new Brain();
    this->type = "Dog";
}

const Dog& Dog::operator=(const Dog& obj)
{
    std::cout << "Copy assignment operator of the Dog class" << std::endl;
    if (this == &obj)
        return (*this);
    this->type = obj.type;
    this->brain = obj.brain;
    return (*this);
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
    std::cout << "Copy constructor of the Dog class" << std::endl;
    if (this != &obj)
        *this = obj;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Destructor of the Dog class" << std::endl;
}

/*member functions*/

void Dog::makeSound(void) const
{
    std::cout << "barking" << std::endl;
}
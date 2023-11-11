#include "Cat.hpp"

Cat::Cat(/* args */) : Animal()
{
    std::cout << "Default constructor of the Cat class" << std::endl;
    this->brain = new Brain();
    this->type = "Cat";
}

const Cat& Cat::operator=(const Cat& obj)
{
    std::cout << "Copy assignment operator of the Cat class" << std::endl;
    if (this == &obj)
        return (*this);
    this->type = obj.type;
    this->brain = obj.brain;
    return (*this);
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
    std::cout << "Copy constructor of the Cat class" << std::endl;
    if (this != &obj)
        *this = obj;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Destructor of the Cat class" << std::endl;
}

/*member functions*/

void Cat::makeSound(void) const
{
    std::cout << "myaw myaw" << std::endl;
}

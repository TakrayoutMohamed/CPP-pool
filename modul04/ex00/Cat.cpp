#include "Cat.hpp"

Cat::Cat(/* args */) : Animal()
{
    std::cout << "Default constructor of the Cat class" << std::endl;
    this->type = "Cat";
}

const Cat& Cat::operator=(const Cat& obj)
{
    if (this == &obj)
        return (*this);
    std::cout << "Copy assignment operator of the Cat class" << std::endl;
    this->type = obj.type;
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
    std::cout << "Destructor of the Cat class" << std::endl;
}

/*member functions*/

void Cat::makeSound(void) const
{
    std::cout << "myaw myaw" << std::endl;
}

#include "Cat.hpp"

Cat::Cat(/* args */) : Animal()
{
    this->type = "Cat";
    std::cout << "Default constructor of the Cat class" << std::endl;
}

const Cat& Cat::operator=(const Cat& obj)
{
    this->type = obj.type;
    std::cout << "Copy assignment operator of the Cat class" << std::endl;
    return (*this);
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
    *this = obj;
    std::cout << "Copy constructor of the Cat class" << std::endl;
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

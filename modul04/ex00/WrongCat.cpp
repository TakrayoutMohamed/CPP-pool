#include "WrongCat.hpp"

WrongCat::WrongCat(/* args */)
{
    this->type = "WrongCat";
    std::cout << "Default constructor of the WrongCat class" << std::endl;
}

const WrongCat& WrongCat::operator=(const WrongCat& obj)
{
    this->type = obj.type;
    std::cout << "Copy assignment operator of the WrongCat class" << std::endl;
    return (*this);
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj)
{
    *this = obj;
    std::cout << "Copy constructor of the WrongCat class" << std::endl;
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

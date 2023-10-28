#include "Weapon.hpp"

 Weapon::Weapon(std::string type) : type(type)
 {
    // std::cout << "Constructor the takes a parameter was called with value :";
    // std::cout << str << std::endl;
    // setType(type);
    return ;
 }

Weapon::~Weapon()
{
    return ;
}

const std::string &Weapon::getType(void)
{
    return (this->type);
}

void    Weapon::setType(std::string newWeapon)
{
    this->type = newWeapon;
}

#include "Weapon.hpp"

Weapon::Weapon(/* args */)
{
    return ;
}

Weapon::~Weapon()
{
    return ;
}

std::string &Weapon::getType(void)
{
    return (this->type);
}

void    Weapon::setType(std::string newWeapon)
{
    this->type = newWeapon;
}

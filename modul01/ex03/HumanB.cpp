#include "./HumanB.hpp"

// HumanB::HumanB(/* args */)
// {
// 	// std::cout << "default Constructor HumanB called" << std::endl;
// 	return ;
// }

HumanB::HumanB(std::string name)
{

	// std::cout << "Constructor HumanB the takes a parameter was called with value :";
    // std::cout << name << std::endl;
    setName(name);
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void	HumanB::attack(void)
{
	std::cout << getName() << " attacks with their " << getWeapon().getType();
	std::cout << std::endl;
}

/*setters*/

void	HumanB::setName(std::string name)
{
	this->_name = name;
}

void	HumanB::setWeapon(Weapon &weaponB)
{
	this->_weapon = &weaponB;
}

/*getters*/

std::string	HumanB::getName(void)
{
	return (this->_name);
}

Weapon& HumanB::getWeapon(void)
{
	return (*this->_weapon);
}

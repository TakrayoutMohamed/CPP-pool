#include "./HumanA.hpp"

// HumanA::HumanA(/* args */)
// {
// 	// std::cout << "default Constructor HumanA called" << std::endl;
// 	return ;
// }

HumanA::HumanA(std::string name, Weapon & weaponName): _weapon(weaponName)
{

	// std::cout << "Constructor HumanA the takes a parameter was called with value :";
    // std::cout << name << std::endl;
    setName(name);
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void	HumanA::attack(void)
{
	std::cout << getName() << " attacks with their " << this->_weapon.getType();
	std::cout << std::endl;
}

/*getters*/

std::string	HumanA::getName(void)
{
	return (this->_name);
}

Weapon	&HumanA::getWeapon(void)
{
	return (this->_weapon);
}

void	HumanA::setName(std::string name)
{
	this->_name = name;
}

void	HumanA::setWeapon(Weapon &weapona)
{
	this->_weapon = weapona;
}

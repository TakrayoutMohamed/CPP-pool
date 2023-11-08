#include "./FragTrap.hpp"

/*******Orthodox Canonical Form and a structor takes a string as parameter *******/

/*Default constructor*/
FragTrap::FragTrap(/* args */) : ClapTrap()
{
	this->setHitPionts(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setName("");
	std::cout << "Default constructor for FragTrap Named ["<< this->getName() <<"] called" << std::endl;
}
/*copy assignement operator*/
const FragTrap &FragTrap::operator=(const FragTrap& obj)
{
	std::cout << "Copy assignement operator to assign FragTrap Named ["<< obj.getName() \
	<<"] to FragTrap Named [" << this->getName() <<"]" << std::endl;
	this->setName(obj.getName());
    this->setHitPionts(obj.getHitPoints());
	this->setEnergyPoints(obj.getEnergyPionts());
	this->setAttackDamage(obj.getAttackDamage());
	return (*this);
}
/*copy constructor*/
FragTrap::FragTrap(const FragTrap &obj)
{
	*this = obj;
	std::cout << "Copy constructor for FragTrap Named ["<< this->getName() <<"] called" << std::endl;
}
/*Destructor*/
FragTrap::~FragTrap()
{
	std::cout << "Destructor for FragTrap Named ["<< this->getName() <<"] called" << std::endl;
}

/*Constructor that takes a string as parameter*/
FragTrap::FragTrap(const std::string &name)  : ClapTrap(name)
{
	this->setHitPionts(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setName(name);
	std::cout << "Constructor(name) for FragTrap Named ["<< this->getName() <<"] called" << std::endl;
}

/*********************member functions***********************/

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap Named "<< this->getName() << " requests a positive high five !!" << std::endl;
}

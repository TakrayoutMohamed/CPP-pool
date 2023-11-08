#include "./ScavTrap.hpp"

/*******Orthodox Canonical Form and a structor takes a string as parameter *******/

/*Default constructor*/
ScavTrap::ScavTrap(/* args */) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_name = "";
	std::cout << "Default constructor for ScavTrap Named ["<< this->getName() <<"] called" << std::endl;
}
/*copy assignement operator*/
const ScavTrap &ScavTrap::operator=(const ScavTrap& obj)
{
	std::cout << "Copy assignement operator to assign ScavTrap Named ["<< obj.getName() \
	<<"] to ScavTrap Named [" << this->getName() <<"]" << std::endl;
	this->setName(obj.getName());
    this->setHitPionts(obj.getHitPoints());
	this->setEnergyPoints(obj.getEnergyPionts());
	this->setAttackDamage(obj.getAttackDamage());
	return (*this);
}
/*copy constructor*/
ScavTrap::ScavTrap(const ScavTrap &obj)
{
	*this = obj;
	std::cout << "Copy constructor for ScavTrap Named ["<< this->getName() <<"] called" << std::endl;
}
/*Destructor*/
ScavTrap::~ScavTrap()
{
	std::cout << "Destructor for ScavTrap Named ["<< this->getName() <<"] called" << std::endl;
}

/*Constructor that takes a string as parameter*/
ScavTrap::ScavTrap(const std::string &name)  : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_name = name;
	std::cout << "Constructor(name) for ScavTrap Named ["<< this->getName() <<"] called" << std::endl;
}

/*********************member functions***********************/

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap Named "<< this->getName() << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (getHitPoints() > 0 && getEnergyPionts() > 0)
	{
		std::cout << "ScaveTrap "<< getName() <<" attacks "<< target <<", causing "<< getAttackDamage()\
		<< " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPionts() - 1);
	}
	else
	{
		if (getHitPoints() <= 0)
			std::cout << "Your hit points are <= 0 , you can't attack ."<< std::endl;
		else
			std::cout << "Your Energie points are <= 0 , you can't attack ."<< std::endl;
	}
}

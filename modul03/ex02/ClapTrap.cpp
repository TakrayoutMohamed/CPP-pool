#include "./ClapTrap.hpp"

/*******Orthodox Canonical Form and a structor takes a string as parameter *******/

/*Default constructor*/
ClapTrap::ClapTrap(/* args */)
{
	this->setHitPionts(10);
	this->setEnergyPoints(10);
	this->setAttackDamage(0);
	this->setName("");
	std::cout << "Default constructor for ClapTrap Named ["<< this->getName() <<"] called" << std::endl;
}
/*copy assignement operator*/
const ClapTrap &ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << "Copy assignement operator to assign ClapTrap Named ["<< obj.getName() \
	<<"] to ClapTrap Named [" << this->getName() <<"]" << std::endl;
	this->_name = obj._name;
	this->_energyPoints = obj._energyPoints;
	this->_hitPoints = obj._hitPoints;
	this->_attackDamage = obj._attackDamage;
	return (*this);
}
/*copy constructor*/
ClapTrap::ClapTrap(const ClapTrap &obj)
{
	*this = obj;
	std::cout << "Copy constructor for ClapTrap Named ["<< this->getName() <<"] called" << std::endl;
}
/*Destructor*/
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor for ClapTrap Named ["<< this->getName() <<"] called" << std::endl;
}

/*Constructor that takes a string as parameter*/
ClapTrap::ClapTrap(const std::string &name)
{
	this->setHitPionts(10);
	this->setEnergyPoints(10);
	this->setAttackDamage(0);
	this->setName(name);
	std::cout << "Constructor(name) for ClapTrap Named ["<< this->getName() <<"] called" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
	// if i have no hitPoints or energyPoints i can not attack 
	// if i attack ,i lost 1 energy point
	//if i attack the claptrap x , x loses me.attackDamage of hitPoints 
		//=>his.hitPoints = his.hitPoints - me.attackDamage
	if (getHitPoints() > 0 && getEnergyPionts() > 0)
	{
		std::cout << "ClapTrap "<< getName() <<" attacks "<< target <<", causing "<< getAttackDamage()\
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
void ClapTrap::takeDamage(unsigned int amount)
{
	// if i have no hitPoints or energyPoints i can not take damage
	// if i have been attacked i take damage of amount => me.hitPoints = me.hitPoints - amount 
	if (getHitPoints() > 0 && getEnergyPionts() > 0)
	{
		std::cout << "ClapTrap "<< getName() <<" has been attacked " << ", causing lose of "<< amount\
		<< " points of damage!" << std::endl;
		setHitPionts(getHitPoints() - amount);
	}
	else
	{
		if (getHitPoints() <= 0)
			std::cout << "Your hit points are <= 0 , you can't take damage ."<< std::endl;
		else
			std::cout << "Your Energie points are <= 0 , you can't take damage ."<< std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	// if i have no hitPoints or energyPoints i can not repair myself
	// if i repair my self i get amount of hitPoints => me.hitPoints = me.hitPoints + amount
	// if i repair my self i lose one energie point => me.energyPoints = me.energiePoints - 1
	if (getHitPoints() > 0 && getEnergyPionts() > 0)
	{
		std::cout << "ClapTrap "<< getName() <<" repaired him self by adding "<< amount \
		<< " of hit points "<< std::endl;
		setEnergyPoints(getEnergyPionts() - 1);
		setHitPionts(getHitPoints() + amount);
	}
	else
	{
		if (getHitPoints() <= 0)
			std::cout << "Your hit points are <= 0 , you can't repair ."<< std::endl;
		else
			std::cout << "Your Energie points are <= 0 , you can't repair ."<< std::endl;
	}
}

/*getters */
const std::string &ClapTrap::getName(void) const
{
	return (this->_name);
}
const int &ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}
const int &ClapTrap::getEnergyPionts(void) const
{
	return (this->_energyPoints);
}
const int &ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

/*setters */
void	ClapTrap::setName(std::string const name)
{
	this->_name = name;
}
void	ClapTrap::setHitPionts(int const hitPoints)
{
	this->_hitPoints = hitPoints;
}
void	ClapTrap::setEnergyPoints(int const energyPoints)
{
	this->_energyPoints = energyPoints;
}
void	ClapTrap::setAttackDamage(int const attackDamage)
{
	this->_attackDamage = attackDamage;
}

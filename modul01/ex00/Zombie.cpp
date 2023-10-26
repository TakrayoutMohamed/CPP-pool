#include "Zombie.hpp"

Zombie::Zombie(/* args */)
{
	std::cout << "Zombie constructor called" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destructor called" << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName(void)
{
	return (this->name);
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

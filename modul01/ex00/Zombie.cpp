#include "Zombie.hpp"

Zombie::Zombie(/* args */)
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destructor called , to destroy the zombie : ";
	std::cout << this->getName() ;
	std::cout << std::endl;
	return ;
}

/*print the name of the zombie followed by a message*/
void	Zombie::announce(void)
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/*getters*/

std::string	Zombie::getName(void)
{
	return (this->name);
}

/*setters*/

void	Zombie::setName(std::string name)
{
	this->name = name;
}

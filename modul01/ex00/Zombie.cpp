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
	if (this->getName().length() <= 0)
		return ;
	std::cout << this->getName();
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
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

#include "./Zombie.hpp"

int	main(void)
{
	Zombie *zombie;
	randomChump("zombie 1");
	zombie = newZombie("Zombie2");
	zombie->announce();
	delete zombie;
	return (0);
}

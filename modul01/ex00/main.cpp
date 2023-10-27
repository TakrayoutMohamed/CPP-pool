#include "./Zombie.hpp"

void foo(void)
{
	system("leaks zombies");
}

int	main(void)
{
	atexit(foo);
	Zombie *zombie;
	randomChump("zombie 1");
	zombie = newZombie("Zombie2");
	zombie->announce();
	delete zombie;
	return (0);
}

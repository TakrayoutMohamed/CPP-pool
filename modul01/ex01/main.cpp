#include "./Zombie.hpp"

// void foo(void)
// {
// 	system("leaks zombieHord");
// }

int	main(void)
{
	// atexit(foo);
	Zombie	*zombies;
	zombies = zombieHorde(4, "zombie11");
	zombies[0].announce();
	zombies[1].announce();
	zombies[2].announce();
	zombies[3].announce();
	delete[] zombies;
	return (0);
}

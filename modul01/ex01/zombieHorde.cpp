#include "./Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	int	i;
	Zombie	*zombies;

	i = 0;
	if (N <= 0)
		return (NULL);
	zombies = new(std::nothrow) Zombie[N];
	if (zombies == NULL)
	{
		std::cout << "Error :memory could not be allocated"<< std::endl;
		return (NULL);
	}
	while (i < N)
	{
		zombies[i].setName(name);
		i++;
	}
	return (zombies);
}

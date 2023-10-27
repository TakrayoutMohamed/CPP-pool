#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class	Zombie
{
	private:
		/* data */
		std::string	name;
	public:
		Zombie(/* args */);
		~Zombie();
		void		announce(void);
		std::string	getName(void);
		void		setName(std::string name);
};
Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif

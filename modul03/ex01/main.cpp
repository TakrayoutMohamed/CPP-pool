#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"

int	main(void)
{
	ClapTrap clapTrap1("ClapTrap1");
	ClapTrap clapTrap2;
	ClapTrap clapTrap3(clapTrap1);

	std::cout << "ssssssssss" << clapTrap3.getName()<< std::endl;
	clapTrap2.setName("ClapTrap2");
	clapTrap1.attack("ClapTrapX");
	clapTrap2.takeDamage(clapTrap1.getAttackDamage());
	return (0);
}
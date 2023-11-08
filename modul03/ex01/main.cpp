#include "./ScavTrap.hpp"

int	main(void)
{
	ClapTrap warrior("Napoleon");
	ScavTrap master("Genkhis khan");
	warrior.attack("Queen");
	master.attack("Soldier");
	std::cout << master.getName() << " EnergyPoints are: " << master.getEnergyPionts() << std::endl;
	master.guardGate();
    return (0);
}
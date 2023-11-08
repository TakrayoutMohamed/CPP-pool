#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

int	main(void)
{
	ClapTrap warrior("Napoleon");
	FragTrap fking("Adolf");
	ScavTrap master("Genkhis khan");
	std::cout << "**********************************"<< std::endl;
	fking.highFivesGuys();
	master.guardGate();
	warrior.attack("Queen");
	master.attack("Soldier");
	std::cout << fking.getName() << " EnergyPoints are: " << fking.getEnergyPionts() << std::endl;
	std::cout << master.getName() << " EnergyPoints are: " << master.getEnergyPionts() << std::endl;
	std::cout << "**********************************"<< std::endl;
    return (0);
}
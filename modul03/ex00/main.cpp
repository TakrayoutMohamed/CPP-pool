#include "./ClapTrap.hpp"

int	main(void)
{
	ClapTrap clapTrap1("ClapTrap1");
    ClapTrap clapTrap2;
    ClapTrap clapTrap3(clapTrap1);

	std::cout << " clapTrap3.name =  " << clapTrap3.getName()<< std::endl;
	clapTrap2.setName("ClapTrap2");
    clapTrap1 = clapTrap2;
    clapTrap1.attack("ClapTrapX");
    clapTrap2.takeDamage(clapTrap1.getAttackDamage());
    return (0);
}
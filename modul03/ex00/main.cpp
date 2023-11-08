#include "./ClapTrap.hpp"

int	main(void)
{
	ClapTrap clapTrap1("ClapTrap1");
    ClapTrap clapTrap3(clapTrap1);

	std::cout << " clapTrap3.name =  " << clapTrap3.getName()<< std::endl;
    clapTrap1.attack("ClapTrapX");
    clapTrap1.takeDamage(21);
    return (0);
}
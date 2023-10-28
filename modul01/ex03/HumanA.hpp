#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		/* data */
		std::string	_name;
		Weapon	&_weapon;
		
	public:
		// HumanA(/* args */);
		HumanA(std::string name, Weapon &weaponName);
		~HumanA();
		void	attack(void);
		std::string getName(void);
		Weapon	&getWeapon(void);
		void 	setName(std::string name);
		void	setWeapon(Weapon &weapon);

};

#endif

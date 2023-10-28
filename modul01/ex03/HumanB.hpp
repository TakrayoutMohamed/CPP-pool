#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "./Weapon.hpp"

class HumanB
{
	private:
		/* data */
		std::string	_name;
		Weapon	* _weapon;
		
	public:
		// HumanB(/* args */);
		HumanB(std::string name);
		~HumanB();
		void	attack(void);
		std::string getName(void);
		void setName(std::string name);
		Weapon& getWeapon(void);
		void setWeapon(Weapon &weaponB);
};

#endif

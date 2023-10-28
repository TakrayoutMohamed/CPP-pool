#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		/* data */
		std::string	name;
		Weapon	weapon;
		
	public:
		HumanA(/* args */);
		~HumanA();

};

#endif

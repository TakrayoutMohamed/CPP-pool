#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "./ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap : public ClapTrap
{
	private:
		/* data */
	public:
		ScavTrap();
		ScavTrap(const ScavTrap&);
		const ScavTrap &operator=(const ScavTrap&);
		~ScavTrap();
		ScavTrap(const std::string &);

		void	guardGate();
		void	attack(const std::string& target);
};

#endif

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "./ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : public ClapTrap
{
	private:
		/* data */
	public:
		FragTrap();
		FragTrap(const FragTrap&);
		const FragTrap &operator=(const FragTrap&);
		~FragTrap();
		FragTrap(const std::string &);

		void	highFivesGuys(void);
};

#endif

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <cstring>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		/*Orthodox canonical form start*/

		ClapTrap();
		ClapTrap(const ClapTrap&);
		const ClapTrap &operator=(const ClapTrap&);
		~ClapTrap();
		/*Orthodox canonical form end*/
		
		ClapTrap(const std::string &);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		/*getters */
		const std::string &getName(void) const;
		const int &getHitPoints(void) const;
		const int &getEnergyPionts(void) const;
		const int &getAttackDamage(void) const;
		/*setters */
		void	setName(std::string const);
		void	setHitPionts(int const);
		void	setEnergyPoints(int const);
		void	setAttackDamage(int const);
};

#endif
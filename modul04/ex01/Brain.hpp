#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
// # include "Animal.hpp"

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain(/* args */);
		Brain(const Brain&);
		const Brain& operator=(const Brain&);
		~Brain();
};

#endif

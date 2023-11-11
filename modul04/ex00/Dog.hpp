#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	private:
		/* data */

	protected:
		/* data */

	public:
		Dog(/* args */);
		Dog(const Dog&);
		const Dog& operator=(const Dog&);
		~Dog();

		void makeSound(void) const;
};
#endif

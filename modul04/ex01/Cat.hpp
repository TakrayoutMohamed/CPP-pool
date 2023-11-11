#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	private:
		/* data */

	protected:
		/* data */

	public:
		Cat(/* args */);
		Cat(const Cat&);
		const Cat& operator=(const Cat&);
		~Cat();

		void makeSound(void) const;
};
#endif

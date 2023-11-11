#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		/* data */

	protected:
		/* data */

	public:
		WrongCat(/* args */);
		WrongCat(const WrongCat&);
		const WrongCat& operator=(const WrongCat&);
		~WrongCat();

		void makeSound(void) const;
};
#endif

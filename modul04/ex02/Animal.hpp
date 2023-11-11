#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
class Animal
{
	private:

	protected:
		std::string type;

	public:
		Animal(/* args */);
		Animal(const Animal&);
		const Animal& operator=(const Animal&);
		virtual ~Animal();
		
		/*getter*/
		virtual std::string getType(void) const;
		virtual void makeSound(void) const = 0;
};
#endif

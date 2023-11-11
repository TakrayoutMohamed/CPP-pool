#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
class WrongAnimal
{
	private:

	protected:
		std::string type;

	public:
		WrongAnimal(/* args */);
		WrongAnimal(const WrongAnimal&);
		const WrongAnimal& operator=(const WrongAnimal&);
		virtual ~WrongAnimal();
		
		/*getter*/
		virtual std::string getType(void) const;
		void makeSound(void) const;
};
#endif

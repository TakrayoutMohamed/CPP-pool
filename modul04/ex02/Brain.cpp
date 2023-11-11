#include "Brain.hpp"

Brain::Brain()
{
	int i;

	i = 0;
	/*fill the ideas array by default values*/
	while (i < 100)
	{
		this->ideas[i] = "IDEA";
		i++;
	}
	std::cout << "Default constructor of the Brain class" << std::endl;
}

Brain::Brain(const Brain& obj)
{
	std::cout << "Copy constructor of the Brain class" << std::endl;
	if (this != &obj)
		*this = obj;
}


const Brain& Brain::operator=(const Brain& obj)
{
	int i;

	std::cout << "Copy assignment operator of the Brain class" << std::endl;
	if (this == &obj)
		return (*this);
	i = 0;
	while (i < 100)
	{
		this->ideas[i] = obj.ideas[i];
		i++;
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Destructor of the Brain class" << std::endl;
}

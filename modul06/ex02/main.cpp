#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int randomNbr;

	srand(time(NULL));
	randomNbr = rand() % 3;
	switch (randomNbr)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C" << std::endl;
	else
		std::cout << "Class unknown" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &classA = dynamic_cast<A&>(p);
		static_cast <void> (classA);
		std::cout << "Class A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B &classB = dynamic_cast<B&>(p);
		static_cast <void> (classB);
		std::cout << "Class B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C &classC = dynamic_cast<C&>(p);
		static_cast <void> (classC);
		std::cout << "Class C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main(void)
{
	Base *pbase = generate();
	identify(pbase);
	return (0);
}

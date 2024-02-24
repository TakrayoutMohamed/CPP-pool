#include "./Span.hpp"
#include <array>
#include <list>
/*push random values to the STL container */
template <typename T>
void pushToContainer(T &stl, const unsigned int nbr)
{
	srand(time(0));
	unsigned int i = 0;
	while (i < nbr)
	{
		stl.push_back(rand() % (nbr * 2));
		i++;
	}

}

int main()
{
	try
	{
		Span sp = Span(30);
		sp.addNumber(3);
		sp.addNumber(6);
		sp.addNumber(9);
		sp.addNumber(17);
		sp.addNumber(11);
		std::list<int> arr;
		pushToContainer<std::list<int> >(arr, 20);
		sp.addManyNumbers<std::list<int>::iterator >(arr.begin(), arr.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
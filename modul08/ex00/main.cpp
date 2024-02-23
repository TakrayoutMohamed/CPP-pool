#include "./easyfind.hpp"
#include <vector>
#include <list>
#include <string>

int main(void)
{
	std::list<int>  data;
	data.push_back(10);
	data.push_back(20);
	data.push_back(30);

	try
	{
		std::cout << " the value to look for is :" << (easyfind<std::list<int> >(data, 10)) << std::endl;
		std::cout << " the value to look for is :" << (easyfind<std::list<int> >(data, 30)) << std::endl;
		std::cout << " the value to look for is :" << (easyfind<std::list<int> >(data, 1)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}

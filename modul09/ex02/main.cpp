#include "./PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error :" << std::endl;
		std::cerr << "Syntax to run the program: " << std::endl;
		std::cerr << "./PmergeMe \"positive numbers\" " << std::endl;
		return (1);
	}
	try
	{
		PmergeMe pm;
		pm.parseData(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cerr << "Exception Error of type : " << e.what() << std::endl;
	}
	return (0);
}
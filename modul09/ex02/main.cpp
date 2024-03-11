#include "./PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error :" << std::endl;
		std::cerr << "Syntax to run the program: " << std::endl;
		std::cerr << "./PmergeMe \"positive numbers\" " << std::endl;
		return (1);
	}
	try
	{
		PmergeMe pm;
		std::string args;
		int i = 1;
		while (i < argc)
		{
			args =  args + " "  + argv[i] + " ";
			i++;
		}
		std::cout << "args = |" << args << "|" << std::endl;
		if (!pm.parseData(args))
			return (1);
		
	}
	catch(std::exception &e)
	{
		std::cerr << "Exception Error of type : " << e.what() << std::endl;
	}
	return (0);
}
#include "./ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error : " << std::endl;
		std::cout << "Number of arguments not acceptable \nExemple " << std::endl;
		std::cout << "\t\t ./convert 44" << std::endl;
		return (1);
	}
	ScalarConverter converter;
	converter.convert((std::string)argv[1]);
	return (0);
}
#include "./File.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error : ";
		std::cout << "./no_sed filePath/fileName word new_word"<< std::endl;
		return (EXIT_FAILURE);
	}
	return (0);
}
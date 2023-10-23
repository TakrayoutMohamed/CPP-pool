#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	int		j;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (std::islower(argv[i][j]))
				std::cout << char(std::toupper(argv[i][j]));
			else
				std::cout << argv[i][j];
			j++;
		}
	}
	std::cout << std::endl;
	return (0);
}

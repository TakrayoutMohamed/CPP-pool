#include "./BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error : " << std::endl;
		std::cerr << "the number of args not compatible : " << std::endl;
		std::cerr << "Exemple : ./btc filename" << std::endl;
		return (1);
	}
	BitcoinExchange bitcoin;
	bitcoin.bitcoinExchange(argv[1]);
	return (0);
}
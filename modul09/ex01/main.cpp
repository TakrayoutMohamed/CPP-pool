#include "./RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error : " << std::endl;
		std::cerr << "the number of args not compatible : " << std::endl;
		std::cerr << "Exemple : ./RPN arg" << std::endl;
		return (1);
	}
	RPN rpn;
	rpn.reversePolishNotation(argv[1]);
	return (0);
}
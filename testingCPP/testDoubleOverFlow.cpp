#include <sstream>
#include <string>
#include <iostream>

bool isOverflowDouble(const std::string &str1, double nbrd)
{
	int	i;

	i = 0;
	std::cout << "the nbrd is : " << nbrd << std::endl;
	(void)str1;
	std::stringstream tostring ;
	std::string resultstr  ;
	tostring << nbrd;
	resultstr = tostring.str();
	std::cout << "the result is : " << resultstr << std::endl;
	return (false);
	// if ((str[i] == '-' && nbrd > 0) || (str[i] == '+' && nbrd < 0))
	// 	return (true);
	// if (str[i] == '-' || str[i] == '+')
	// 	i++;
	// while (str[i] == '0')
	// 	i++;
	// while (str[i] != '\0')
	// {

	// 	i++;
	// }
}

int main(void)
{
    return (0);
}
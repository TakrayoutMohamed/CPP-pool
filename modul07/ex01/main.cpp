#include "./iter.hpp"

template<typename J>
void printMember(J &member)
{
	std::cout << member << std::endl;
}

void toUpper(std::string &member)
{
	for (size_t i = 0; i < member.size(); i++)
	{
		member[i] = toupper(static_cast<int>(member[i]));
	}
}

template void printMember<int> (int &nbr);
template void printMember<std::string>(std::string &str);

void updatePlusOne(int &nbr)
{
	nbr++;
}

int main(void)
{
	try
	{
		std::cout <<"'''''''''''int case'''''''''" << std::endl;
		int array[] = {2, 5,1};
		std::cout << "************* befor updatePlusOne ************" << std::endl;
		iter<int>(array, 3, printMember<int>);
		iter<int>(array, 3, updatePlusOne);
		std::cout << "************* after updatePlusOne ************" << std::endl;
		iter<int>(array, 3, printMember<int>);


		std::cout <<"'''''''''''string case'''''''''" << std::endl;
		std::string arrayString[] = {"alvares", "negredo", "eleven"};
		std::cout << "************* befor toUpper ************" << std::endl;
		iter<std::string>(arrayString, 3, printMember<std::string>);
		iter<std::string>(arrayString, 3, toUpper);
		std::cout << "************* after toUpper ************" << std::endl;
		iter<std::string>(arrayString, 3, printMember<std::string>);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "'\n'";
	}
	
	return (0);
}

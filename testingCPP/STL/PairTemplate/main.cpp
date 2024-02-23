#include <iostream>

int main(void)
{
	std::pair<int, int> pair1, pair3;
	std::pair<int ,std::string> pair2;
	
	pair1 = std::make_pair(1, 2); //insert 1 and 2 to pair1
	pair2 = std::make_pair(1, "Student1337");
	pair3 = std::make_pair(2, 4);
	std::cout << "pair1.first : " << pair1.first << std::endl;
	std::cout << "pair2.second : "<< pair2.second << std::endl;
	
	if (pair1 == pair3)
		std::cout << "pair1 equals pair3" << std::endl;
	else
		std::cout << "pair1 not equal pair3" << std::endl;
	return (0);
}

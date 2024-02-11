#include <iostream>
#include <string>

int main(void)
{
	std::string name = "alvares";
	std::string name2= "alvares";

	std::cout << "name = " << name << " with address " << &name << std::endl;
	std::cout << "name2 = " << name2 << " with address " << &name2 << std::endl;
	
	std::string name3 =  "iiiiiiik";
	name2 = "hhhhh";
	std::cout << "name2 = " << name2 << " with address " << &name2 << std::endl;

	return (0);
}

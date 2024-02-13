#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

int main(void)
{

	const int	a(1);

	int& holder = (const_cast<int&>(a) = const_cast<int&>(a) + 90);

	holder = 9;

	std::cout << holder << ' ' << a << std::endl;
	std::cout << &holder << ' ' << &a;
	return (0);
}

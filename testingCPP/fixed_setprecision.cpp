// modify precision
#include <iostream>     // std::cout, std::ios
#include <iomanip>

int main ()
{
	double f = 3.14159;
	// std::cout.unsetf ( std::ios::floatfield );                // floatfield not set
	std::cout << std::setprecision(5);
	std::cout <<"first precision = 5 "<< f << '\n';
	std::cout.precision(10);
	std::cout <<"first precision = 10 "<< f << '\n';
	// std::cout.setf( std::ios::fixed, std:: ios::floatfield ); // floatfield set to fixed
	std::cout << f << '\n';
	return 0;
}
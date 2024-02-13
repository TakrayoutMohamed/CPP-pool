#include <iostream>

int main(void)
{
	int a = 16;
	char c = 'a';
	float f = 4.77f;

	/*******************************************************************************************/
	int  b = static_cast<int>(f);
	std::cout << " cast from float f: " << f << " to int with static_cast  : " << b << std::endl;
	float ff = static_cast<float>(b);
	std::cout << " cast from int b: " << b << " to float with static_cast  : " << ff << std::endl;
	int bb = f;
	std::cout << " cast from float f: " << f << " to int without static cast  : " << bb << std::endl;
	float FF = b;
	std::cout << " cast from int b: " << b << " to float without static_cast  : " << FF << std::endl;
	/*******************************************************************************************/
	// int castedCharToInt1 = (int) c;
	// int castedCharToInt2 = static_cast <int> (c);
	// std::cout << "cast char 'a' to int using convertion by assignment : " << castedCharToInt1 << std::endl;
	// std::cout << "cast char 'a' to int using unary operator static_cast : " << castedCharToInt2 << std::endl;
	/*******************************************************************************************/
	// int *pointerToInt1 = (int *) &c;
	// int *pointerToInt2 = static_cast<int *> (&c);//error: static_cast from 'char *' to 'int *' is not allowed
	// std::cout << "pointer to int 1  : "<< *pointerToInt1 << std::endl;
	// std::cout << "pointer to int 2  : "<< *pointerToInt2 << std::endl;
	/*******************************************************************************************/
	// int *pointerToInt1 = (int *) &c;
	// int *pointerToInt2 = static_cast<int *> (&f);//error: static_cast from 'char *' to 'int *' is not allowed
	// std::cout << "pointer to int 1  : "<< *pointerToInt1 << std::endl;
	// std::cout << "pointer to int 2  : "<< *pointerToInt2 << std::endl;
	/*******************************************************************************************/
	// const int x(5);
	// int& ref =  static_cast<int&>(x) ; // error: binding reference of type 'int' to value of type 'const int' drops 'const' qualifier
	// ref = 6;
	/*******************************************************************************************/
	// std::cout << "int a : "<< a << std::endl;
	return (0);
}

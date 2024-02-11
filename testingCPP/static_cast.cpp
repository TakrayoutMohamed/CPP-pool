#include <iostream>

int main(void)
{
	int a = 16;
	char c = 'a';
	float f = 4.77;

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
	int *pointerToInt1 = (int *) &c;
	int *pointerToInt2 = static_cast<int *> (&f);//error: static_cast from 'char *' to 'int *' is not allowed
	std::cout << "pointer to int 1  : "<< *pointerToInt1 << std::endl;
	std::cout << "pointer to int 2  : "<< *pointerToInt2 << std::endl;
	/*******************************************************************************************/

	// std::cout << "int a : "<< a << std::endl;
	return (0);
}


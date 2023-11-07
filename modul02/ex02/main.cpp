#include "./Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed c(2.3f);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	
	std::cout << "a = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;


	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;

	std::cout << b <<" - " << c << " = " << b - c << std::endl;

	std::cout << b <<" + " << c << " = " << b + c << std::endl;

	std::cout << b <<" * " << c << " = " << b * c << std::endl;

	std::cout << b <<" / " << c << " = " << b / c << std::endl;
	
	// Fixed e(0);
	// std::cout << b <<" / " << e << " = " << b / e << std::endl;


	std::cout << Fixed::max( c, a ) << std::endl;
	std::cout << Fixed::max( (const Fixed)c, (const Fixed)a ) << std::endl;
	std::cout << Fixed::min( c, a ) << std::endl;
	std::cout << Fixed::min( (const Fixed)c, (const Fixed)a ) << std::endl;
	// std::cout << Fixed::min( a, b ) << std::endl;
	// std::cout << Fixed::min( a, b ) << std::endl;
	return 0;
}

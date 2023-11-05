#include "./Fixed.hpp"

const int Fixed::nbrFractional = 8;

Fixed::Fixed(/* args */)
{
	this->fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor was called" << std::endl;
}

/*here is the copy constructor*/
Fixed::Fixed(Fixed& copyObj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copyObj;
}

/*here is the overloading operator assignment*/
Fixed   &Fixed::operator= (Fixed& fxd)
{
	std::cout << "Copy assignment operator called"<< std::endl;
	this->fixedPoint = fxd.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPoint);
}

void    Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}

#include "./Fixed.hpp"

Fixed::Fixed(/* args */)
{
	this->fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

/*here is the copy constructor*/
Fixed::Fixed(const Fixed& copyObj)
{
	std::cout << "Copy constructor called" << std::endl;
	if (&copyObj == this)
		return ;
	*this = copyObj;
}

Fixed::Fixed(const int intNbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = intNbr << this->nbrFractional;
}

Fixed::Fixed(const float floatNbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(floatNbr * (1 << this->nbrFractional));
}

Fixed::~Fixed()
{
	std::cout << "Destructor was called" << std::endl;
}

/*here is the overloading operators*/

Fixed   &Fixed::operator= (const Fixed& fxd)
{
	std::cout << "Copy assignment operator called"<< std::endl;
	this->fixedPoint = fxd.fixedPoint;
	return (*this);
}

Fixed   &Fixed::operator+ (const Fixed& fxd)
{
	float temp;
	std::cout << "plus assignment operator called"<< std::endl;
	// this->fixedPoint = this->fixedPoint + fxd.fixedPoint;
	temp = this->toFloat() + fxd.toFloat();
	this->fixedPoint = roundf(temp * (1 << this->nbrFractional));
	return (*this);
}

Fixed   &Fixed::operator- (const Fixed& fxd)
{
	float	temp;
	std::cout << "minus assignment operator called"<< std::endl;
	temp = this->toFloat() - fxd.toFloat();
	this->fixedPoint = roundf(temp * (1 << this->nbrFractional));
	return (*this);
}

Fixed   &Fixed::operator/ (const Fixed& fxd)
{
	float	temp;
	std::cout << "substruction assignment operator called"<< std::endl;
	if (!fxd.fixedPoint)
		exit (EXIT_FAILURE);
	temp = this->toFloat() / fxd.toFloat();
	this->fixedPoint = roundf(temp * (1 << this->nbrFractional));
	return (*this);
}

Fixed   &Fixed::operator* (const Fixed& fxd)
{
	float	temp;
	std::cout << "multiplication assignment operator called"<< std::endl;
	temp = this->toFloat() * fxd.toFloat();
	this->fixedPoint = roundf(temp * (1 << this->nbrFractional));
	return (*this);
}

float	Fixed::toFloat(void) const
{
	return (float(this->fixedPoint) / (float)(1 << this->nbrFractional));
}

int	Fixed::toInt(void) const
{
	return (int(this->fixedPoint / (1 << this->nbrFractional)));
}

/*here overloading the output stream*/
std::ostream	&operator<< (std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

#include "./Fixed.hpp"

Fixed::Fixed(/* args */)
{
	this->fixedPoint = 0;
}

/*here is the copy constructor*/
Fixed::Fixed(const Fixed& copyObj)
{
	if (&copyObj == this)
		return ;
	*this = copyObj;
}

Fixed::Fixed(const int intNbr)
{
	this->fixedPoint = intNbr << this->nbrFractional;
}

Fixed::Fixed(const float floatNbr)
{
	this->fixedPoint = roundf(floatNbr * (1 << this->nbrFractional));
}

Fixed::~Fixed()
{
}

/*here are overloading  arithmetic operators: = + - / * */

Fixed   &Fixed::operator= (const Fixed& fxd)
{
	this->fixedPoint = fxd.fixedPoint;
	return (*this);
}

Fixed   Fixed::operator+ (const Fixed& fxd)
{
	float temp;
	temp = this->toFloat() + fxd.toFloat();
	return (Fixed(temp));
}

Fixed   Fixed::operator- (const Fixed& fxd)
{
	float	temp;
	temp = this->toFloat() - fxd.toFloat();
	return (Fixed(temp));
}

Fixed   Fixed::operator/ (const Fixed& fxd)
{
	float	temp;
	if (!fxd.fixedPoint)
		exit (EXIT_FAILURE);
	temp = this->toFloat() / fxd.toFloat();
	return (Fixed(temp));
}

Fixed   Fixed::operator* (const Fixed& fxd)
{
	float	temp;
	temp = this->toFloat() * fxd.toFloat();
	return (Fixed(temp));
}

/*here are overloading  increment/decrement operators a++ ++a a-- --a */

/*overloading increment operator a++*/
Fixed   Fixed::operator++ (int)
{
	Fixed temp(this->toFloat());
	this->fixedPoint++;
	return (temp);
}

/*overloading increment operator ++a*/
Fixed   Fixed::operator++ (void)
{
	++this->fixedPoint;
	return (*this);
}

/*overloading decrement operator a--*/
Fixed   Fixed::operator-- (int)
{
	Fixed temp(this->toFloat());

	this->fixedPoint--;
	return (temp);
}

/*overloading decrement operator --a*/
Fixed   Fixed::operator-- (void)
{
	--this->fixedPoint;
	return (*this);
}

/*here are overloading  comparison operators > >= < <= == != */

bool	Fixed::operator> (const Fixed& fxd)
{
	return (this->toFloat() > fxd.toFloat());
}

bool	Fixed::operator>= (const Fixed& fxd)
{
	return (this->toFloat() >= fxd.toFloat());
}

bool	Fixed::operator< (const Fixed& fxd)
{
	return (this->toFloat() < fxd.toFloat());
}

bool	Fixed::operator<= (const Fixed& fxd)
{
	return (this->toFloat() <= fxd.toFloat());
}

bool	Fixed::operator== (const Fixed& fxd)
{
	return (this->toFloat() == fxd.toFloat());
}

bool	Fixed::operator!= (const Fixed& fxd)
{
	return (this->toFloat() != fxd.toFloat());
}

/*here are overloading  member functions
*	min(const Fixed, const Fixed)  min(Fixed, Fixed) 
*	min(const Fixed, const Fixed)  min(Fixed, Fixed) 
*/

Fixed	&Fixed::min(Fixed& fxd1, Fixed& fxd2)
{
	return ((fxd1 < fxd2) ? (Fixed &)fxd1 : (Fixed &)fxd2);
}

Fixed	&Fixed::min(const Fixed& fxd1, const Fixed& fxd2)
{
	return (((Fixed)fxd1 < (Fixed)fxd2) ? (Fixed &)fxd1 : (Fixed &)fxd2);
}

Fixed	&Fixed::max(Fixed& fxd1,Fixed& fxd2)
{
	return ((fxd1 < fxd2) ? (Fixed &)fxd2 : (Fixed &)fxd1);
}

Fixed	&Fixed::max(const Fixed& fxd1, const Fixed& fxd2)
{
	return (((Fixed)fxd1 < (Fixed)fxd2) ? (Fixed &)fxd2 : (Fixed &)fxd1);
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

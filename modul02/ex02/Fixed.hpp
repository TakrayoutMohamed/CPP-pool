#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <fstream>
#include <cmath>
class Fixed
{
	private:
		int					fixedPoint;
		static const	int	nbrFractional = 8;
	public:
		Fixed(/* args */);
		~Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed&);
		Fixed	&operator= (const Fixed&);
		Fixed	&operator+ (const Fixed&);
		Fixed	&operator- (const Fixed&);
		Fixed	&operator/ (const Fixed&);
		Fixed	&operator* (const Fixed&);
		float	toFloat(void) const;
		int		toInt(void) const;
};
std::ostream	&operator<< (std::ostream&,const Fixed&);

#endif

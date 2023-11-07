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
		Fixed	operator+ (const Fixed&) const;
		Fixed	operator- (const Fixed&) const;
		Fixed	operator/ (const Fixed&) const;
		Fixed	operator* (const Fixed&) const;
		Fixed	operator++ (int);
		Fixed	operator++ (void);
		Fixed	operator-- (int);
		Fixed	operator-- (void);
		bool	operator> (const Fixed&);
		bool	operator>= (const Fixed&);
		bool	operator< (const Fixed&);
		bool	operator<= (const Fixed&);
		bool	operator== (const Fixed&);
		bool	operator!= (const Fixed&);
		static Fixed	&min(const Fixed&, const Fixed&);
		static Fixed	&min(Fixed&, Fixed&);
		static Fixed	&max(const Fixed&, const Fixed&);
		static Fixed	&max(Fixed&, Fixed&);
		float	toFloat(void) const;
		int		toInt(void) const;
};
std::ostream	&operator<< (std::ostream&,const Fixed&);

#endif

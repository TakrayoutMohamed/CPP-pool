#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
	private:
		int					fixedPoint;
		static const	int	nbrFractional;
	public:
		Fixed(/* args */);
		~Fixed();
		Fixed(Fixed& rv); 
		Fixed	&operator= (Fixed&);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif

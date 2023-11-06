#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
	private:
		int					fixedPoint;
		static const	int	nbrFractional = 8;
	public:
		Fixed(/* args */);
		~Fixed();
		Fixed(Fixed&); 
		Fixed	&operator= (Fixed&);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif

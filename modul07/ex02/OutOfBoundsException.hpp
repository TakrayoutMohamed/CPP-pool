#ifndef OUTOFBOUNDSEXCEPTION_HPP
# define OUTOFBOUNDSEXCEPTION_HPP
# include <exception>
# include <iostream>
class OutOfBoundsException : public std::exception
{
	private:
		/* data */
	public:
		virtual const char *what() const throw();
};

#endif

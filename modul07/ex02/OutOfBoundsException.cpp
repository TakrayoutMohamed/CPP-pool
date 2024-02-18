#include "./OutOfBoundsException.hpp"

const char *OutOfBoundsException::what() const throw()
{
	return "OutOfBoundsException";
}

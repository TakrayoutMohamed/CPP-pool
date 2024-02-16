#include "./NullException.hpp"

const char *NullException::what() const throw()
{
    return ("Null pointer has been Detected");
}

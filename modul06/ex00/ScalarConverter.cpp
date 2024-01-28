#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor for ScalarConverter has been called "<< std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{

    std::cout << "Copy constructor for ScalarConverter has been called "<< std::endl;
    if (this != &obj)
        *this = obj;
}

const ScalarConverter &ScalarConverter::operator=(const ScalarConverter& obj)
{
    std::cout << "Copy assignment operator for ScalarConverter has been called "<< std::endl;
    if (this != &obj)
    {
        this->_char = obj._char;
        this->_int = obj._int;
        this->_float = obj._float;
        this->_double = obj._double;
    }
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor for ScalarConverter has been called "<< std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    //check the type of the 
    std::cout << str << std::endl;
}
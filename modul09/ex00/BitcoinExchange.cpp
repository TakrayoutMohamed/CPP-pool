#include "./BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(/* args */)
{
    std::cout << "Default constructor BitcoinExchange" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
    std::cout << "Copy constructor BitcoinExchange" << std::endl;
    if (this != &obj)
    {
        *this = obj;
    }
}

const BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    std::cout << "copy assignment operator BitcoinExchange" << std::endl;
    if (this != &obj)
    {
        this->_data = obj.data;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}
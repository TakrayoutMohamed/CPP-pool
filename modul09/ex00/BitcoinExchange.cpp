#include "./BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
    if (this != &obj)
    {
        *this = obj;
    }
}

const BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if (this != &obj)
    {

    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}
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

/*************************************member functions start here **************************************/
void	BitcoinExchange::openFile(const char *file)
{
    this->_currentFile.open(file);
    if (!is_open(_currentFile))
        throw CouldNotOpenFileException;
}

const std::string	&BitcoinExchange::readline(char delim)
{
    return (std::getline(_currentFile, this->line, delim));
}

/*if the first line not "date | value" return false*/
bool    BitcoinExchange::checkFirstLine(const std::string &firstLine) const
{
    return (!str.compare("date | value"));
}

/*to help for the checkOtherLines function : checking the format of the value is it valid*/
bool isValidValueFormat(const std::string &lineData, int &index)
{
    if (lineData[index] == '+' || lineData[index] == '-')
        index++;
    while (is_digit(static_cast<int> (lineData[index])))
        index++;
    if (lineData[index] != '\0' && !is_space(static_cast<int> (lineData[index])))
        return (false)
    return (true);
}

bool isValidDateFormat(std::string const lineData, int &index)
{
    int j;

    j = 0;
    while (lineData[index] != '\0' && !is_space(static_cast<int> (lineData[index])))
    {
        if (j == 10)
            break;
        if (j != 3 && j != 6)
        {
            if (is_diget(static_cast<int>(lineData[index])) == false)
                return (false);
        }
        else if (lineData[index] != '-')
            return (false);
        index++;
        j++;
    }
    if (!is_space(static_cast<int> (lineData[index])) && lineData[index] != '|')
        return (false);
    return (true);
}

void skipSpaces(const std::string &lineData, int &index)
{
    while (is_space(static_cast<int> (lineData[index])))
        index++;
}

/*if it respect the form of a date ([0-9]{4}(-[0-9]{2}){2}  | {0-9}+) return true else return false*/
bool	BitcoinExchange::checkOtherLines(const std::string &lineData) const
{
    int index;

    index = 0;
    skipSpaces(lineData, index);
    if (!isValidDateFormat(lineData, index))
        return (false);
    skipSpaces(lineData, index);
    if (lineData[index] != '|')
        return (false);
    else
        index++;
    if (!isValidValueFormat(lineData, index))
        return (false);
    skipSpaces(lineData, index);
    if (lineData[index] != '\0')
        return (false);
    return (true);
}

std::istringstream	&BitcoinExchange::pushLineToStream(const std::string &line)
{
    return (this->_stringStream.str(line));
}

void    BitcoinExchange::spliteLineByPipe()
{
    std::getline(this->_stringStream, this->_date, '|');
    {
        //check is the date values good by checking is the year makes sense 
        // check is the month makes since 
        // check is the day makes sense

    }
    std::getline(this->_stringStream, this->_exchangeValue, '|');
    {
        //check is the value makes sense means is it positive , is it less than 1000
    }
}
/***************************************member functions ends here***************************************/
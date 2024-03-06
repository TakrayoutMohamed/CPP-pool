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
		this->_database = obj._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Destructor BitcoinExchange" << std::endl;
}
/************************************start exceptions**********************************/
const char *BitcoinExchange::CouldNotOpenFileException::what() const throw()
{
	return ("CouldNotOpenFileException");
}

const char *BitcoinExchange::CouldNotOpenDatabaseException::what() const throw()
{
	return ("CouldNotOpenDatabaseException");
}
/************************************end exceptions************************************/
/*************************************member functions start here **************************************/
void	BitcoinExchange::openFile(const char *file)
{
	this->_currentFile.open(file);
	if (!_currentFile.is_open())
		throw CouldNotOpenFileException;
}

const std::string	&BitcoinExchange::readLine(char delim)
{
	std::getline(_currentFile, this->_line, delim);
	return (this->_line);
}

/*if the first line not "date | value" return false*/
bool    BitcoinExchange::checkFirstLine(const std::string &firstLine) const
{
	return (!firstLine.compare("date | value"));
}

/*to help for the checkOtherLines function : checking the format of the value is it valid*/
bool isValidValueFormat(const std::string &lineData, int &index)
{
	if (lineData[index] == '+' || lineData[index] == '-')
		index++;
	if (!isdigit(static_cast<int> (lineData[index])))
		return (false);
	while (isdigit(static_cast<int> (lineData[index])))
		index++;
	if (lineData[index] == '.' && isdigit(static_cast<int> (lineData[index + 1])))
		index++;
	while (isdigit(static_cast<int> (lineData[index])))
		index++;
	if (lineData[index] != '\0' && !isspace(static_cast<int> (lineData[index])))
		return (false);
	return (true);
}

bool isValidDateFormat(std::string const lineData, int &index)
{
	int j;

	j = 0;
	while (lineData[index] != '\0' && !isspace(static_cast<int> (lineData[index])))
	{
		if (j != 4 && j != 7)
		{
			if (isdigit(static_cast<int>(lineData[index])) == false)
				return (false);
		}
		else if (lineData[index] != '-')
			return (false);
		index++;
		j++;
		if (j == 10)
			break;
	}
	if (!isspace(static_cast<int> (lineData[index])) && lineData[index] != '|')
		return (false);
	return (true);
}

void skipSpaces(const std::string &lineData, int &index)
{
	while (isspace(static_cast<int> (lineData[index])))
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
	skipSpaces(lineData, index);
	if (!isValidValueFormat(lineData, index))
		return (false);
	skipSpaces(lineData, index);
	if (lineData[index] != '\0')
		return (false);
	return (true);
}

std::istringstream	&BitcoinExchange::pushLineToStream(const std::string &line)
{
	this->_istringStream.clear();
	this->_istringStream.str("");
	this->_istringStream.str(line);
	return (this->_istringStream);
}

void    BitcoinExchange::spliteLineToDateExchangeRate()
{
	pushLineToStream(_line);
	std::getline(this->_istringStream, this->_date, '|');
	{
		std::cout << "date : [" << _date << "]" ;
		//check is the date values good by checking is the year makes sense 
		// check is the month makes since 
		// check is the day makes sense

	}
	std::getline(this->_istringStream, this->_exchangeValue, '|');
	{
		std::cout << "[" << _exchangeValue << "]" << std::endl;
		//check is the value makes sense means is it positive , is it less than 1000
	}
}

// bool	isBissextileYear(int year)
// {
// 	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
// }

bool	isValidMonthDay(int year, int month, int day)
{
	std::tm tm;
	std::time_t t;
	const std::time_t now = std::time(NULL);
	const std::tm* localTime = std::localtime(&now);

	if (localTime->tm_year + 1900 == year)
	{
		if (month > localTime->tm_mon + 1)
			return (false);
		if(month == localTime->tm_mon + 1 && day > localTime->tm_mday)
			return (false);
	}
	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;
	t = std::mktime(&tm);
	std::tm local = *std::localtime(&t);
	if (local.tm_year != year - 1900)
		return (false);
	if (local.tm_mon != month - 1)
		return (false);
	if (local.tm_mday != day)
		return (false);
	return (true);
}

bool	isValidYear(int year)
{
	const std::time_t now = std::time(NULL);
	const std::tm* localTime = std::localtime(&now);
	return (year <= localTime->tm_year + 1900);
}

bool	BitcoinExchange::checkIsDateValid()
{
	int year;
	int month;
	int day;

	std::string tmp = this->_date;
	std::stringstream dateStringStream;
	dateStringStream << tmp;
	std::getline(dateStringStream, tmp, '-');
	std::stringstream(tmp) >> year;
	std::getline(dateStringStream, tmp, '-');
	std::stringstream(tmp) >> month;
	std::getline(dateStringStream, tmp, '-');
	std::stringstream(tmp) >> day;
	if (!isValidYear(year))
	{
		std::cout << "********Not valid year : " << year << std::endl;
		return (false);
	}
	if (!isValidMonthDay(year, month, day))
	{
		std::cout << "*******Not valid month :" << month << " Not valid day :" <<  day << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::checkIsExchangeValid() const
{
	float	exchangeRate;

	std::stringstream exchangeStringStream;
	exchangeStringStream << this->_exchangeValue;
	exchangeStringStream >> exchangeRate;
	if (exchangeStringStream.fail())
	{
		std::cout << "##################### Not valid nbr exchange rate = " << exchangeRate << " exchangeValue :" << _exchangeValue << std::endl;
		return (false);
	}
	if (exchangeRate < 0)
	{
		std::cout << "##################### Negativ exchange rate = " << exchangeRate << std::endl;
		return (false);
	}
	if (exchangeRate > 1000)
	{
		std::cout << "##################### Big exchange rate = " << exchangeRate << std::endl;
		return (false);
	}
	return (true);
}

float convertStringToFloat(const std::string &str)
{
	std::stringstream ss;
	ss << str;
	float nbr;
	ss >> nbr;
	return (nbr);
}

void				BitcoinExchange::storeDatabaseData(const std::string &databaseFile)
{
	std::ifstream database;
	std::string data;
	std::string key;
	std::string value;
	database.open(databaseFile);
	if (!database.is_open())
		throw CouldNotOpenDatabaseException;
	database >> data;
	while (database >> data)
	{
		std::stringstream sstreamLine;
		sstreamLine << data;
		std::getline(sstreamLine, key, ',');
		std::getline(sstreamLine, value, ',');
		// std::cout << "key = |" << key << "| value = |" << value << "|" << std::endl;
		this->_database[key] = convertStringToFloat(value);
		// std::cout << "key = |" << this->_database[key] << "| value = |" << "" << "|" << std::endl;
	}
	database.close();
	// std::cout << "the size of the data base is :" << _database.size() << std::endl;
}
/***************************************member functions ends here***************************************/

void printMap(const std::map<std::string, float> data)
{
	for (std::map<std::string, float>::const_iterator it = data.begin(); it != data.end(); ++it)
		std::cout <<"key = |" <<  it->first << "| value = |" << it->second << "|; " << std::endl;
}

void	removeSpacesFromString(std::string &str)
{
	while (std::find(str.begin(), str.end(), ' ') != str.end())
	{
		str.erase(std::find(str.begin(), str.end(), ' '));
	}
}

void BitcoinExchange::testAllFunctions(const char *arg)
{
	try
	{
		storeDatabaseData("data.csv");
		openFile(arg);
		std::string line;
		line = readLine('\n');
		if (!checkFirstLine(line))
		{
			std::cout << "the first line should be : date | value" << std::endl;
			return ;
		}
		std::cout << line << std::endl;
		while (std::getline(_currentFile, this->_line, '\n'))
		{
			// std::cout << "the return of check other lines :" << checkOtherLines(_line) << std::endl;
			if (!checkOtherLines(_line))
			{
				std::cout << "the other lines should be {yyyy-mm-dd | value} ";
			}
			std::cout << _line << std::endl;
			spliteLineToDateExchangeRate();
			checkIsDateValid();
			checkIsExchangeValid();
			std::cout << "date: |" << _date << "|" << std::endl;
			removeSpacesFromString(_date);
			std::cout << "date: |" << _date << "|" << std::endl;
		}
	} 
	catch(std::exception &e)
	{
		std::cerr << " Error occurred : " << e.what() << std::endl;
	}
	if (this->_currentFile.is_open())
		this->_currentFile.close();
}
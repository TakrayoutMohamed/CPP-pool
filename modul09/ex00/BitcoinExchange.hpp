#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <cstdlib>
# include <map>
# include <exception>
# include <ctime>

class BitcoinExchange
{
	private:

		std::ifstream												_currentFile;
		std::string 												_line;
		std::map<std::string, float, std::greater<std::string> >	_database;
		std::string													_date;
		std::string													_exchangeValue;
		std::istringstream											_istringStream;
		BitcoinExchange(const BitcoinExchange &obj);
		const BitcoinExchange &operator=(const BitcoinExchange &obj);
	public:
		BitcoinExchange(/* args */);
		~BitcoinExchange();
		/************************************start exceptions**********************************/
		class CouldNotOpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		}CouldNotOpenFileException;
		
		class CouldNotOpenDatabaseException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		}CouldNotOpenDatabaseException;
		/************************************end exceptions************************************/

	private :/*member function*/
		void				openFile(const char *file);
		const std::string	&readLine(char delim);
		// if first line return false the programe should quite
		bool				checkFirstLine(const std::string &firstLine) const;
		// if return false set to the string "Error bad input"
		bool				checkOtherLines(const std::string &lineData) const;
		std::istringstream	&pushLineToStream(const std::string &line);
		void				spliteLineToDateExchangeRate();
		bool				checkIsDateValid();
		bool				checkIsExchangeValid() const;
		void				storeDatabaseData(const std::string &databaseFile);

	public : /*member functions*/
		void bitcoinExchange(const char *);

		
};

#endif

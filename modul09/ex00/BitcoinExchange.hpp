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
// # include <pair>

class BitcoinExchange
{
	private:

		std::ifstream								_currentFile; //stream to read from the file
		std::string 								_line; //used to store the data extracted by getline 
		std::map<std::string, float, std::less<std::string> >	_database; // the data from the database will be stored here as pair (string , int)
		std::string									_date;
		std::string									_exchangeValue;
		std::istringstream							_istringStream;
	public:
		BitcoinExchange(/* args */);
		BitcoinExchange(const BitcoinExchange &obj);
		const BitcoinExchange &operator=(const BitcoinExchange &obj);
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
		void testAllFunctions(const char *);

		
};

#endif

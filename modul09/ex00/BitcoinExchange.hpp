#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <string>
// # include <istringstream>
# include <sstream>
# include <algorithm>
# include <cstdlib>
# include <queue>
// # include <pair>

class BitcoinExchange
{
	private:

		std::fstream								_currentFile; //stream to read from the file
		std::string 								_line; //used to store the data extracted by getline 
		std::queue<std::pair<std::string, int> >	_data; // the data from the file will be stored here as pair (string , int)
		std::string									_date;
		std::string									_exchangeValue;
		std::istringstream							_stringStream;
	public:
		BitcoinExchange(/* args */);
		BitcoinExchange(const BitcoinExchange &obj);
		const BitcoinExchange &operator=(const BitcoinExchange &obj);
		~BitcoinExchange();

	private :/*member function*/
		void				openFile(const char *file);
		const std::string	&readline(char delim);
		// if first line return false the programe should quite
		bool				checkFirstLine(const std::string &firstLine) const;
		// if return false set to the string "Error bad input"
		bool				checkOtherLines(const std::string &lineData) const;
		std::istringstream	&pushLineToStream(const std::string &line);
		void				spliteLineByPipe();



		
};

#endif

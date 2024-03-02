#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <algorithm>
# include <queue>
# include <pair>

class BitcoinExchange
{
	private:

		std::ostream								currentFile; //stream to read from the file
		std::string 								line; //used to store the data extracted by getline 
		std::queue<std::pair<std::string, int> >	_data; // the data from the file will be stored here as pair (string , int)
	public:
		BitcoinExchange(/* args */);
		BitcoinExchange(const BitcoinExchange &obj);
		const BitcoinExchange &operator=(const BitcoinExchange &obj);
		~BitcoinExchange();

	private :/*member function*/
		void				openFile(const char *file);
		const std::string	&readline();
		bool				checkFirstLine() const;
		

		
};

#endif

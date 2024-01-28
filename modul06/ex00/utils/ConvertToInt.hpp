#ifndef CONVERTTOINT_HPP
# define CONVERTTOINT_HPP
# include <iostream>
# include <string>

class ConvertToInt
{
	private:
		/* data */
		ConvertToInt(/* args */);
	public:
		ConvertToInt(const std::string &str);
		ConvertToInt(const ConvertToInt &obj);
		const ConvertToInt &operator=(const ConvertToInt &obj);
		~ConvertToInt();
};

#endif

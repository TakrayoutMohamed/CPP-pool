#ifndef CONVERTTOINT_HPP
# define CONVERTTOINT_HPP
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

class ConvertToInt
{
	private:
		int nbr;
	public:
		ConvertToInt(/* args */);
		ConvertToInt(const std::string &str);
		ConvertToInt(float);
		ConvertToInt(double);
		ConvertToInt(char);
		ConvertToInt(const ConvertToInt &obj);
		const ConvertToInt &operator=(const ConvertToInt &obj);
		~ConvertToInt();

		/*methods*/
		operator int ();
};

#endif

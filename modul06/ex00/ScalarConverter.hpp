#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# define CHAR_ 1
# define INT_ 2
# define DOUBLE_ 3
# define FLOAT_ 4
# define STRING_ 5
# define NAN_ 6
# define NANF_ 7
# define PLUS_INF_ 8
# define MINUS_INF_ 9
# define PLUS_INFF_ 10
# define MINUS_INFF_ 11
# include <iostream>
# include <exception>
# include <string>
# include <sstream>
# include <limits>
# include <iomanip>


class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
	public:
		ScalarConverter(const ScalarConverter &obj);
		const ScalarConverter &operator=(const ScalarConverter& obj);
		/*methods*/
		static void convert(const std::string &str);
};




#endif

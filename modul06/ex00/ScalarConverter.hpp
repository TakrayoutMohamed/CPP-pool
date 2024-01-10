#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <exception>

class ScalarConverter
{
	private:
		char	_char;
		int		_int;
		float	_float;
		double	_double;
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		const ScalarConverter &operator=(const ScalarConverter& obj);
		~ScalarConverter();
		/*methods*/
		void convert(const std::string &str);
};




#endif

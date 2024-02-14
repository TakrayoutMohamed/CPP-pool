#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor for ScalarConverter has been called "<< std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{

	std::cout << "Copy constructor for ScalarConverter has been called "<< std::endl;
	if (this != &obj)
		*this = obj;
}

const ScalarConverter &ScalarConverter::operator=(const ScalarConverter& obj)
{
	std::cout << "Copy assignment operator for ScalarConverter has been called "<< std::endl;
	if (this != &obj)
	{ }
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor for ScalarConverter has been called "<< std::endl;
}

int	getTypeNormal(const std::string &str)
{
	int	i;

	i = 0;
	if ((str.size() == 1 && !isdigit(static_cast<int> (str[0]))) || str.size() == 0 )
		return (CHAR_);
	if (static_cast<char> (str[i]) == '-' || static_cast<char> (str[i]) == '+')
		i++;
	if (static_cast<char> (str[i]) == '.')
		return (STRING_);
	while (isdigit(static_cast<int> (str[i])))
		i++;
	if (static_cast<char>(str[i]) == '.')
	{
		i++;
		if (static_cast<char> (str[i]) == '\0')
			return (STRING_);
		while (isdigit(static_cast<int> (str[i])))
			i++;
		if (static_cast<char> (str[i]) == 'f')
		{
			if (static_cast<char> (str[i + 1]) == '\0')
				return (FLOAT_);
			else
				return (STRING_);
		}
		else if (static_cast<char> (str[i]) == '\0')
			return (DOUBLE_);
		else
			return (STRING_);
	}
	else
	{
		if (static_cast<char> (str[i]) == '\0')
			return (INT_);
	}
	return (STRING_);
}

int	getTypeAbnormal(const std::string &str)
{
	if (str.compare("nan") == 0)
		return (NAN_);
	if (str.compare("nanf") == 0)
		return (NANF_);
	if (str.compare("+inf") == 0)
		return (PLUS_INF_);
	if (str.compare("-inf") == 0)
		return (MINUS_INF_);
	if (str.compare("+inff") == 0)
		return (PLUS_INFF_);
	if (str.compare("-inff") == 0)
		return (MINUS_INFF_);
	return (STRING_);
}

int getType(const std::string &str)
{
	int	normalType;

	normalType = getTypeNormal(str);
	if (normalType != STRING_)
		return (normalType);
	return (getTypeAbnormal(str));

}

void	stringCase(void)
{
	std::cout << "char: imposible" << std::endl;
	std::cout << "int: imposible" << std::endl;
	std::cout << "float: imposible" << std::endl;
	std::cout << "double: imposible" << std::endl;
}

void	nanOrNanfCase(void)
{
	std::cout << "char: imposible" << std::endl;
	std::cout << "int: imposible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void	plusInfOrPlusInffCase(void)
{
	std::cout << "char: imposible" << std::endl;
	std::cout << "int: imposible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
}

void	minusInfOrMinusInffCase(void)
{
	std::cout << "char: imposible" << std::endl;
	std::cout << "int: imposible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

void	charCase(const std::string &str)
{
	char c;

	c = static_cast<char> (str[0]);
	if (!isprint(static_cast<int> (c)))
		std::cout << "char:  Non displayable" << std::endl;
	else
		std::cout << "char: '"<< c << "'" << std::endl;
	std::cout << "int: "<< static_cast<int> (c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)<< static_cast<float> (c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double> (c) << std::endl;
}

void	intCase(const std::string &str)
{
	int nbr;

	std::stringstream(str) >> nbr;
	if (!isprint(nbr))
		std::cout << "char:  Non displayable" << std::endl;
	else
		std::cout << "char: '"<< static_cast<char> (nbr)<< "'" << std::endl;
	std::cout << "int: "<< nbr << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)<< static_cast<float> (nbr) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double> (nbr) << std::endl;
}

void	floatCase(std::string str)
{
	float nbrf;

	str[str.size() - 1] = static_cast<int> ('\0');
	std::stringstream(str) >> nbrf;
	if (!isprint(static_cast<int> (nbrf)))
		std::cout << "char:  Non displayable" << std::endl;
	else
		std::cout << "char: '"<< static_cast<char> (nbrf)<< "'" << std::endl;
	std::cout << "int: "<< static_cast<int> (nbrf) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) <<  nbrf << "f" << std::endl;
	std::cout << "double: " <<  static_cast<double> (nbrf) << std::endl;
}

void	doubleCase(const std::string &str)
{
	double nbrd;

	std::stringstream(str) >> nbrd;
	if (!isprint(static_cast<int> (nbrd)))
		std::cout << "char:  Non displayable" << std::endl;
	else
		std::cout << "char: '"<< static_cast<char> (nbrd)<< "'" << std::endl;
	std::cout << "int: "<< static_cast<int> (nbrd) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2)<< static_cast<float> (nbrd) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << nbrd << std::endl;
}

void	degitsOrCharCase(const std::string &str, const int dataType)
{
	if (dataType == CHAR_)
		charCase(str);
	else if (dataType == INT_)
		intCase(str);
	else if (dataType == FLOAT_)
		floatCase(str);
	else if (dataType == DOUBLE_)
		doubleCase(str);
}

void ScalarConverter::convert(const std::string &str)
{
	int	dataType;

	dataType = getType(str);
	if (dataType == STRING_)
		stringCase();
	else if (dataType == NAN_ || dataType == NANF_)
		nanOrNanfCase();
	else if (dataType == PLUS_INF_ || dataType == PLUS_INFF_)
		plusInfOrPlusInffCase();
	else if (dataType == MINUS_INF_ || dataType == MINUS_INFF_)
		minusInfOrMinusInffCase();
	else if (dataType > 0 && dataType < 5)
		degitsOrCharCase(str, dataType);
}
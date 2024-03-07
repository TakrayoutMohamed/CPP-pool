#include "RPN.hpp"

/***********************************start of Orthodox Form Canonical**********************************/
RPN::RPN()
{
	std::cout << "Default constructor RPN" << std::endl;
}

RPN::RPN(const RPN &obj)
{
	std::cout << "Copy constructor RPN" << std::endl;
	if (this != &obj)
	{
		*this = obj;
	}
}

const RPN &RPN::operator=(const RPN &obj)
{
	std::cout << "Copy assingnment operator RPN" << std::endl;
	if (this != &obj)
	{

	}
	return (*this);
}

RPN::~RPN()
{
	std::cout << "Destructor RPN" << std::endl;
}
/***********************************end of Orthodox Form Canonical************************************/

int convertStringToInt(const std::string &str)
{
	std::stringstream ss;
	ss << str;
	int nbr;
	ss >> nbr;
	return (nbr);
}

bool	RPN::parseData(const char *str)
{
	std::istringstream isstream;
	std::string data;
	int nbr;

	if (!str || !*str)
		return (false);
	isstream.clear();
	isstream.str("");
	isstream.str(str);
	while (std::getline(isstream, data, ' '))
	{
		if (data.length() == 0)
			continue ;
		if (data.length() != 1)
		{
			std::cerr << "Error : not valid number {" << data << "}" << std::endl;
			return (false);
		}
		if (isdigit(data[0]))
		{
			nbr = convertStringToInt(data);
			this->_data.push(nbr);
		}
		else if (isOperator(data[0]))
		{
			if(_data.size() < 2)
			{
				std::cerr << "Error : not enough numbers to do the operation {" << data << "}" << std::endl;
				return (false);
			}
			else
				this->_data.push(doOperation(data[0]));
		}
		else
		{
			std::cerr << "Error : not valid data {" << data << "}" << std::endl;
			return (false);
		}

	}
	if (_data.size() != 1)
		return (std::cerr << "Error : there are more numbers in the stack need operators" << std::endl, false);
	this->_result = _data.top();
	return (true);
}

bool RPN::isOperator(const char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

// bool RPN::isAcceptedNumber(const int nbr) const
// {
// 	return (nbr < 10 && nbr >= 0);
// }

int RPN::doOperation(const char c)
{
	int firstNbr;
	int secondNbr;

	firstNbr = this->_data.top();
	this->_data.pop();
	secondNbr = this->_data.top();
	this->_data.pop();
	switch (c)
	{
		case '+':
			return (secondNbr + firstNbr);
			break ;
		case '*':
			return (secondNbr * firstNbr);
			break ;
		case '-':
			return (secondNbr - firstNbr);
			break ;
		case '/':
			return (secondNbr / firstNbr);
			break ;
		default:
			std::cerr << "Error : not accepted operator " << std::endl;
	}
	return (0);
}

/*getters*/
void RPN::reversePolishNotation(const char *str)
{
	if (parseData(str))
	{
		std::cout << this->_result << std::endl;
	}
	
}
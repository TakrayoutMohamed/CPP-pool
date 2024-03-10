#include "./PmergeMe.hpp"

/*****************************start orthodox form canonical******************/
PmergeMe::PmergeMe()
{
	std::cout << "Default constructor PmergeMe" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	std::cout << "Copy constructor PmergeMe" << std::endl;
	if (this != &obj)
	{
		*this = obj;
	}
}

const PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	std::cout << "copy assignment operator PmergeMe" << std::endl;
	if (this != &obj)
	{

	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "destructor PmergeMe" << std::endl;
}

/*****************************end orthodox form canonical********************/
/*****************************start Exceptions*********************/
const char *PmergeMe::OverflowException::what() const throw()
{
	return ("Overflow Exception");
}
/*****************************end Exceptions***********************/
/************************* Start member functions ***************************/


bool	PmergeMe::parseData(const char *str)
{
	if (!str || !*str)
	{
		std::cerr << "Error "<< std::endl << "The data you entered not accepted" << std::endl;
		return (false);
	}
	if (!isAcceptedArgs(str))
	{
		std::cerr << "Error "<< std::endl << "The data you entered not valid" << std::endl;
		std::cerr << "Valid pattern : (\\s)* (\\d)+ (\\s*|\\d+)*" << std::endl;
		std::cerr << "Valid pattern : any combination of positive numbers and spaces " << std::endl;
		return (false);
	}
	try
	{
		fillDataQue(str);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error :" << std::endl << "Exception of type :" << e.what() << std::endl;
		return (false);
	}
	return (true);
}

bool	PmergeMe::isAcceptedArgs(const char *str) const throw()
{
	int i = 0;

	if (!str || !*str)
		return (false);
	while(str[i])
	{
		if (isspace(static_cast <int> (str[i])) && ++i > -2)
			continue ;
		if (str[i] == '-')
			return (false);
		if (str[i] == '+')
		{
			if (!isdigit(str[i + 1]))
				return (false);
			if (i != 0 && !isspace(str[i - 1]))
				return (false);
		}
		i++;
	}
	return (true);
}

void PmergeMe::fillDataQue(const char *strData)
{
	std::stringstream tempsstream;
	std::string strNbr;
	int nbr;

	tempsstream.clear();
	tempsstream.str("");
	tempsstream.str(strData);
	while(std::getline(tempsstream, strNbr, ' '))
	{
		if (strNbr.length() == 0)
			continue ;
		nbr = convertStringToInt(strNbr);
		dataQueue.push(nbr);
	}
}

int PmergeMe::convertStringToInt(const std::string str) const
{
    int nbr;
    std::stringstream ss;
    ss << str;
    ss >> nbr;
    if (ss.fail())
        throw OverflowException;
    return (nbr);
}
/************************* End member functions *****************************/
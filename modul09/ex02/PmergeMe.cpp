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



//this one should be removed
///
///
///
///
void printQue(std::queue<int> data) 
{
	if (data.empty())
	{
		std::cout << "the queue is empty" <<std::endl;
		return ;
	}
	else
		std::cout << "***********start printing the data of the queue" << std::endl;
	while (!data.empty())
	{
		std::cout << data.front() << " ";
		data.pop();
	}
	std::cout << std::endl;
	std::cout << "***********end printing the data of the queue" << std::endl;
}

//this one should be removed
///
///
///
///
void printVectorPair(std::vector<std::pair<int, int> > data) 
{
	if (data.empty())
	{
		std::cout << "the vector<pair> is empty" <<std::endl;
		return ;
	}
	else
		std::cout << "***********start printing the data of the vector<pair>" << std::endl;
	std::vector<std::pair<int, int> >::iterator it = data.begin();
	while (it != data.end())
	{
		std::cout <<"{" << it->first << ", " << it->second << "} ";
		it++;
	}
	std::cout << std::endl;
	std::cout << "***********end printing the data of the vector<pair>" << std::endl;
}

//this one should be removed
///
///
///
///
void printVector(std::vector<int> data) 
{
	if (data.empty())
	{
		std::cout << "the vector is empty" <<std::endl;
		return ;
	}
	else
		std::cout << "***********start printing the data of the vector" << std::endl;
	std::vector<int>::iterator it = data.begin();
	while (it != data.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	std::cout << "***********end printing the data of the vector" << std::endl;
}

//this one should be removed
///
///
///
///
void printList(std::list<int> data) 
{
	if (data.empty())
	{
		std::cout << "the list is empty" <<std::endl;
		return ;
	}
	else
		std::cout << "***********start printing the data of the list" << std::endl;
	std::list<int>::iterator it = data.begin();
	while (it != data.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	std::cout << "***********end printing the data of the list" << std::endl;
}

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
		std::queue<int> dataQueue;
		fillDataQue(str, dataQueue);
		fillDataToContainer<std::vector<int> >(dataQueue, dataVector);
		fillDataToContainer<std::list<int> >(dataQueue, dataList);
		// printQue(dataQueue);
		printVector(this->dataVector);
		sortVector();
		// printList(this->dataList);
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

void PmergeMe::fillDataQue(const char *strData, std::queue<int> &dataQueue)
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
/************************* Start member functions that uses Vector*****************************/
void PmergeMe::sortVector()
{
	std::vector<std::pair<int, int> > pairVector;
	int lastElem;
	if (this->dataVector.size() % 2 != 0)
	{
		lastElem = *(--(this->dataVector.end()));
		this->dataVector.pop_back();
	}
	makePairs(this->dataVector, pairVector);
	sortPairAcending(pairVector);

	sortVectorByPairFirst(pairVector);
	printVectorPair(pairVector);//this one should be removed
}

std::vector<std::pair<int, int> > &PmergeMe::makePairs(const std::vector<int> &vect, std::vector<std::pair<int, int> > &obj)
{
	std::vector<int>::const_iterator it;
	
	it = vect.begin();
	while (it != vect.end() && (it + 1) != vect.end())
	{
		obj.insert(obj.end(), std::make_pair(*it, *(it + 1)));
		it = it + 2;
	}
	return (obj);
}

void PmergeMe::sortPairAcending(std::vector<std::pair<int, int> > &obj)
{
	std::vector<std::pair<int, int> >::iterator it;
	it = obj.begin();

	while (it != obj.end())
	{
		if (it->first < it->second)
			swap(it->first, it->second);
		it++;
	}
}

void PmergeMe::sortVectorByPairFirst(std::vector<std::pair<int, int> > &obj)
{
	(void) obj;
}
/************************* End member functions that uses Vector*******************************/
/************************* Start member functions that uses List*****************************/
// void PmergeMe::fillDataVector(std::deque<int> data)
// {
// 	while (!data.empty())
// 	{
// 		this->dataVector.insert(this->dataVector.end(), data.front());
// 		data.pop();
// 	}
// }
/************************* End member functions that uses List*******************************/
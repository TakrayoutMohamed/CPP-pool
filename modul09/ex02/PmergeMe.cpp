#include "./PmergeMe.hpp"

/*****************************start orthodox form canonical******************/
PmergeMe::PmergeMe() :_lastElem(-1)
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
		this->dataVector = obj.dataVector;
		this->dataDeque = obj.dataDeque;
		this->_lastElem = obj._lastElem;
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

void PmergeMe::printVector(const std::string &str, const std::vector<int> &data)  const
{
	std::vector<int>::const_iterator it = data.begin();
	std::cout << str ;
	while (it != data.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque(const std::string &str, const std::deque<int> &data)  const
{
	std::deque<int>::const_iterator it = data.begin();
	std::cout << str ;
	while (it != data.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

double getTimeNow()
{
	struct timeval t;

    gettimeofday(&t, NULL);
    return(static_cast<double> (t.tv_sec) + static_cast<double>(t.tv_usec / 1000000.00));
}

bool	PmergeMe::parseData(const std::string &str)
{
	double startVectorTime;
	double endVectorTime;
	double startDequeTime;
	double endDequeTime;

	if (str.length() == 0)
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
		fillDataToContainer<std::deque<int> >(dataQueue, dataDeque);
		printVector("Befor [Vector]:", this->dataVector);
		startVectorTime = getTimeNow();
		sortVector();
		endVectorTime = (getTimeNow() - startVectorTime) * 1000000.00;
		printVector("After [Vector]:", this->dataVector);
		printDeque("Befor [Deque]:", this->dataDeque);
		startDequeTime = getTimeNow();
		sortDeque();
		endDequeTime = (getTimeNow() - startDequeTime) * 1000000.00;
		printDeque("After [Deque]:", this->dataDeque);
		std::cout << "Time to process a range of "<< this->dataVector.size() <<" elements with std::[Vector] : " << endVectorTime << std::endl;
		std::cout << "Time to process a range of "<< this->dataDeque.size() <<" elements with std::[Deque] : " << endDequeTime << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error :" << std::endl << "Exception of type :" << e.what() << std::endl;
		return (false);
	}
	return (true);
}

bool	PmergeMe::isAcceptedArgs(const std::string &str) const throw()
{
	int i = 0;

	if (str.length() == 0)
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

void PmergeMe::fillDataQue(const std::string &strData, std::queue<int> &dataQueue)
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
	std::vector<int> mainChain;
	std::vector<int> pendChain;

	this->_lastElem = -1;
	if (this->dataVector.size() % 2 != 0)
	{
		_lastElem = *(--(this->dataVector.end()));
		this->dataVector.pop_back();
	}
	makePairs(this->dataVector, pairVector);
	dataVector.clear();
	sortPairAcending(pairVector);

	sortVectorByPairFirst(pairVector);
	mainPendChain(mainChain, pendChain, pairVector);
	printVector("main chain",mainChain);
	printVector("pend chain",pendChain);
	mergeMainPendChain(mainChain, pendChain);
	printVector("main chain",mainChain);
	printVector("pend chain",pendChain);
	pairVector.clear();
	mainChain.clear();
	pendChain.clear();
}

void PmergeMe::makePairs(const std::vector<int> &vect, std::vector<std::pair<int, int> > &obj)
{
	std::vector<int>::const_iterator it;
	
	it = vect.begin();
	while (it != vect.end() && (it + 1) != vect.end())
	{
		obj.insert(obj.end(), std::make_pair(*it, *(it + 1)));
		it = it + 2;
	}
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
	mergeSort(obj, 0, obj.size() - 1);
}

void PmergeMe::mainPendChain(std::vector<int> &mainObj, std::vector<int> &pendObj, std::vector<std::pair<int, int> > &pairObj)
{
	std::vector<std::pair<int, int> >::iterator it = pairObj.begin();
	if (it != pairObj.end())
	{
		mainObj.insert(mainObj.end(), it->second);
		mainObj.insert(mainObj.end(), it->first);
		it++;
	}
	while (it != pairObj.end())
	{
		mainObj.insert(mainObj.end(), it->first);
		pendObj.insert(pendObj.end(), it->second);
		it++;
	}
}

void PmergeMe::mergeSort(std::vector<std::pair<int, int> > &obj, int start, int end)
{
	if (start == end)
		return;
	int mid = (end + start) / 2;
	mergeSort(obj, start, mid);
	mergeSort(obj, mid + 1, end);
	_merge(obj, start, mid, end);
}

void PmergeMe::_merge(std::vector<std::pair<int, int> > &obj, int start, int mid, int end)
{
	std::vector<std::pair<int, int> > temp;
	int startFirstHalf = start;
	int startSecondHalf = mid + 1;
	while (startFirstHalf <= mid && startSecondHalf <= end)
	{
		if ((obj.begin() + startFirstHalf)->first < (obj.begin() + startSecondHalf)->first)
			temp.push_back(*(obj.begin() + startFirstHalf++));
		else
			temp.push_back(*(obj.begin() + startSecondHalf++));
	}
	while (startFirstHalf <= mid)
		temp.push_back(*(obj.begin() + startFirstHalf++));
	while (startSecondHalf <= end)
		temp.push_back(*(obj.begin() + startSecondHalf++));
	for(size_t i = 0; i < temp.size(); i++)
		*(obj.begin() + start + i) = *(temp.begin() + i);
}

bool comp(int a, int value)
{
	return (a <= value);
}

void PmergeMe::mergeMainPendChain(std::vector<int> &mainChain, std::vector<int> &pendChain)
{
	int i = std::distance(pendChain.begin(), pendChain.end()) / 2;
	int j = i + 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator prevIt;
	std::vector<int>::iterator lower;

	it = pendChain.begin();
	this->dataVector.clear();
	this->dataVector.insert(this->dataVector.begin(), mainChain.begin(), mainChain.end());
	while (it != pendChain.end() && i >= 0 )
	{
		prevIt = it;
		if (i - 2 >= 0)
		{
			lower = std::lower_bound(this->dataVector.begin(), this->dataVector.end(), *(it + 1), comp);
			this->dataVector.insert(lower, *(it + 1));
			it++;
			i--;
		}
		lower = std::lower_bound(this->dataVector.begin(), this->dataVector.end(), *prevIt, comp);
		this->dataVector.insert(lower, *prevIt);
		it++;
		i--;
	}
	if (this->_lastElem != -1)
	{
		lower = std::lower_bound(this->dataVector.begin(), this->dataVector.end(), _lastElem, comp);
		this->dataVector.insert(lower, _lastElem);
	}
	it = pendChain.end() - 1;
	while (static_cast<size_t>(j) < pendChain.size() - 1)
	{
		lower = std::lower_bound(this->dataVector.begin(), this->dataVector.end(), *(it), comp);
		this->dataVector.insert(lower, *it);
		it--;
		j++;
	}

}
/************************* End member functions that uses Vector*******************************/
/************************* Start member functions that uses Deque*****************************/
void PmergeMe::sortDeque()
{
	std::deque<std::pair<int, int> > pairDeque;
	std::deque<int> mainChain;
	std::deque<int> pendChain;

	this->_lastElem = -1;
	if (this->dataDeque.size() % 2 != 0)
	{
		_lastElem = *(--(this->dataDeque.end()));
		this->dataDeque.pop_back();
	}
	makePairs(this->dataDeque, pairDeque);
	sortPairAcending(pairDeque);

	sortDequeByPairFirst(pairDeque);
	mainPendChain(mainChain, pendChain, pairDeque);
	pairDeque.clear();
	mergeMainPendChain(mainChain, pendChain);
	mainChain.clear();
	pendChain.clear();
}

void PmergeMe::makePairs(const std::deque<int> &vect, std::deque<std::pair<int, int> > &obj)
{
	std::deque<int>::const_iterator it;
	
	it = vect.begin();
	while (it != vect.end() && (it + 1) != vect.end())
	{
		obj.insert(obj.end(), std::make_pair(*it, *(it + 1)));
		it = it + 2;
	}
}

void PmergeMe::sortPairAcending(std::deque<std::pair<int, int> > &obj)
{
	std::deque<std::pair<int, int> >::iterator it;
	it = obj.begin();

	while (it != obj.end())
	{
		if (it->first < it->second)
			swap(it->first, it->second);
		it++;
	}
}

void PmergeMe::sortDequeByPairFirst(std::deque<std::pair<int, int> > &obj)
{
	mergeSort(obj, 0, obj.size() - 1);
}

void PmergeMe::mainPendChain(std::deque<int> &mainObj, std::deque<int> &pendObj, std::deque<std::pair<int, int> > &pairObj)
{
	std::deque<std::pair<int, int> >::iterator it = pairObj.begin();
	if (it != pairObj.end())
	{
		mainObj.insert(mainObj.end(), it->second);
		mainObj.insert(mainObj.end(), it->first);
		it++;
	}
	while (it != pairObj.end())
	{
		mainObj.insert(mainObj.end(), it->first);
		pendObj.insert(pendObj.end(), it->second);
		it++;
	}
}

void PmergeMe::mergeSort(std::deque<std::pair<int, int> > &obj, int start, int end)
{
	if (start == end)
		return;
	int mid = (end + start) / 2;
	mergeSort(obj, start, mid);
	mergeSort(obj, mid + 1, end);
	_merge(obj, start, mid, end);
}

void PmergeMe::_merge(std::deque<std::pair<int, int> > &obj, int start, int mid, int end)
{
	std::deque<std::pair<int, int> > temp;
	int startFirstHalf = start;
	int startSecondHalf = mid + 1;
	while (startFirstHalf <= mid && startSecondHalf <= end)
	{
		if ((obj.begin() + startFirstHalf)->first < (obj.begin() + startSecondHalf)->first)
			temp.push_back(*(obj.begin() + startFirstHalf++));
		else
			temp.push_back(*(obj.begin() + startSecondHalf++));
	}
	while (startFirstHalf <= mid)
		temp.push_back(*(obj.begin() + startFirstHalf++));
	while (startSecondHalf <= end)
		temp.push_back(*(obj.begin() + startSecondHalf++));
	for(size_t i = 0; i < temp.size(); i++)
		*(obj.begin() + start + i) = *(temp.begin() + i);
}

void PmergeMe::mergeMainPendChain(std::deque<int> &mainChain, std::deque<int> &pendChain)
{
	int i = std::distance(pendChain.begin(), pendChain.end()) / 2;
	int j = i + 1;
	std::deque<int>::iterator it;
	std::deque<int>::iterator prevIt;
	std::deque<int>::iterator lower;

	it = pendChain.begin();
	this->dataDeque.clear();
	this->dataDeque.insert(this->dataDeque.begin(), mainChain.begin(), mainChain.end());
	while (it != pendChain.end() && i >= 0 )
	{
		prevIt = it;
		if (i - 2 >= 0)
		{
			lower = std::lower_bound(this->dataDeque.begin(), this->dataDeque.end(), *(it + 1), comp);
			this->dataDeque.insert(lower, *(it + 1));
			it++;
			i--;
		}
		lower = std::lower_bound(this->dataDeque.begin(), this->dataDeque.end(), *prevIt, comp);
		this->dataDeque.insert(lower, *prevIt);
		it++;
		i--;
	}
	if (this->_lastElem != -1)
	{
		lower = std::lower_bound(this->dataDeque.begin(), this->dataDeque.end(), _lastElem, comp);
		this->dataDeque.insert(lower, _lastElem);
	}
	it = pendChain.end() - 1;
	while (static_cast<size_t>(j) < pendChain.size() - 1)
	{
		lower = std::lower_bound(this->dataDeque.begin(), this->dataDeque.end(), *(it), comp);
		this->dataDeque.insert(lower, *it);
		it--;
		j++;
	}

}
/************************* End member functions that uses List*******************************/
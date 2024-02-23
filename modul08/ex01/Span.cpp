#include "./Span.hpp"
Span::Span()
{

}

Span::Span(const Span &obj)
{
	if (&obj != this)
	{
		*this = obj;
	}
}

Span::Span(const unsigned int nbr) : spanSize(nbr)
{

}

const Span &Span::operator=(const Span &obj)
{
	if (&obj != this)
	{
		this->vect = obj.vect;
	}
	return (*this);
}
Span::~Span()
{

}

/*method functions*/
void Span::addNumber(const int nbr)
{
	if (this->spanSize == this->vect.size())
		return;
	// 	throw OutOfSizeException;
	this->vect.push_back(nbr);
}
void Span::addManyNumbers(const unsigned int nbr)
{
	srand(time(0));
	// if (this->spanSize == this->vect.size())
	// 	throw OutOfSizeException;
	// if (this->spanSize + this->vect.size() > nbr)
	// 	throw OutOfSizeException;
	unsigned int i = 0;
	while (i < nbr)
	{
		addNumber(rand() % 200);
		i++;
	}

}

int Span::shortestSpan()
{
	int shortSpan;
	// if (this->vect.size() <= 1)
	// 	throw NoSpanCanBeFoundException;
	std::sort(this->vect.begin(), this->vect.end());
	shortSpan = this->longestSpan();
	std::vector<int>::iterator it = ++vect.begin();
	for (; it != --vect.end(); it++)
	{
		if (shortSpan > *it - (*(it - 1)))
			shortSpan = *it - (*(it - 1));
	}
	return (shortSpan);
}
int Span::longestSpan()
{
	std::sort(this->vect.begin(), this->vect.end());
	return (*(--this->vect.end()) - *this->vect.begin());
}

void Span::print(void)
{	
	std::cout << "****************the vector elements are : ****************" << std::endl;
	for (std::vector<int>::iterator it = vect.begin() ;it != vect.end(); it++)
    {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
	std::cout << "**********************************************************" << std::endl;
}

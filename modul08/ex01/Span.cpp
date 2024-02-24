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
		if (!this->vect.empty())
			vect.clear();
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

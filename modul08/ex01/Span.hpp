#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include <vector>
# include <iterator>
# include <algorithm>

class Span
{
	private :
		unsigned int	spanSize;
		std::vector<int> vect;

	protected:
		Span();

	public :
		Span(const Span &obj);
		Span(const unsigned int nbr);
		const Span &operator=(const Span &obj);
		~Span();
		/*method functions*/
		void addNumber(const int nbr);
		template<typename T>
		void addManyNumbers(T first, T last)
		{

			// if (this->spanSize == this->vect.size())
			// 	throw OutOfSizeException;
			// if (this->spanSize + this->vect.size() > static_cast<size_t>(abs(distance(last, first))))
			// 	throw OutOfSizeException;
			this->vect.insert(this->vect.end(), first, last);
		}
		int shortestSpan();
		int longestSpan();
		void print(void);

};

#endif

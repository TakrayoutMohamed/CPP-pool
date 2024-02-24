#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

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
			if (this->spanSize < this->vect.size() + static_cast<size_t>(abs(std::distance(first, last))))
				throw OutOfSizeException;
			this->vect.insert(this->vect.end(), first, last);
		}
		class NoSpanCanBeFoundException: public std::exception
		{
			public :
				const char *what() const throw();
		}NoSpanCanBeFoundException;

		class OutOfSizeException: public std::exception
		{
			public :
				const char *what() const throw();
		}OutOfSizeException;
		int shortestSpan();
		int longestSpan();
		void print(void);

};

#endif

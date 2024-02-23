#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include <vector>
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
		void addManyNumbers(const unsigned int nbr);
		int shortestSpan();
		int longestSpan();
		void print(void);

};

#endif

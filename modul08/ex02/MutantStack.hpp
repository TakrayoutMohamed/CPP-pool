#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>

template <typename S>
class MutantStack : public std::stack<S, std::deque<S> >
{
	private:
		/* data */
	public:
		typedef typename std::deque<S>::iterator iterator;
		MutantStack(/* args */);
		MutantStack(const MutantStack<S> &obj);
		MutantStack<S> &operator=(const MutantStack<S> &obj);
		~MutantStack();

		/*methods*/
		iterator begin();

		iterator end();
};

template<typename S>
MutantStack<S>::MutantStack()
{
    // std::cout << "Default constructor MutantStack<>" << std::endl;
}

template<typename S>
MutantStack<S>::MutantStack(const MutantStack<S> &obj)
{
    // std::cout << "Copy constructor MutantStack<>" << std::endl;
	if (this != &obj)
		*this = obj;
}

template<typename S>
MutantStack<S> &MutantStack<S>::operator=(const MutantStack<S> &obj)
{
	// std::cout << "Copy assignment operator MutantStack<>" << std::endl;
	if (this != &obj)
	{
		this->c = obj.c;
	}
	return (*this);
}

template<typename S>
MutantStack<S>::~MutantStack()
{
	// std::cout << "Destructor MutantStack<>" << std::endl;
}

/*methods*/

template<typename S>
typename MutantStack<S>::iterator MutantStack<S>::begin()
{
	return (this->c.begin());
}

template<typename S>
typename MutantStack<S>::iterator MutantStack<S>::end()
{
	return (this->c.end());
}
#endif

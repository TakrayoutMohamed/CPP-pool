#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>
# include <exception>

class NullException : public std::exception
{
	public :
		virtual const char *what() const throw();
} NullException;

const char *NullException::what() const throw()
{
	return ("NullException");
}

class ElemNotFoundException : public std::exception
{
	public :
		virtual const char *what() const throw();
} ElemNotFoundException;

const char *ElemNotFoundException::what() const throw()
{
	return ("ElemNotFoundException");
}

template <typename T>
int easyfind(T data, int toFind)
{
	if (data.empty())
		throw NullException;
	if (std::binary_search(data.begin(), data.end(), toFind) == false)
		throw ElemNotFoundException;
	return (*(std::find(data.begin(), data.end(), toFind)));
}
#endif

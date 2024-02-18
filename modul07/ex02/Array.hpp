#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>
# include <iostream>

template <class T>
class Array
{
	private:
		T *arr;
		unsigned int _n;
	public :
		class OutOfBoundsException : public std::exception
		{
			private:
				/* data */
			public:
				virtual const char *what() const throw();
		}OutOfBoundsException;
		Array<T>();
		Array(unsigned int);
		Array(const Array<T> &obj);
		const Array<T> &operator=(const Array<T> &obj);
		T &operator[](int index);
		/*membeer functions*/
		size_t	size(void) const;
		~Array();
};

template <class T>
Array<T>::Array(): _n(0)
{
	// std::cout << "Default Constructor" << std::endl;
	arr = new T[0];
};

template <class T>
Array<T>::Array(unsigned int n) : _n(n)
{
	// std::cout << "Constructor(unsigned int)" << std::endl;
	arr = new T[_n];
};

template <class T>
Array<T>::Array(const Array<T> &obj) : arr(NULL)
{
	// std::cout << "Copy constructor" << std::endl;
	*this = obj;
};

template<class T>
const Array<T> &Array<T>::operator=(const Array<T> &obj)
{
	// std::cout << "Copy assignment operator" << std::endl;
	if (this != &obj)
	{
		if (this->arr)
		{
			delete[] this->arr;
		}
		this->_n = obj.size();
		this->arr = new T[obj.size()];
		for (size_t i = 0; i < obj.size(); i++)
		{
			this->arr[i] = obj.arr[i];
		}
	}
	return (*this);
};

template<class T>
T &Array<T>::operator[](int index)
{
	// std::cout << "subscript operator" << std::endl;
	if (index >= static_cast <int>(this->_n) || index < 0)
		throw OutOfBoundsException;
	return (arr[index]);
}

template <class T>
size_t Array<T>::size(void) const
{
	return (static_cast <size_t> (_n));
};

template <class T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "OutOfBoundsException";
}

template <class T>
Array<T>::~Array()
{
	// std::cout << "Destructor" << std::endl;
	delete[] arr;
}

#endif

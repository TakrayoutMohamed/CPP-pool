#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <class T>
class Array
{
	private:
		T *arr;
		unsigned int _n;
	public :
		Array();
		Array(unsigned int);
		Array(const Array<T> &obj);
		const Array<T> &operator=(const Array<T> &obj);
		T &operator[](int index);
		//here i still need to declere the subscript operator []
		/*membeer functions*/
		size_t	size(void) const;
		~Array();
};

template <class T>
Array<T>::Array(): _n(0)
{
	std::cout << "Default Constructor" << std::endl;
	arr = new T[0];
};

template <class T>
Array<T>::Array(unsigned int n) : _n(n)
{
	std::cout << "Constructor(unsigned int)" << std::endl;
	arr = new T[_n];
	std::cout << "Constructor(unsigned int)" << std::endl;
};

template <class T>
Array<T>::Array(const Array<T> &obj)
{
	std::cout << "Copy constructor" << std::endl;
	if (this != &obj)
	{
		*this = Array<T> (obj);
	}
};

template<class T>
const Array<T> &Array<T>::operator=(const Array<T> &obj)
{
	std::cout << "Copy assignment operator" << std::endl;
	if (this != &obj)
	{
		std::cout << "sssssssss fuuuuck1" << std::endl;
		// if (this->arr)
		// 	delete[] arr;
		this->arr = new T[obj.size()];
		for (int i = 0; i < obj.size(); i++)
		{
			std::cout << "1   i = " << i << std::endl;
			this->arr[i] = obj.arr[i];
			std::cout << "2"<< std::endl;
		}
		std::cout << "sssssssss fuuuuck2" << std::endl;
	}
	return (*this);
};

template<class T>
T &Array<T>::operator[](int index)
{
	std::cout << "subscript operator" << std::endl;
	return (arr[index]);
}

template <class T>
size_t Array<T>::size(void) const
{
	return (static_cast <size_t> (_n));
};

template <class T>
Array<T>::~Array()
{
	std::cout << "Destructor" << std::endl;
	delete[] arr;
}

#endif

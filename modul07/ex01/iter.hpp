#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include "NullException.hpp"

template <typename T>
void	iter(T *array, int len, void (*fun)(T &))
{
	int	i;

	i = 0;
	if (array == NULL || !fun)
		throw NullException();
	while (i < len)
	{
		fun(array[i]);
		i++;
	}
}

#endif

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include "./Data.hpp"
class Serializer
{
	private:
		Serializer(/* args */);
		Serializer(const Serializer &obj);
		const Serializer &operator=(const Serializer &obj);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
#endif

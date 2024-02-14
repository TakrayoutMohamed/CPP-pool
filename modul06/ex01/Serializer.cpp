#include "./Serializer.hpp"

Serializer::Serializer(/* args */)
{
    std::cout << "Default constructor for Serializer" << std::endl;
}

Serializer::Serializer(const Serializer &obj)
{
    std::cout << "copy constructor for Serializer" << std::endl;
    if (this != &obj)
        *this = obj;
}

const Serializer &Serializer::operator=(const Serializer &obj)
{
    (void)obj;
    std::cout << "Copy assignment operator for Serializer " << std::endl;
    return (*this);
}

Serializer::~Serializer()
{
    std::cout << "Destructor for Serializer" << std::endl;
}

/*static methods*/

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t> (ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *> (raw));
}

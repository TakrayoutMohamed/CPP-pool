#include <iostream>

class B
{
    public :
    B()
    {
        std::cout << "default constructor of B class" << std::endl;
    }
};

class A
{
    public:
    A()
    {
        std::cout << "default constructor of A class" << std::endl;
    }
    A(B b){
        std::cout << "constructor that takes B class as parameter of A class" << std::endl;
    }
};

int main()
{
    B b;
    A a=b;
    return (0);
}
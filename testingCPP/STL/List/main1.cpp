#include <initializer_list>
#include <iostream>
#include <iterator>
#include <list>
 
void print(std::string const comment, std::list<int> & container)
{
    size_t size = container.size();
    std::cout << comment << "{ ";
    for (std::list<int>::iterator it = container.begin() ; it != container.end(); it++)
        std::cout << *it << (--size ? ", " : " ");
    std::cout << "}\n";
}
 
int main()
{
    std::list<int> x, y, z;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    std::list<int> w;
    w.push_back(4);
    w.push_back(5);
    w.push_back(6);
    w.push_back(7);
 
    std::cout << "Initially:\n";
    print("x = ", x);
    print("y = ", y);
    print("z = ", z);
 
    std::cout << "Copy assignment copies data from x to y:\n";
    y = x;
    print("x = ", x);
    print("y = ", y);
 
    std::cout << "Move assignment moves data from x to z, modifying both x and z:\n";
    z = x;
    print("x = ", x);
    print("z = ", z);
 
    std::cout << "Assignment of initializer_list w to z:\n";
    z = w;
    print("w = ", w);
    print("z = ", z);
}
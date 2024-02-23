#include <iostream>
#include <vector>
#include  <set>

using namespace std;

int main(void)
{
    vector<int> v1;
    // hash_multiset<int, int> t;
    v1.push_back(30);
    v1.push_back(20);
    v1.push_back(10);
    v1.push_back(40);

    for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        std::cout << "v1 -> " << *it << std::endl;
    }

    std::cout << " the value of the last pointing to is " << *(v1.end()) << "the precedent of end is " << *(--(v1.end())) << std::endl;
    exit(10);



    // std::cout << " v1 without iterator : " << v1 << std::endl; //not work cause you need to overload <<
    // std::cout << " *v1 without iterator : " << *v1 << std::endl;// error : indirection requires pointer operand ('vector<int>' invalid)
    std::cout << " v1.front() without iterator : " << v1.front() << std::endl;
    std::cout << " v1.back() without iterator : " << v1.back() << std::endl;
    /*to get the size of a vector*/
    std::cout << "size of the vector is : " << v1.size() << std::endl;
    std::cout << "capacite of the vector is : " << v1.capacity() << std::endl;

    v1.push_back(50);
    std::cout << "adding a value to the vector" << std::endl;
    std::cout << "size of the vector is : " << v1.size() << std::endl;
    std::cout << "capacite of the vector is : " << v1.capacity() << std::endl;
    v1.resize(5, 404);

    std::cout << "resizing the vector so it will be 5 elem" << std::endl;
    std::cout << "size of the vector is : " << v1.size() << std::endl;
    std::cout << "capacite of the vector is : " << v1.capacity() << std::endl;
    v1.clear();

    std::cout << "clear the vector" << std::endl;
    std::cout << "size of the vector is : " << v1.size() << std::endl;
    std::cout << "capacite of the vector is : " << v1.capacity() << std::endl;

    // std::cout << "value of first elem in vector is : " << v1.at(0) << std::endl;//here it aborts because we cleared the victor than try to access to it
    std::vector<int> v2 ;
    std::cout << "***********the vector v2 just created still fresh new one********" << std::endl;
    std::cout << " the size of the second vector v2 is : " << v2.size() <<std::endl;
    std::cout << " the capacity of the second vector v2 is : " << v2.capacity() <<std::endl;

    std::cout << "*************next try to swap the values of the vect v1 to v2********" << std::endl;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    // v2.resize(v1.size());
    // std::cout << "***********the vector v2 just created but resized to the size of v1********" << std::endl;
    // std::cout << " the size of the second vector v2 is : " << v2.size() <<std::endl;
    // std::cout << " the capacity of the second vector v2 is : " << v2.capacity() <<std::endl;
    std::cout << "==========befor swaping the two vectors========" << std::endl;
    for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        std::cout << "v1 -> " << *it << "   ";
    }
    std::cout<< std::endl;
    for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        std::cout << "v2 -> " << *it << "  ";
    }
    std::cout<< std::endl;
    v2.swap(v1);
    std::cout << "==========after swaping the two vectors========" << std::endl;
    for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        std::cout << "v1 -> " << *it << "   ";
    }
    std::cout<< std::endl;
    for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        std::cout << "v2 -> " << *it << "  ";
    }
    std::cout<< std::endl;
    return (0);
}
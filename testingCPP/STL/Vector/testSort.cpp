#include <iostream>
#include <algorithm>
#include <vector>

// bool comp(std::vector<int>::iterator &a, std::vector<int>::iterator &b)
// {
//     return (1);
// }

int main(void)
{
    std::vector <int> vect;
    vect.push_back(3);
    vect.push_back(1);
    vect.push_back(5);
    vect.push_back(8);
    vect.push_back(4);

    for (std::vector<int>::iterator it = vect.begin() ;it != vect.end(); it++)
    {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;

    std::cout << "after sorting it" << std::endl;
    std::sort(vect.begin(), vect.end());
    for (std::vector<int>::iterator it = vect.begin() ;it != vect.end(); it++)
    {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;

    std::cout << "after sorting it using a helper function in std::sort parameter" << std::endl;
    vect.resize(12);
    std::sort(vect.begin(), vect.end());
    for (std::vector<int>::iterator it = vect.begin() ;it != vect.end(); it++)
    {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    std::cout << "distance between the first and the last is : " << std::distance(vect.begin(), --vect.end());

    return (0);
}
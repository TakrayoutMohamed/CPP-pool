#include <iostream>
#include <list>

using namespace std;

int main ()
{
    list<int> list1(7); //[1, 2, 3, 4]
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);
    list1.resize(44);
    std::cout << "the size of list1 = " << list1.size()  << std::endl;
    list<int> list2; // [5, 6, 7, 8]
    list2.push_back(5);
    list2.push_back(6);
    list2.push_back(7);
    list2.push_back(8);
    
    list<int>::iterator it;
    
    it = list1.begin();
    ++it;   //pointing to second position          
    std::cout << *it << std::endl; 
    
    list1.splice(it, list2);
    /* transfer all elements of list2 at position 2 in list1 */
    /* now list1 is 1 5 6 7 8 2 3 4 and list2 is empty */
    
    // std::cout << *list2.begin() << std::endl;
                                          
    list2.splice(list2.begin(), list1, it);
    /* transfer element pointed by it in list1 to the beginning of list2 */
    /* list2 is now 2 and list1 is 1 5 6 7 8 3 4*/
    std::cout << *list2.begin() << std::endl;
    std::cout << *list2.end() << std::endl;
    
    return 0;
}
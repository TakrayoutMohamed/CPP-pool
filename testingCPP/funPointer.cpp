#include <iostream>  
using namespace std;  
void printname(void)  
{  
    std::cout << "Name is :" << std::endl;  
}  
  
int main()  
{  
    char s[20];  // array declaration  
    void (*ptr)(void);  // function pointer declaration  
    ptr=printname;  // storing the address of printname in ptr.  
    std::cout << "Enter the name of the person: " << std::endl;  
    cin>>s;  
    cout<<s<< std::endl;  
    ptr();  // calling printname() function  
   return 0;  
}
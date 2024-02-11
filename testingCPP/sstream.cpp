#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


int main(void)
{
    const std::string str = "2.010f";
    double c;
    std::stringstream(str) >> c;
    std::cout << "the str value is : " << str << " and c value is :" << c << std::endl;
    std::stringstream(str) >>  c;
    std::cout << "the str value is : " << str << " and c value in int is :" << c << std::endl;
    std::cout << "the str value is : " << str << " and c value in float is :" << std::setprecision(2) <<  static_cast<float>(c) << "f"<< std::endl;
    float a = 88888888888888888888.2f;
    std::cout  << "the value is : " << a << " iiiiii" << std::endl;
    int i = a;
    std::cout  << "the value is : " << i << " iiiiii" << std::endl;


    return (0);
}
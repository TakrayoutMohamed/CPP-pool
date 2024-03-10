#include <sstream>
#include <iostream>
#include <string>
#include <typeinfo>

int convertStringToInt(const std::string str)
{
    int nbr;
    std::stringstream ss;
    ss << str;
    ss >> nbr;
    if (ss.fail())
        std::cerr << "overflow error " << std::endl;
    return (nbr);
}

int main()
{
    std::stringstream isstream;

    std::string str;
    int nbr;

    isstream.str("12 0 45888888888888888888      8 9 6");
    while (getline(isstream, str, ' '))
    {
        if (str.length() == 0)
            continue;
        std::cout << "str = {" << str << "} and the data type of it is : " << typeid(str).name() << std::endl;
        nbr = convertStringToInt((str));
        std::cout << "nbr = {" << nbr << "} and the data type of it is : " << typeid(nbr).name() << std::endl;
    }

    // while (getline(isstream, nbr, ' '))
    // {
    //     if (str[0] == ' ')
    //         continue;
    //     std::cout << "str = " << str << " and the data type of it is : " << typeid(str).name() << std::endl;
    // }
    return (0);
}
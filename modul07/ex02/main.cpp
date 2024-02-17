#include <iostream>
#include "Array.hpp"

#define MAX_VAL 7

// int main()
// {
//     Array<int> numbers(10);
//     for (size_t i = 0; i < numbers.size(); i++)
//         std::cout << numbers[i] << " ";
//     std::cout << std::endl;
//     numbers[1] = 22;
//     std::cout << numbers[1] << " ";
//     std::cout << std::endl;

//     return (0);
// }

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "sssssssssssssssss1" << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        std::cout << "sssssssssssssssss2" << std::endl;
        Array<int> test(tmp);
        std::cout << "sssssssssssssssss2" << std::endl;
    }
    std::cout << "sssssssssssssssss" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    exit (4);
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750



class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    Awesome(int n) : _n( n ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};
int main(int, char**)
{
    try
    {
        /* code */
        Array<int> numbers(MAX_VAL);
        Array<int> numberss;
        Array<Awesome> awesomes(10);
        std::cout << "numbers size = " << numbers.size() << std::endl;
        std::cout << "numberss size = " << numberss.size() << std::endl;
        std::cout << "awesome size = " << awesomes.size() << std::endl;
        awesomes[2] = Awesome(1337);
        std::cout << "value of awesomes[1] = " << awesomes[1].get() << std::endl;
        std::cout << "value of awesomes[2] = " << awesomes[2].get() << std::endl;
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
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
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    return 0;
}
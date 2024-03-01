#include <iostream>
#include <limits>

int get_year(int date)
{
    return (date >> 12);
}
int get_month(int date)
{
    return ((date - (date >> 12)) >> 4);
}


int main(void)
{
    int date = 0;
    int year = 2001;
    int month = 12;
    int day = 31;

    date =  year;
    date = (date << 8) | month;
    date = (date << 4) | day;
    std::cout << " date = " << date << std::endl;

    std::cout << "year =  " << get_year(date) << std::endl;
    std::cout << "year =  " << get_month(date) << std::endl;
    std::cout << " date = " << date << std::endl;
    return (0);
}
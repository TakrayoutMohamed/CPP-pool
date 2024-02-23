#include <iostream>
#include <tuple>

int main(void)
{
    std::tuple<int, int, int> tuple1;
    std::tuple<int, std::string, std::string> tuple2;

    tuple1 = std::make_tuple(1, 2, 3); //insert 1, 2, 3 to the tuple
    tuple2 = std::make_tuple(1, "Student1337", "Fuck you");

    int id;
    std::string firstName, lastName;

    std::tie(id, firstName, lastName) = tuple2;
    std::cout << "first name : " << firstName << " last name : " << lastName << std::endl;
    return (0);
}
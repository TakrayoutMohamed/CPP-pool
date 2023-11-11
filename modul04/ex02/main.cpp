#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// void foo(void)
// {
//     system("leaks brain");
// }
int main(void)
{
    // atexit(foo);
    const Animal *animals[4];

    animals[0] = new Cat();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Dog();

    std::cout << "***************************************"<< std::endl;
    for (int k = 0; k < 4; k++)
    {
        std::cout << "{" << std::endl;
        std::cout << "type of the animal nbr "<< k + 1 << "= "<< animals[k]->getType() << std::endl;
        std::cout << "the sound of the " << animals[k]->getType() << " is " << std::endl;
        animals[k]->makeSound();
        std::cout << "}" << std::endl;
    }
    
    std::cout << "***************************************"<< std::endl;
    for (int k = 0; k < 4; k++)
    {
        delete animals[k];
    }
    std::cout << "***************************************"<< std::endl;
    {
        // Animal meta;
        // std::cout << "the type of the animal meta is : " << meta.getType() << std::endl;
    }
    return 0;
}
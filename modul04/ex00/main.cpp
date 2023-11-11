#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// void foo(void)
// {
//     system("leaks animals");
// }

int main(void)
{
    // atexit(foo);
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " here is dog" << std::endl;
    std::cout << i->getType() << " here is cat" << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete i;
    delete j;
    delete meta;

    std::cout << "***************************************"<< std::endl;
    const WrongAnimal* meta1 = new WrongAnimal();
    const WrongAnimal* i1 = new WrongCat();
    std::cout << i1->getType() << " here is the wrong cat" << std::endl;
    i1->makeSound(); //should output the cat sound!
    meta1->makeSound();
    delete i1;
    delete meta1;
    return 0;
}
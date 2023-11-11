#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    /*
    *
    *
    * 
    * i SHOULD ADD THE MAKE FILE FLAGS BEFOR PUSH
    * 
    * 
    * */
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete i;
    delete j;
    delete meta;

    std::cout << "***************************************"<< std::endl;
    const WrongAnimal* meta1 = new WrongAnimal();
    const WrongAnimal* i1 = new WrongCat();
    std::cout << i1->getType() << " " << std::endl;
    i1->makeSound(); //will output the cat sound!
    meta1->makeSound();
    delete i1;
    delete meta1;
    return 0;
}
#include <iostream>
#include <exception>
using namespace std;


class Base
{
    public :
    Base()
    {
        std::cout << "Default constructor of Base class" << std::endl;
    }
    virtual void doSomething()
    {
        std::cout << "Do Something m******* in Base" <<  std::endl;
    }
};

class Derived : public Base
{
    public :
        Derived ()
        {
            std::cout << "Default constructor of Drived class" << std::endl;
        }
        void doSomething()
        {
            std::cout << "Do Something m******* in Derived" <<  std::endl;
        }
        void doSomething2()
        {
            std::cout << "Do Something2 good boy in Derived" <<  std::endl;
        }
};

void leaks(void)
{
    system("leaks a.out");
}

int main()
{
    leaks();
    // Base    ba;
    // Derived da;
    
    // Base * pba;
    // Derived * pda;

    // pba = dynamic_cast <Base *> (&da);       //cast from derived to base
    // pda = dynamic_cast <Derived *> (&ba);    //cast from base to drived
    // std::cout << "******************" <<std::endl;
    // pba->doSomething();
    // std::cout << "******************" <<std::endl;
    // pda->doSomething2();
    // pda->doSomething();
    // std::cout << "******************" <<std::endl;
    try {
        Base * pba = new Derived;
        Base * pbb = new Base;
        Derived * pd;
        
        pd = dynamic_cast<Derived *>(pba);//base to Derived using a pointer that created by an instence of Derived class
        if (pd==0)
            cout << "Null pointer on first type-cast" << endl;
        pd = dynamic_cast<Derived *>(pbb); //base to Derived using a pointer that created by an instence of Base class
        if (pd==0)
            cout << "Null pointer on second type-cast" << endl;
        pd->doSomething();
    } catch (exception& e) 
    {
        std::cout << "Exception: " << e.what();
    }
    return (0);
}
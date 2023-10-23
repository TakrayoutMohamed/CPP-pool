#include <iostream>
#include "./Contact.hpp"

Contact::Contact(/* args */)
{
	std::cout << "Constructor called Contact" << std::endl;
	return ; 
}

Contact::~Contact()
{
	std::cout << "Destructor called Contact" << std::endl;
	return ; 
}

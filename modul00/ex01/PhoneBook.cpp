#include <iostream>
#include "./PhoneBook.hpp"

PhoneBook::PhoneBook(/* args */)
{
	std::cout << "Constructor called PhoneBook" << std::endl;
	return ; 
}

PhoneBook::~PhoneBook()
{
	std::cout << "Destructor called PhoneBook" << std::endl;
	return ; 
}

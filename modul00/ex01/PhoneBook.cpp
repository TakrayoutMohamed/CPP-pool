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

void	PhoneBook::printPhoneBook()
{
	int	i;

	i = 0;
	std::cout << "-------------------------PHONE BOOK--------------------------------"<<std::endl;
	std::cout << "|Id        |FirstName |LastName  |NickName  |Number    |DarkSecret|"<<std::endl;
	std::cout << "-------------------------------------------------------------------"<<std::endl;
	while (i < 2)
	{
		this->contacts[i].printContact();
		i++;
	}
	std::cout << "-------------------------------------------------------------------"<<std::endl;
}

void PhoneBook::addContact(int id)
{
	std::string	str;

	this->contacts[id].setId(id);
	do {
		std::cout << "Enter the first Name: ";
		std::getline (std::cin, str);
		this->contacts[id].setFirstName(str);
		std::cout << std::endl;
	} while (str.empty());
	do {

		std::cout << "Enter the last Name: ";
		std::getline (std::cin, str);
		this->contacts[id].setLastName(str);
		std::cout << std::endl;
	} while (str.empty());
	do {
		std::cout << "Enter the Nick Name : ";
		std::getline (std::cin, str);
		this->contacts[id].setNickName(str);
		std::cout << std::endl;
	} while (str.empty());
	do {
		std::cout << "Enter the Phone Number : ";
		std::getline (std::cin, str);
		this->contacts[id].setPhoneNumber(str);
		std::cout << std::endl;
	} while (str.empty());
	do {
		std::cout << "Enter the darkest Secret : ";
		std::getline (std::cin, str);
		this->contacts[id].setDarkSecret(str);
		std::cout << std::endl;
	} while (str.empty());
}

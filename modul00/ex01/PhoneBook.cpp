#include <iostream>
#include "./PhoneBook.hpp"

PhoneBook::PhoneBook(/* args */)
{
	this->contactNbr = 0;
	this->id = 0;
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
	std::cout << "-------------------------PHONE BOOK----------"<<std::endl;
	std::cout << "|index     |FirstName |LastName  |NickName  |"<<std::endl;
	std::cout << "---------------------------------------------"<<std::endl;
	while (i < this->contactNbr)
	{
		this->contacts[i].printContact();
		i++;
	}
	std::cout << "---------------------------------------------"<<std::endl;
}

void	PhoneBook::searchContactById(int id)
{
	if (id < this->contactNbr)
	{
		std::cout << "First Name    : " << this->contacts[id].getFirstName();
		std::cout << std::endl;
		std::cout << "Last Name     : " << this->contacts[id].getLastName();
		std::cout << std::endl;
		std::cout << "Nick Name     : " << this->contacts[id].getNickName();
		std::cout << std::endl;
		std::cout << "Phone Number  : " << this->contacts[id].getPhoneNumber();
		std::cout << std::endl;
		std::cout << "Dark Secret   : " << this->contacts[id].getDarkSecret();
		std::cout << std::endl;
	}
	else
		std::cout << "index you entered not available ."<< std::endl;
}

void PhoneBook::addContact(void)
{
	std::string	str;

	this->id = this->id % 8;
	if (this->contactNbr > this->id)
	{
		this->contacts[this->id].setFirstName("");
		this->contacts[this->id].setLastName("");
		this->contacts[this->id].setNickName("");
		this->contacts[this->id].setPhoneNumber("");
		this->contacts[this->id].setDarkSecret("");
	}
	if (this->contactNbr < 8)
		this->contactNbr++;
	this->contacts[this->id].setId(this->id + 1);
	do {
		std::cout << "Enter the first Name    : ";
		std::getline (std::cin, str);
		this->contacts[this->id].setFirstName(str);
		std::cout << std::endl;
	} while (str.empty());
	do {
		std::cout << "Enter the last Name     : ";
		std::getline (std::cin, str);
		this->contacts[this->id].setLastName(str);
		std::cout << std::endl;
	} while (str.empty());
	do {
		std::cout << "Enter the Nick Name     : ";
		std::getline (std::cin, str);
		this->contacts[this->id].setNickName(str);
		std::cout << std::endl;
	} while (str.empty());
	do {
		std::cout << "Enter the Phone Number  : ";
		std::getline (std::cin, str);
		this->contacts[this->id].setPhoneNumber(str);
		std::cout << std::endl;
	} while (str.empty());
	do {
		std::cout << "Enter the darkest Secret: ";
		std::getline (std::cin, str);
		this->contacts[this->id].setDarkSecret(str);
		std::cout << std::endl;
	} while (str.empty());
	this->id++;
}

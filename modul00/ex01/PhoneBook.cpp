#include <iostream>
#include "./PhoneBook.hpp"

PhoneBook::PhoneBook(/* args */)
{
	this->contactNbr = 0;
	this->id = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

void	PhoneBook::printPhoneBook()
{
	int	i;

	i = 0;
	std::cout << "-------------------------PHONE BOOK----------"<<std::endl;
	std::cout << "|     Index| FirstName|  LastName|  NickName|"<<std::endl;
	std::cout << "---------------------------------------------"<<std::endl;
	while (i < this->contactNbr)
	{
		this->contacts[i].printContact();
		i++;
	}
	std::cout << "---------------------------------------------"<<std::endl;
}

int	PhoneBook::getIdToSearch(void)
{
	std::string	nbr;

	std::cout << "Enter the id of the contact to search ."<< std::endl;
	std::getline(std::cin, nbr);
	if (std::cin.eof())
		exit(1);
	if (nbr.length() > 1)
		return (-1);
	return (nbr[0] - '0');
}

void	PhoneBook::searchContactById(void)
{
	int	id;
	
	id = PhoneBook::getIdToSearch();
	std::cout << "-----------------------------------------------------"<<std::endl;
	if (id - 1 < this->contactNbr && id - 1 >= 0)
	{
		std::cout << "First Name    : " << this->contacts[id - 1].getFirstName();
		std::cout << std::endl;
		std::cout << "Last Name     : " << this->contacts[id - 1].getLastName();
		std::cout << std::endl;
		std::cout << "Nick Name     : " << this->contacts[id - 1].getNickName();
		std::cout << std::endl;
		std::cout << "Phone Number  : " << this->contacts[id - 1].getPhoneNumber();
		std::cout << std::endl;
		std::cout << "Dark Secret   : " << this->contacts[id - 1].getDarkSecret();
		std::cout << std::endl;
	}
	else
		std::cout << "=> Error : Index you entered not available ." << std::endl;
	std::cout << "-----------------------------------------------------"<<std::endl;
}

void PhoneBook::addContact(void)
{
	std::string	str;

	this->id = this->id % 8;
	if (this->contactNbr < 8)
		this->contactNbr++;
	this->contacts[this->id].setId(this->id + 1);
	do {
		std::cout << "Enter the first Name    : ";
		if (!std::getline (std::cin, str))
			exit(0);
		this->contacts[this->id].setFirstName(str);
	} while (str.empty());
	do {
		std::cout << "Enter the last Name     : ";
		if (!std::getline (std::cin, str))
			exit(0);
		this->contacts[this->id].setLastName(str);
	} while (str.empty());
	do {
		std::cout << "Enter the Nick Name     : ";
		if (!std::getline (std::cin, str))
			exit(0);
		this->contacts[this->id].setNickName(str);
	} while (str.empty());
	do {
		std::cout << "Enter the Phone Number  : ";
		if (!std::getline (std::cin, str))
			exit(0);
		this->contacts[this->id].setPhoneNumber(str);
	} while (str.empty());
	do {
		std::cout << "Enter the darkest Secret: ";
		if (!std::getline (std::cin, str))
			exit(0);
		this->contacts[this->id].setDarkSecret(str);
	} while (str.empty());
	this->id++;
}

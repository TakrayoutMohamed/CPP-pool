#include "./Contact.hpp"
#include "./PhoneBook.hpp"
#include <string>
#include <iostream>
#include <cctype>

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	while (1)
	{
		std::cout << "Enter :" << std::endl;
		std::cout << "		 ADD    : save a new contact" << std::endl;
		std::cout << "		 SEARCH : display a specific contact" << std::endl;
		std::cout << "		 EXIT   : exit the program" << std::endl;
		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD")
			phoneBook.addContact();
		else if (command.compare("SEARCH") == 0)
		{ 
			phoneBook.printPhoneBook();
			phoneBook.searchContactById();
		}
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout << "the program accept only : ADD, SEARCH, EXIT"<< std::endl;

	}
	return (0);
}

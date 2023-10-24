#include "./Contact.hpp"
#include "./PhoneBook.hpp"
#include <string>
#include <iostream>
#include <cctype>

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;
	int			id;

	id = 0;
	do {
		std::cout << "Enter :" << std::endl;
		std::cout << "ADD: to save a new contact" << std::endl;
		std::cout << "SEARCH: display a specific contact" << std::endl;
		std::cout << "EXIT: to exit the program" << std::endl;
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0)
		{
			phoneBook.addContact(id % 8);//still need to work on this add contact 
			id++;
		}
		else if (command.compare("SEARCH") == 0)
		{ 
			phoneBook.printPhoneBook();
		}
		else if (command.compare("EXIT") == 0)
		{
			break ;
		}

	} while (1);

	return (0);
}

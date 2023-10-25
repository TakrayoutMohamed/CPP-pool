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
		if (!std::getline(std::cin, command))
			exit(0);
		if (command == "ADD")
		{
			phoneBook.addContact();
		}
		else if (command.compare("SEARCH") == 0)
		{ 
			phoneBook.printPhoneBook();
			std::cout << "Enter the id of the contact to search ."<< std::endl;
			std::cin >> id;
			phoneBook.searchContactById(id);
		}
		else if (command.compare("EXIT") == 0)
		{
			break ;
		}
		else
		{
			std::cout << "the program accept only : ADD, SEARCH, EXIT"<< std::endl;
		}

	} while (1);

	return (0);
}

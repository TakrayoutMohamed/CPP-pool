#include "./Contact.hpp"
#include "./PhoneBook.hpp"
#include <string>
#include <iostream>
#include <cctype>

int	main(void)
{
	PhoneBook phoneBook;

	phoneBook.addContact(0);
	phoneBook.addContact(1);
	phoneBook.printPhoneBook();

	return (0);
}

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "./Contact.hpp"
class PhoneBook
{
	private:
		Contact contacts[8];
	public:
		PhoneBook(/* args */);
		~PhoneBook();
		void	addContact(int id);
		void	printPhoneBook();
};

#endif

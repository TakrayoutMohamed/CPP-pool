#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "./Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		contactNbr;
		int		id;
	public:
		PhoneBook(/* args */);
		~PhoneBook();
		void	addContact(void);
		void	searchContactById(void);
		void	printPhoneBook();
	private:
		int	getIdToSearch(void);
};

#endif

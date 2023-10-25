#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
	private:
		int	id;
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkSecret;

	public:
		Contact();
		~Contact();

		void		printContact(void);

		void		setId(int id);
		int			getId(void);

		void		setFirstName(std::string firstName);
		std::string	getFirstName(void);

		void		setLastName(std::string lastName);
		std::string	getLastName(void);

		void		setNickName(std::string nickName);
		std::string	getNickName(void);

		void		setPhoneNumber(std::string phoneNumber);
		std::string	getPhoneNumber(void);

		void		setDarkSecret(std::string darkSecret);
		std::string	getDarkSecret(void);
};
#endif

#include <iostream>
#include "./Contact.hpp"

Contact::Contact(/* args */)
{
	std::cout << "Constructor called Contact" << std::endl;
	return ; 
}

Contact::~Contact()
{
	std::cout << "Destructor called Contact" << std::endl;
	return ; 
}

void	printChars(std::string str)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (i < 9 && str[i])
			std::cout << str[i];
		else if (i == 9 && str.length() > 9)
		{
			std::cout << ".";
			break ;
		}
		else
			std::cout << " ";
		i++;
	}
	std::cout << "|";
}

void	Contact::printContact(void)
{
	std::cout << "|";
	std::cout << getId() << "         ";
	std::cout << "|";
	printChars(getFirstName());
	printChars(getLastName());
	printChars(getNickName());
	std::cout << std::endl;
}

/*getters*/

int	Contact::getId()
{
	return (id);
}

std::string	Contact::getFirstName()
{
	return (firstName);
}

std::string	Contact::getLastName()
{
	return (lastName);
}

std::string	Contact::getNickName()
{
	return (nickName);
}

std::string	Contact::getPhoneNumber()
{
	return (phoneNumber);
}

std::string	Contact::getDarkSecret()
{
	return (darkSecret);
}

/*setters*/
void	Contact::setId(int id)
{
	this->id = id;
}

void	Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void	Contact::setNickName(std::string nickName)
{
	this->nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void	Contact::setDarkSecret(std::string darkSecret)
{
	this->darkSecret = darkSecret;
}


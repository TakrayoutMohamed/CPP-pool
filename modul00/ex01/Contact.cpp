#include <iostream>
#include "./Contact.hpp"

Contact::Contact(/* args */)
{
	return ; 
}

Contact::~Contact()
{
	return ; 
}

void	Contact::printChars(std::string str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str.length() < 10)
	{
		while (j < 10 - (int)str.length())
		{
			std::cout << " ";
			j++;
		}
	}
	while (i + j < 10)
	{
		if (i < 9 && str[i])
			std::cout << str[i];
		else if (i == 9 && str.length() > 9)
		{
			std::cout << ".";
			break ;
		}
		i++;
	}
	std::cout << "|";
}

void	Contact::printContact(void)
{
	std::cout << "|";
	std::cout << "         " << getId();
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
	return (this->firstName);
}

std::string	Contact::getLastName()
{
	return (this->lastName);
}

std::string	Contact::getNickName()
{
	return (this->nickName);
}

std::string	Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkSecret()
{
	return (this->darkSecret);
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


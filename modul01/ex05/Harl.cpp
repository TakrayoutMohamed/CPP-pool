#include "./Harl.hpp"

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "DEBUG : "<< std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout << " I really do!";
	std::cout << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO : "<< std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << " You did not put enough bacon in my burger! If you did, I would not be asking for more!";
	std::cout << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING : "<< std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I have been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
}

void Harl::error(void)
{
	std::cout << "ERROR : "<< std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void Harl::complain(std::string level)
{
	typedef void	(Harl::*harlFunc)();
	int	i; 
	harlFunc 	info;
	harlFunc 	debug;
	harlFunc 	error;
	harlFunc 	warning;
	std::string	levels[] = {"INFO", "DEBUG", "ERROR", "WARNING"};

	info = &Harl::info;
	debug = &Harl::debug;
	error = &Harl::error;
	warning = &Harl::warning;
	i = 0;
	while (i < 4 && levels[i] != level)
		i++;
	switch (i)
	{
		case 0:
			(this->*info)();
			break;
		case 1:
			(this->*debug)();
			break;
		case 2:
			(this->*error)();
			break;
		case 3:
			(this->*warning)();
			break;
		default:
			std::cout << "Entered level not accepted"<< std::endl;
		break;
	}
}
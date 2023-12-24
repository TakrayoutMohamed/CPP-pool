#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		/* data */
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(/* args */);
		Bureaucrat(const std::string &, int);
		~Bureaucrat();

	public :
		std::string	getName(void) const;
		int	getGrade(void) const;
};

#endif

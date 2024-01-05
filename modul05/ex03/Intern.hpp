#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		/* data */
	public:
		Intern(/* args */);
		Intern(const Intern &);
		const Intern &operator=(const Intern &);
		~Intern();

		class FormNotExistException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		} FormNotExistException;
		/*member functions*/
		AForm	*makeForm(std::string formName, std::string formTarget) const;

};

#endif

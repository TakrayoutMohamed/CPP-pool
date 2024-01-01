#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <exception>
# include <fstream>
# include "./AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(/* args */);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		const ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
		ShrubberyCreationForm(const std::string &);
		class FileCreationException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		/*getters*/
		std::string getTarget(void) const;
		
		/*member functions*/
		void	shrubberyAction(void) const throw(ShrubberyCreationForm::FileCreationException);
};

#endif

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
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

		/*getters*/
		std::string getTarget(void) const;
		
		/*member functions*/
		void	shrubberyAction(const std::string &) const;
};

#endif

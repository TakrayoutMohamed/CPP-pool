#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "./AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm(/* args */);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &);
		const PresidentialPardonForm &operator=(const PresidentialPardonForm &);
		PresidentialPardonForm(const std::string &);
		/*getters*/
		std::string getTarget(void) const;
		
		/*member functions*/
		void	presidentialPardonAction(void) const;
		void execute(Bureaucrat const & executor) const;
};

#endif

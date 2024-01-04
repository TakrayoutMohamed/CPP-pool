#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "./AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(/* args */);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &);
		const RobotomyRequestForm &operator=(const RobotomyRequestForm &);
		RobotomyRequestForm(const std::string &);
		/*getters*/
		std::string getTarget(void) const;
		
		/*member functions*/
		void	robotomyRequestAction(void) const;
		void execute(Bureaucrat const & executor) const;
};

#endif
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "./AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		/* data */
	public:
		RobotomyRequestForm(/* args */);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &);
		const RobotomyRequestForm &operator=(const RobotomyRequestForm &) const;
		RobotomyRequestForm(const std::string &);
};

#endif
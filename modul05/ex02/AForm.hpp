#ifndef AAFORM_HPP
# define AAFORM_HPP
# include <iostream>
# ifndef BUREAUCRAT_HPP
# include "./Bureaucrat.hpp"
# endif
class Bureaucrat;
class AForm
{
	private:
		/* data */
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		AForm(/* args */);
		AForm(const std::string &, const int, const int);
		AForm(const AForm &);
		const AForm &operator=(const AForm&);
		~AForm();

		/*Exception classes*/
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		} GradeTooLowException;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		} GradeTooHighException;
		/*getters*/
		const std::string &getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		/*member functions */
		void beSigned(const Bureaucrat &);
};
std::ostream &operator<<(std::ostream &,const AForm &);

#endif

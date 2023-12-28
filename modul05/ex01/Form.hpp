#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# ifndef BUREAUCRAT_HPP
# include "./Bureaucrat.hpp"
# endif
class Bureaucrat;
class Form
{
	private:
		/* data */
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		Form(/* args */);
		Form(const std::string &, const int, const int);
		Form(const Form &);
		const Form &operator=(const Form&);
		~Form();

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
std::ostream &operator<<(std::ostream &,const Form &);

#endif

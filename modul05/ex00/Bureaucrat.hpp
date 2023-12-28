#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
// #include <exception>

class Bureaucrat
{
	private:
		/* data */
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(/* args */);
		/*copy constructor*/
		Bureaucrat(const Bureaucrat &);
		/*copy assignment operator*/
		const Bureaucrat &operator=(const Bureaucrat &);
		Bureaucrat(const std::string &, int);
		~Bureaucrat();

	public :
		/*getters*/
		std::string	getName(void) const;
		int	getGrade(void) const;
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
		/*member functions*/
		void	incrementGrade(void);
		void	decrementGrade(void);
};
std::ostream	&operator<< (std::ostream&,const Bureaucrat&);

#endif

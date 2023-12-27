#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# ifdef BUREAUCRAT_HPP
# include "./Bureaucrat.hpp"
# endif
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
			Form(const Form &);
			Form &operator=(const Form&);
			~Form();
			/*getters*/
			const std::string &getName(void) const;
			bool getIsSigned(void) const;
			int getGradeToSign(void) const;
			int getGradeToExecute(void) const;
	};

#endif

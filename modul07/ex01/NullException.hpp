#ifndef NULLEXCEPTION_HPP
# define NULLEXCEPTION_HPP
# include <iostream>
# include <exception>

class NullException : public std::exception
{
    private:
        /* data */
    public:
        virtual const char* what() const throw();
};

#endif

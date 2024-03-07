#ifndef RPN_HPP
# define RPN_HPP
# include <stack>
# include <array>
# include <iostream>
# include <string>
# include <algorithm>

class RPN
{
	private:
		std::stack<int> _data;
		int _number;
		char _operator;
	protected:
	public:
		RPN();
		RPN(const RPN &obj);
		const RPN &operator=(const RPN &operator);
		~RPN();
		/*member functions*/
		

};

#endif
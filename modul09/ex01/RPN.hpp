#ifndef RPN_HPP
# define RPN_HPP
# include <stack>
# include <array>
# include <iostream>
# include <sstream>
# include <string>
# include <algorithm>

class RPN
{
	private:
		std::stack<int> _data;
		int _result;
	public:
		RPN();
		RPN(const RPN &obj);
		const RPN &operator=(const RPN &obj);
		~RPN();
		void reversePolishNotation(const char *str);
	private:
		/*member functions*/
		bool	parseData(const char *str);
		bool	isOperator(const char c) const;
		// bool	isAcceptedNumber(const int nbr) const;
		int		doOperation(const char c);
		
		

};

#endif
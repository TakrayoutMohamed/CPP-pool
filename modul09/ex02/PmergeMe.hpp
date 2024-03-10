#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <exception>
# include <sstream>
# include <string>
# include <algorithm>
# include <vector>
# include <deque>
# include <queue>
# include <list>
# include <set>

class PmergeMe
{
	private:
		std::vector<int> dataVector;
		std::deque<int> dataDeque;
		std::queue<int> dataQueue;
	protected:
	public :
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		const PmergeMe &operator=(const PmergeMe &obj);
		~PmergeMe();
		/*Exception Classes*/
		struct OverflowException : public std::exception
		{
			const char *what() const throw();
		} OverflowException;
		/*member functions*/
		bool parseData(const char *str) ;
		bool isAcceptedArgs(const char *str) const throw();
		void fillDataQue(const char *str)  ;
		int  convertStringToInt(const std::string str) const;


};

#endif

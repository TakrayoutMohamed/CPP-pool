#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <sstream>
# include <string>
# include <algorithm>
# include <vector>
# include <deque>
# include <set>

class PmergeMe
{
	private:
		std::vector<int> dataVector;
		std::deque<int> dataDeque
	protected:
	public :
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		const PmergeMe &operator=(const PmergeMe &obj);
		~PmergeMe();
};

#endif

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
// # include <pair>
# include <list>
# include <set>

class PmergeMe
{
	private:
		std::vector<int> dataVector;
		std::list<int> dataList;
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
		void fillDataQue(const char *str, std::queue<int> &)  ;
		int  convertStringToInt(const std::string str) const;
		template <typename T>
		void	swap(T &a, T &b);
		template <typename T>
		void fillDataToContainer(std::queue<int> data, T &container);
		/*sorting member functions that uses Vector */
		void	sortVector();
		std::vector<std::pair<int, int> > &makePairs(const std::vector<int> &vect, std::vector<std::pair<int, int> > &obj);
		void sortPairAcending(std::vector<std::pair<int, int> > &obj);
		void sortVectorByPairFirst(std::vector<std::pair<int, int> > &obj);
		/*sorting member functions that uses List*/
		
};

template <typename T>
void PmergeMe::fillDataToContainer(std::queue<int> data, T &container)
{
	while (!data.empty())
	{
		container.insert(container.end(), data.front());
		data.pop();
	}
}

template <typename T>
void	PmergeMe::swap(T &a, T &b)
{
	T	c;
	c = a;
	a = b;
	b = c;
}
#endif

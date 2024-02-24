#include "./MutantStack.hpp"
#include <vector>

template <typename S>
void print(S obj)
{
	int i = 0;

	std::cout <<"the size of this class is : "<<  obj.size() << std::endl;
	typename S::iterator it = obj.begin();
	typename S ::iterator ite = obj.end();
	while (it != ite)
	{
		std::cout <<"["<< i<< "] = "<< *it << " , ";
		++it;
		i++;
	}
	std::cout << std::endl;
}

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	//[...]
	print(mstack);
	
	mstack.pop();
	MutantStack<int> s(mstack);
	print(s);
	// MutantStack<int>::iterator mstack;
	return 0;
}
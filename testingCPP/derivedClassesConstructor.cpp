// constructors and derived classes
#include <iostream>
using namespace std;
class mother
{
	public:
		mother ()//default constructor
		{
			cout << "mother: no parameters\n";
		}
		mother (int a) //new constructor that takes int as its parametre
		{
			cout << "mother: int parameter\n";
		}
		~mother()
		{
			cout << "mother destructor called\n";
		}
};
class daughter : public mother
{
	public:
		daughter (int a)
		{
			cout << "daughter: int parameter\n\n";
		}
		~daughter()
		{
			cout << "daughter destructor called\n";
		}
};
class son : public mother
{
	public:
		son (int a) : mother (a)
		{
			cout << "son: int parameter\n\n";
		}
		son () : mother()
		{
			cout << "son: no parameter\n\n";
		}
		~son()
		{
			cout << "son destructor called\n";
		}
};
int main ()
{
	son daniel(0);
	son danielkk;
	daughter cynthia (0);
	return 0;
}
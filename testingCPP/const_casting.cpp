
#include <iostream>
using namespace std;
void print (char * str)
{
	cout << str << endl;
	str[0] = 'a';
	cout << str << endl;
}
int main ()
{
	const char * c = "sample text";
	print ( const_cast<char *> (c) );
	return 0;
}
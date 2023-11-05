// static members in classes
#include <iostream>
using namespace std;
class CDummy {
    public:
        static int n;
        CDummy ()
        {
            n++;
        };
        ~CDummy ()
        {
            n--;
        };
};
int CDummy::n=0;
int main () {
    CDummy a;
    CDummy d;
    {
    }
    CDummy b[5];
    CDummy * c = new CDummy;
    cout << (a.n) << endl;
    a.n = 0;
    cout << (b[3].n) << endl;
    delete c;
    cout << CDummy::n << endl;
    return 0;
} 
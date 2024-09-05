#include <iostream>
using namespace std;

int & preinc(int &);

int main ()
{
int i=6;
i = preinc(i);  // same as ++i, i = 5
 cout << "i is " << i << endl;

}

int& preinc(int& r) 
{
 r++;
 cout << "r after incrementing is " << r << endl;
 int k = r;

    return k; // not returning an alias

}

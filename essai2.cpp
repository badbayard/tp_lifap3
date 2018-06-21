#include <iostream>

using namespace std;

int comb (int n, int p)
{
	int tmp1, tmp2;
	cout <<"calcule du nb de combinaisons de " << p <<"elts parmi " <<endl;

	if ((p==0) || (n==p))
	 return 1;
tmp1 =comb(n-1,p-1);
tmp2 =comb(n-1,p);
return tmp1+tmp2;
}



int main ()
{
	int c;
	c = comb(4,3);
	cout <<"c vaut " <<c << endl;

	return 0;

}

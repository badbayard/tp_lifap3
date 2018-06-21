#include <iostream>

using namespace std;

int comb(int n, int p)
{
	int tmp1, tmp2;
	cout<<"calcul du nb de combinaisons1 de " << p <<"elts parmi " << n << endl ;

	if ((p==0) || (n==p))
		return 1;
	tmp1 = comb(n-1,p-1);
	tmp2 = comb(n-1,p);
	return tmp1 + tmp2;
}

void comb2(int n,int p, int  &result)
{
	int tmp1, tmp2;
	cout <<"calcul du nb de combinaisons2 de " << p <<"elts parmi " << n <<endl;

	if ((p==0) || (n==p))
		result=1;
tmp1=	comb(n-1,p-1);
tmp2=	comb(n-1,p);
	result=tmp1+tmp2;

}

void comb3(int n,int p ,int *result)
{
	int tmp1, tmp2;
	cout <<"calcul du nb de combinaison3 de " << p <<"elts parmi " <<n <<endl;

	if ((p==0) || (n==p))
	*result=1;
	tmp1=comb(n-1,p-1);
	tmp2=comb(n-1,p);
  *result=tmp1+tmp2;
}


int main ()
{
	int c;
	int *a=new int;
	int result;
//	c=comb(4,3);
//	comb2(4,3,result);
	comb3(4,3,&a);
//	cout <<"resulta vaut " << result <<endl;
//	cout <<"c vaut " << c <<endl;
	cout << "a vaut " <<*a <<endl;
	delete a;
	return 0;
}

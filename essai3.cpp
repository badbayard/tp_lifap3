#include <iostream>

using namespace std ;



void prec(int x, int &prec, int &suiv)
{
	prec=x-1;
	suiv=x+1;
}

int main ()
{
	
	int x=5;
	int y=10000;
	int z=100000;
	prec(x,&y,&z);
	cout<<"prec ets : "<<y<<"suivant est : " <<z<<endl;
	
	return 0;
}

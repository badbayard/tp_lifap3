#include <iostream>

using namespace std;

int main (void)
{
	cout <<"taille d'un char " <<sizeof(char)<<endl;
	cout <<"taille d'un int " <<sizeof(int) <<endl;
	cout <<"taille d'un short " << sizeof(short)<<endl;
	cout <<"taille d'un @ " <<sizeof(void*)<<endl;
	cout <<"taille d'un double"<<sizeof(double)<<endl;
  cout <<"taille d'un float"<<sizeof(float)<<endl;

	int a=2;
	int &b=a;
	b=3;
	a=4;
	cout << "la valeur de a est " <<a<<endl;
	cout <<"la valeur de b est " <<b<<endl;

	int x=53;
	int *ptrx =&x;
	*ptrx=*ptrx +2;
	cout <<x<<endl;


	return 0;

}	

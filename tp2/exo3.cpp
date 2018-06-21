#include <iostream>

using namespace std;

int main ()
{

	int a,i;
	cout <<"mettre une taille pour le tableau " <<endl;
	cin >>a;
	int *tab=new int[a];

	cout<<"mettre des valeurs "<<endl;
	for(i=0;i<a;i++)
	{
		cin >>tab[i];
	}

	for(i=0;i<a;i++)
	{
		cout<<tab[i];
	}
	delete []tab;
	return 0;

}	

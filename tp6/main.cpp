#include <iostream>
#include "ElementL.h"
#include "Liste.h"

using namespace std;

int main()
{
	Liste l;
	int i;
//	Cellule c;
	for(i=0;i<10;i++)
	{
		l.ajouterEnTete(i);
	}
	l.afficherGaucheDroite();
	l.afficherDroiteGauche();
	return 0;

}

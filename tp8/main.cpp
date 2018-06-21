#include <iostream>
#include "ElementA.h"
#include "Arbre.h"

using namespace std;

int main ()
{
	Arbre a;
	a.insererElement(4);
	a.insererElement(7);
	a.insererElement(9);
	a.afficherParcoursInfixe();
	return 0;
}

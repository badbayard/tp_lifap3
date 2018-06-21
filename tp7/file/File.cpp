#include <iostream>
#include "File.h"

using namespace std;

File::File():l()
{
}

File::~File()
{
	l.vider();
}

/*
File& File::operator = (const File &f)
{
	l=f.l;
	return *this;
}
*/

unsigned int File::nbElements()const
{
	return l.nbElements();
}

/*
 * bool File::estVide()
 * {
 * 	return l.estVide();
 * }
 *
 * void File::Enfiler(ElementL adr)
 * {
 * 	l.ajouterEnQueue(adr);
 * }
 *
 * void File::defiler()
 * {
 * 	l.supprimerTete();
 * }
 *
 * ElementL File::premierDeLaFile()
 * {
 * 	return l.iemeElement(0);
 * }
 **/


#ifndef _ELEMENT_L
#define _ELEMENT_L

typedef void * ElementL;

void afficherElementL(ElementL e);
/* Postconditions : l'adresse e est affichee a l'ecran sans retour a la ligne */

bool estEgalElementL(ElementL e1, ElementL e2);
/* Resultat : renvoie vrai si e1 est egal a e2, faux sinon */

bool estInferieurElementL(ElementL e1, ElementL e2);
/* Resultat : renvoie vrai si e1 est strictement inferieur a e2, faux sinon */

#endif

#ifndef _ELEMENT_L
#define _ELEMENT_L

typedef int ElementL;

void afficherElementL(ElementL e);

bool estEgalElementL(ElementL e1, ElementL e2);
/* Preconditions : aucune
   Resultat : renvoie vrai si e1 est egal a e2, faux sinon */

bool estInferieurElementL(ElementL e1, ElementL e2);
/* Preconditions : aucune
   Resultat : renvoie vrai si e1 est strictement inferieur a e2, faux sinon */

#endif

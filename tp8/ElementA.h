#ifndef _ELEMENT_A
#define _ELEMENT_A

typedef int ElementA;

void afficherElementA(ElementA e);
/* Preconditions : aucune
   Postconditions : e est affiche a l'ecran sans retour a la ligne
*/

bool estInferieurElementA(ElementA e1, ElementA e2);
/* Preconditions : aucune
   Resultat : vrai si e1 < e2, faux sinon */

bool estSuperieurElementA(ElementA e1, ElementA e2);
/* Preconditions : aucune
   Resultat : vrai si e1 > e2, faux sinon */

bool estSuperieurOuEgalElementA(ElementA e1, ElementA e2);
/* Preconditions : aucune
   Resultat : vrai si e1 >= e2, faux sinon */

bool estEgalElementA(ElementA e1, ElementA e2);
/* Preconditions : aucune
   Resultat : vrai si e1 == e2, faux sinon */

#endif

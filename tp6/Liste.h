#ifndef _LISTE
#define _LISTE

#include "ElementL.h"

struct sCellule {
    ElementL info;
    struct sCellule * suivant;
    struct sCellule * precedent;
};
typedef struct sCellule Cellule;

class Liste {
public:
    /* Donnees membres */
    /* =============== */
    Cellule * prem;
    Cellule * last;

    /* Fonctions membres */
    /* ================= */
    Liste ();
    /* Postcondition : la liste est initialement vide */

    ~Liste ();
    /* Postcondition : la memoire allouee sur le tas est liberee */

    Liste& operator = (const Liste & l);
    /* Postcondition : la liste correspond a une copie de l (mais les 2 listes sont totalement independantes l'une de l'autre) */

    void vider ();
    /* Postcondition : la liste ne contient plus aucune cellule */

    bool estVide () const;
    /* Resultat : vrai si liste vide, faux sinon */

    unsigned int nbElements () const;
    /* Resultat : nombre d'elements contenus dans la liste */

    ElementL iemeElement (unsigned int i) const;
    /* Precondition : la liste n'est pas vide, et 0 <= i < nb elements
       Resultat : valeur du i+1-eme element de la liste, sachant que les elements sont numerotes a partir de 0 */

    void modifierIemeElement (unsigned int i, ElementL e);
    /* Precondition : la liste n'est pas vide, et 0 <= i < nb elements
       Postcondition : e remplace le i+1-eme element de la liste, sachant que les elements sont numerotes a partir de 0 */

    void afficherGaucheDroite () const;
    /* Postcondition : affichage de tous les elements, en commencant par le premier (espacement entre les elements) */

    void afficherDroiteGauche () const;
    /* Postcondition : affichage de tous les elements, en commencant par le dernier (espacement entre les elements) */

    void ajouterEnTete (ElementL e);
    /* Postcondition : e est ajoute en tete de liste */

    void ajouterEnQueue (ElementL e);
    /* Postcondition : e est ajoute en fin de liste */

    void supprimerTete ();
    /* Precondition : la liste n'est pas vide
       Postcondition : la liste perd son premier element */

    int rechercherElement (ElementL e) const;
    /* Resultat : position de la premiere occurrence de e dans la liste (en partant de la gauche),
                  -1 si e n'est pas dans la liste. Les cellules sont numerotees de 0 a n-1, donc une valeur de retour egale a 0
                  signifie que la premiere occurrence de e se trouve dans la premiere cellule de la liste. */

    void insererElement (ElementL e, unsigned int position);
    /* Preconditions : 0 <= position <= nb elements
       Postconditions : une copie independante de e est inseree de sorte qu'elle occupe la position indiquee */

    void trier ();
    /* Postcondition : la liste est triee dans l'ordre croissant des valeurs des elements */

};

#endif

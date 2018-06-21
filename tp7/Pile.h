#ifndef _PILE
#define _PILE

#include "TableauDynamique.h"

class Pile {
public:
    /* Donnees membres */
    /* =============== */
    TableauDynamique t;

    /* Fonctions membres */
    /* ================= */
    Pile ();
    /* Postcondition : la pile est initialement vide */

    ~Pile ();
    /* Postcondition : la memoire allouee sur le tas est liberee */

    Pile (const Pile & p);
    /* Precondition : la pile p est initialisee */
    /* Postcondition : les deux piles ont le meme contenu */

    void empiler (void * adr);
    /* Postcondition : le sommet de la pile est une copie de adr */

    void depiler ();
    /* Precondition : la pile n'est pas vide
       Postcondition : le sommet de la pile est depile ("last in, first out") */

    void * consulterSommet () const;
    /* Precondition : la pile n'est pas vide
       Resultat : l'adresse qui se trouve au sommet de la pile */

    bool estVide () const;
    /* Resultat : vrai si la pile est vide, faux sinon */

    void afficher () const;
    /* Postcondition : les adresses contenues dans la pile sont affiches a l'ecran,
                       en hexadécimal, en commencant par la base de la pile (le sommet est affiche en dernier) */

};

#endif

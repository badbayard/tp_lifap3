#ifndef _ARBRE
#define _ARBRE

#include "ElementA.h"

struct sNoeud {
    ElementA info;
    struct sNoeud * fg;
    struct sNoeud * fd;
};
typedef struct sNoeud Noeud;

class Arbre {
public:

    /* Donnees membres */
    /* =============== */

    Noeud * adRacine;
    int nbElemDansArbre;

    /* Fonctions membres */
    /* ================= */

    Arbre ();
    /* Postcondition : l'arbre est initialement vide */

    ~Arbre ();
    /* Postcondition : la memoire allouee sur le tas est liberee */

    bool estVide () const;
    /* Resultat : vrai si l'arbre est vide, faux sinon */

    void afficherParcoursInfixe () const;
    /* Postcondition : affichage infixe de tous les elements de l'arbre (espacement entre les noeuds) */

    void vider ();
    /* Postcondition : l'arbre est vide */

    void insererElement (ElementA e);
    /* Postcondition : si e n'existe pas deja dans l'arbre, alors un nouveau noeud contenant e est insere,
                       si e existe deja dans l'arbre, alors l'arbre est inchange */

    void rechercherElement (ElementA e, bool * trouve, int * nb_visites) const;
    /* Postcondition : Si aucun noeud de l'arbre ne contient la valeur e, *trouve vaut faux.
                       Si on a trouve un noeud avec le e demande, alors *trouve vaut vrai.
                       Dans les deux cas, nb_visites contient le nombre de noeuds testes lors de cette recherche. */

    int hauteurArbre () const;
    /* Resultat : la hauteur de l'arbre (longueur de sa plus longue branche), ou -1 s'il est vide */

    double profondeurMoyenne () const;
    /* Resultat : la somme des profondeurs de tous les noeuds de l'arbre, divisee par le nombre de noeuds.
                  La profondeur de la racine est 0, celle des fils de la racine est 1, etc. */

};

#endif

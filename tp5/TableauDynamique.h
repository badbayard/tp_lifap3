#ifndef _TAB_DYN
#define _TAB_DYN

#include "ElementTD.h"

class TableauDynamique {
public:
    /* donnees membres */
    /* =============== */
    /* (ne sont pas censees etre connues par l'utilisateur,
        si on avait pu ne pas les faire figurer dans l'interface, on l'aurait fait)
    */
    unsigned int capacite;
    unsigned int taille_utilisee;
    ElementTD * ad;

    /* fonctions membres */
    /* ================= */
    TableauDynamique (); // Constructeur par défaut
    /* Postcondition : le tableau a 1 emplacement alloue mais vide (taille utilisee nulle) */

    TableauDynamique (const TableauDynamique& t); // Constructeur par copie
    /* Precondition : le tableau t est initialise */
    /* Postcondition : l'ancien contenu de l'instance est perdu.
                       Les deux tableaux contiennent des sequences d'ElementTD identiques (copie de t) */

    ~TableauDynamique (); // Destructeur
    /* Postcondition : la memoire allouee dynamiquement est liberee. On ne pourra plus appeler les sous-programmes qui
                       necessitent que le tableau soit initialise */

    void ajouterElement (ElementTD e);
    /* Postcondition : L'element e est ajoute dans le premier emplacement inutilise du tableau,
                       la taille est incrementee de 1. Doublement de la capacite si necessaire. */

    ElementTD valeurIemeElement (unsigned int i) const;
    /* Precondition : 0 <= i < taille utilisee */
    /* Resultat : retourne le i+1eme ElementTD */

    void modifierValeurIemeElement (ElementTD e, unsigned int i);
    /* Precondition : 0 <= i < taille utilisee */
    /* Postcondition : le i+1eme ElementTD vaut e */

    void afficher () const;
    /* Postcondition : Les elements du tableau sont affiches sur la sortie standard (espacement entre les elements)
                       en utilisant la procedure d'affichage de ElementTD */

    void supprimerElement (unsigned int position);
    /* Precondition : le tableau est non vide */
    /* Postcondition : la taille utilisee du tableau est decrementee de 1.
                       Si tailleUtilisee < capacite/3, alors on divise la capacité par 2. */

    void insererElement (ElementTD e, unsigned int i);
    /* Precondition : 0 <= i < taille utilisee */
    /* Postcondition : e est insere en i+1eme position et la taille utilisee est incrementee de 1 */

    void trier ();
    /* Postcondition : le tableau est trie dans l'ordre croissant des valeurs des elements */

    int rechercherElement (ElementTD e) const;
    /* Precondition : le tableau est trie dans l'ordre croissant */
    /* Resultat : indice de l'emplacement qui contient un ElementTD egal a e,
                  -1 si le tableau ne contient pas d'element egal a e */

};

#endif

#ifndef _FILE
#define _FILE

#include "Liste.h"
#include "ElementL.h"

class File {
public:

    /* Donnees membres */
    /* =============== */
    Liste l;

    /* Fonctions membres */
    /* ================= */
    File ();
    /* Postcondition : la file est initialement vide */

    ~File ();
    /* Postcondition : la memoire allouee sur le tas est liberee */

     File& operator = (const File & f);
    /* Postcondition : la file a le meme contenu que f */

    unsigned int nbElements () const;
    /* Resultat : retourne le nombre d'elements presents dans la file */

    void enfiler (void * adr);
    /* Precondition : adr est un pointeur valide
       Postcondition : adr est ajoute en fin de file */

    void defiler ();
    /* Postcondition : l'element de tete de file est supprime ("first in, first out") */

    void * premierDeLaFile () const;
    /* Precondition : la file est non vide
       Resultat : l'adresse qui se trouve en tete de file */

    bool estVide () const;
    /* Resultat : vrai si la file est vide, faux sinon */

};

#endif

#include <iostream>
#include "ElementA.h"
#include "Arbre.h"

using namespace std;

Arbre::Arbre()
{
	adRacine=NULL;
	nbElemDansArbre=0;
}

Arbre::~Arbre()
{
	delete adRacine;
	nbElemDansArbre=0;
}

int insertionAPartirDeCellule(ElementA e,Noeud **N)
{
	if(*N==NULL)
	{
		*N=new Noeud;
		(*N)->info=e;
		(*N)->fg=NULL;
		(*N)->fd=NULL;
		return 1;
	}
	if(e != (*N)->info)
	{
		if(e< (*N)->info)
		{
			insertionAPartirDeCellule(e,&(*N)->fg);
		}
		else
		{
			insertionAPartirDeCellule(e,&(*N)->fd);
		}
	}
		return 0;
}
void Arbre::insererElement(ElementA e)
{
	if(insertionAPartirDeCellule(e,&adRacine))
	 nbElemDansArbre++;
}

/*
 * void Arbre::inserer_rec(Noeud *p,Element e)
 * {
 * 	if(e<p->info)
 * 	{
 * 		if(p->fg !=NULL)
 * 			insere_rec(p->fg,e);
 * 		else
 * 			Noeud * q =new Noeud;
 * 			q->info= e;
 * 			q->fg=NULL;
 * 			q->fd=NULL;
 * 			p->fg=q;
 * 	}
 * 	else
 * 	{
 * 		else if(e>p->info)
 * 		{
 * 			if(p->fd!=NULL){
 * 				inserer_rec(p->fd,e);
 * 			}
 * 			else
 * 			{
 * 				Noeud *q=new Noeud;
 * 				q->info=e;
 * 				q->fg=NULL;
 * 				q->fd=NULL;
 * 				p->fd=q;
 * 			}
 * 		}
 * 	}
 * 	*/




void parcoursNoeudInfixe(Noeud *N)
{
	if(N==NULL);
	else {
		parcoursNoeudInfixe(N->fg);
		afficherElementA(N->info);
		parcoursNoeudInfixe(N->fd);
	}
}

void Arbre::afficherParcoursInfixe() const
{
	parcoursNoeudInfixe(adRacine);
}	

void Arbre::rechercherElement (ElementA e, bool * trouve, int nb_visites) const
{
}	

#include <iostream>
#include "Liste.h"
#include "ElementL.h"

using namespace std;

Liste::Liste()
{
	prem=NULL;
	last=NULL;
}

Liste::~Liste()
{
}

void Liste::ajouterEnTete(ElementL e)
{
	Cellule *p=new Cellule[1];
	p->info=e;
	p->suivant=prem;
	p->precedent=NULL;
	prem=p;
	if(last==NULL)
	{
		last=p;
	}
}

void Liste::ajouterEnQueue (ElementL e)
{
	Cellule *p=new Cellule[1];
	p->info=e;
	p->suivant=NULL;
	p->precedent=last;
	if(prem==NULL)
	{
		prem=p;
	}
	else
	{
	last->suivant=p;
	}

last=p;
}

bool Liste::estVide()const
{
	if (prem !=NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Liste::vider()
{
	Cellule *temp=prem;
	Cellule *tempsuivant;
	if(!temp) return;
	do
	{
		tempsuivant=temp->suivant;
		delete temp;
		temp=tempsuivant;
	}while(temp !=NULL);
}

ElementL Liste:: iemeElement (unsigned int i)const
{
	Cellule *temp=new Cellule[1];
	temp=prem;
	while(--i > 0)
	{
		temp=temp->suivant;
	}
	return temp->info;
}

void Liste::modifierIemeElement (unsigned int i, ElementL e)
{
	Cellule *temp=new Cellule[1];
	temp=prem;
	while(--i > 0)
	{
		temp=temp->suivant;
	}
	temp->info=e;
	if(temp->suivant !=NULL)
		temp->suivant->precedent=temp;
	if(temp->precedent !=NULL)
		temp->precedent->suivant =temp;
}

void Liste::afficherGaucheDroite()const
{
	Cellule *temp=prem;
	int i=0;
	while (temp != NULL)
	{
		afficherElementL(temp->info);
		temp=temp->suivant;
		i++;
	}
}

void Liste::afficherDroiteGauche()const
{
	Cellule *temp=last;
	int i=0;

	while (temp !=NULL)
	{
		afficherElementL(temp->info);
		temp=temp->suivant;
		i++;
	}
}
	
//prof
void Liste::supprimerTete()
{
	Cellule *tmp;
	if(prem !=NULL)
	{
		tmp=prem;
		prem=prem->suivant;
		if(prem!=NULL)
		{
			prem->precedent=NULL;
		}
		else
		{
			last=NULL;
		}
		delete tmp;
	}
}


#include <iostream>
#include "TableauDynamique.h"

using namespace std;

TableauDynamique::TableauDynamique()
{
	capacite = 1;
	taille_utilisee = 0;
	ad =new ElementTD[1];

}

TableauDynamique::TableauDynamique(const TableauDynamique& t)
{
	capacite=t.capacite;
	taille_utilisee=t.taille_utilisee;
	ad=new ElementTD[capacite];

	for(unsigned int i =0 ; i< taille_utilisee ;i++)
	{
		ad[i]=t.ad[i];
  }	
}

TableauDynamique::~TableauDynamique()
{
	if(ad != 0)
	{
		delete []ad;
		ad=0;
		capacite =1 ;
		taille_utilisee=0;
	}
}

void TableauDynamique::ajouterElement (ElementTD e)
{
  unsigned	int i;
	if(capacite == taille_utilisee)
	{
		ElementTD * temp = ad;
		ad = new ElementTD[capacite*2];
		for(i=0; i < capacite ;i++)
		{
			ad[i]=temp[i];
		}
		delete []temp;
		capacite *=2;
	}
	ad[taille_utilisee]=e;
	taille_utilisee++;
}

ElementTD TableauDynamique::valeurIemeElement (unsigned int i )const
{
	return ad[i];
}

void TableauDynamique::modifierValeurIemeElement (ElementTD e, unsigned int i)
{
	ad[i]=e;
}

void TableauDynamique::afficher()const
{
	unsigned int i;
	for(i=0;i<taille_utilisee;i++)
	{
		cout<<ad[i]<<endl;
	}
}

void TableauDynamique::supprimerElement(unsigned int position)
{
	unsigned i,j;
	ElementTD *temp;
	for(i=position;position <taille_utilisee; i++)
	{
		ad[i]=ad[i+1];
		taille_utilisee--;
	}

	if(taille_utilisee < (capacite / 3))
	{
		capacite/=2;
		temp=ad;
		ad=new ElementTD[capacite];

		for(j=0; j<capacite;i++)
		{
			ad[j]=temp[i];
		}
		delete []temp;
	}
}

int TableauDynamique::rechercherElement (ElementTD e) const {
  int debutZR, finZR, milieuZR; /* indices de la zone de recherche */
  bool trouve, fini;
  int res;

  if (taille_utilisee < 1) return -1; // tableau vide
  if ((e < ad[0]) || (e > ad[taille_utilisee-1])) return -1; // l'element recherche n'est pas compris entre le min et le max du tableau

  debutZR = 0;
  finZR = taille_utilisee - 1;
  fini = false;
  trouve = false;
  res = -1;

  while ((!fini) && (!trouve)) {
      milieuZR = (finZR - debutZR)/2 + debutZR;

      if (e == ad[debutZR])     {trouve = true; res = debutZR;}
      if (e == ad[finZR])       {trouve = true; res = finZR;}
      if (e == ad[milieuZR])    {trouve = true; res = milieuZR;}
      if (debutZR == milieuZR)  {fini = true;}

      if ((!trouve) && (!fini)) {
          if(ad[milieuZR] < e) debutZR = milieuZR;
          else finZR = milieuZR;
      }
    }
    return res;
}
		
		

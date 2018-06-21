#include <iostream>
#include "ElementTD.h"
#include "TableauDynamique.h"

using namespace std;


void echange (ElementTD a, ElementTD b)
{
	ElementTD temp;
	temp=a;
	a=b;
	b=temp;
}

bool estPlusPetit(ElementTD a, ElementTD b)
{
	if(a<b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void triParInsertion (TableauDynamique *tab)
{
  unsigned	int i,j;
	ElementTD tmp;
	for(i=1;i<tab->taille_utilisee;i++)
	{
		tmp=tab->valeurIemeElement(i);
		j=i;
		while((j>0)&&(estPlusPetit(tmp,tab->valeurIemeElement(j-1))))
		{
			tab->modifierValeurIemeElement(tab->valeurIemeElement(j-1),j);
			j--;
		}
		tab->modifierValeurIemeElement(tmp,j);
	}
}

void triParselection(TableauDynamique *tab)
{
	ElementTD tmp;
	unsigned int min,i,j;
	for(i=0;i<tab->taille_utilisee-1;i++)
	{
		min=j;
		for(j=i+1;j<=tab->taille_utilisee-1;j++)
		{
			if(estPlusPetit(tab->valeurIemeElement(j),tab->valeurIemeElement(min)))
					{
						min=j;
					}
						tmp=tab->valeurIemeElement(min);
						tab->modifierValeurIemeElement(tab->valeurIemeElement(i),min);
						tab->modifierValeurIemeElement(tmp,i);
					}
	}
}

/*
void trifusion (TableauDynamique *tab)
{
	ElementTD *tmp1;
	unsigned int i,j,k,lg,debutmono1,debutmono2;
	unsigned int nbtraites1,nbtraites2;
	lg=1;

	while(lg<tab->taille_utilisee)
	{
		tmp1=new ElementTD[tab->taille_utilisee];
		debutmono1=0;
		debutmono2=debutmono1+lg;

		while(k<debutmono1+lg)
		{
			tmp1[1]=tab[k];
			k++;
			i++;
		}
		j=debutmono2;
		i=0;
		k=debutmono1=0;
		nbtraites1=0;
		nbtraites2=0;

		while((nbtraites1<lg)&&(nbtraites2<lg)&&(j<taille))
		{
			if(tmp1[i] <tab[j])
			{
				tab->modifierValeurIemeElement(tmp1[i],k);
				i++;
				nbtraites1++;
			}
			else
			{
				tab->modifierValeurIemeElement(tmp1[k],k);
				i++;
				k++;
				nbtraites1++;
			}
		}
		debutmono1+=2*lg;
		debutmono2+=2*lg;
	}
	lg=lg*2;
}
}*/
		





int main ()
{
//	ElementTD e;
	TableauDynamique tab ;
	TableauDynamique tab2;
	tab.ajouterElement(50);
	tab.ajouterElement(40);
	tab.ajouterElement(60);
	tab.ajouterElement(70);
	tab.ajouterElement(33);
/*	cout <<"avant changement " <<endl;
	tab.modifierValeurIemeElement(4,1);
	cout<<"apres changement " <<endl;
	tab.afficher();
	tab.supprimerElement(2);
	tab.afficher();*/

	for (int i=0;i<5;i++)
	{
		tab2.ajouterElement(i);
	}
	
	cout<<"la table avant le tri " <<endl;
	tab.afficher();
	triParselection(&tab);
	cout<<"la table apres le tri"<<endl;
	tab.afficher();



	

	return 0;

}

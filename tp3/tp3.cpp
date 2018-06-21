#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

class nbComplexe
{
	public:
	float re;
	float im;

		
	nbComplexe()
	{
		re=0.0;
		im=0.0;
	}

  nbComplexe( float a,float b)
	{
		re=a;
		im=b;
	}

	nbComplexe(const nbComplexe & nb)
	{
		re=nb.re;
		im=nb.im;
	}

	~nbComplexe()
	{
		cout<<"le nombre complexe est detruit "<<endl;
	}



	void saisir()
	{
		cout<<"saisir la partie reelle " << endl;
		cin >> re;
		cout<<"saisir la partie imaginaire " <<endl;
		cin >>im;
	}

	void affiche()
	{
		if(im>=0)
		{
		cout <<re<<"+"<<im<<"i" <<endl;
		}
		else
		{
			cout<<re <<im <<"i"<<endl;
		}
	}

	void multiplier(const nbComplexe nb2 )
	{
		float tmp;
		tmp=re;
		re=(re*nb2.re-im*nb2.im);
		im=(im*nb2.re+tmp*im);

	}

	float module()
	{
		return sqrt(re*re+im*im);
	}
			
	bool estPlusPetit(nbComplexe nb2)
	{		
		if (module() < nb2.module())
		{
			return true;
		}
		else
		{
			return false;
		}
	}


};

	void tri_par_selection2(nbComplexe *tab,const int taille,float tab2[])
	{
	//	float tab2[taille];
		int i,memory,compt,marqueur;

				for(i=0;i<taille;i++)
				{
					tab2[i]=tab[i].module();
				//œ	cout<<tab2[i]<<endl;
				}

				for(i=1;i<taille;i++)
				{
					memory=tab2[i];
					compt=i-1;

					do
					{
						marqueur=false;
						if (tab2[compt]>memory)
						{
							tab2[compt+1]=tab2[compt];
							compt--;
							marqueur=true;
						}
						if(compt<0) marqueur=false;
					}
					while(marqueur);
					tab2[compt+1]=memory;
				}
	}





void tri_par_selection(nbComplexe *tab,int taille)
{
	int i,j,indmin;
	nbComplexe min;

	for(i=0;i<taille-1;i++)
	{
		indmin=i;
		for(j=1+i;j<=taille-1;j++)
		{
			if(tab[j].estPlusPetit(tab[indmin])==1)
			{
				indmin=j;
			}
		}
		min=tab[indmin];
		tab[indmin]=tab[i];
		tab[i]=min;
	}
}

void tri_par_insertion(nbComplexe *tab,int taille)
{
  nbComplexe complexeAPlacer;
  for (int j=1; j<taille; j++) {
    complexeAPlacer = tab[j];
    int i = j-1;
    while( i>= 0 && complexeAPlacer.estPlusPetit(tab[i]) ) {
      tab[i+1] = tab[i];
      i--;
    }
    tab[i+1]=complexeAPlacer;
  }
}

		


								





int main ()
{



	//test avec 2 nombres complexex pour le module est estpluspetit
/*
	nbComplexe nombrecom;
	nbComplexe nombrecom2(30,58);
	nombrecom.saisir();
	nombrecom.affiche();
	float a=nombrecom.module();
	float b=nombrecom2.module();
	cout <<" le module est du premier est : " <<a <<endl;
	cout <<"le module du deuxieme est : " << b <<endl;
	bool e=nombrecom.estPlusPetit(nombrecom2);
	cout <<e <<endl; */



//le tri avec les chiffres aléatoire


	
	int taille,i;
	int min = -10;
	int max =10;
	cout<<"mettre une taille de tableau " <<endl;
	cin >>taille;
//	float tab2[taille];
	nbComplexe *tab=new nbComplexe[taille];

	srand((unsigned int)time(NULL));

	for(i=0;i<taille;i++)
	{
		tab[i].re=(2*(rand()%(max+1))+min);
	 	tab[i].im=(2*(rand()%(max+1))+min);
	}


/*	for(i=0;i<taille;i++)
	{
		tab[i].affiche();
	}	
	cout<<"le module du tableau : " <<endl;
*/
		tri_par_insertion(tab,taille);
//	tri_par_selection(tab,taille);
/*	for(i=0;i<taille;i++)
	{
		cout<<"tableau ordonnee "<<tab2[i]<<endl;
	}
*/
//	remet_dans_ordre(tab,taille,tab2);
	
	for(i=0;i<taille;i++)
	{
		tab[i].affiche();
	}





		

//	nbComplexe *autrenombre3=new nbComplexe[taille];
//	autrenombre2->saisir();
//	nbComplexe autrenombre(8,-5);
//	autrenombre2->affiche();
	//nombrecom.multiplier(autrenombre);

//	int b=nombrecom.estPlusPetit(autrenombre);
//	cout <<b<<endl;


//	nombrecom.affiche();

	

//	nombrecom.saisir();
//	nombrecom.affiche();
//	nombrecom.multiplier(autrenombre);
//	nombrecom.affiche();
//	int a=sizeof(nombrecom);
//	cout<<"la taille en octet est de : " <<a<<endl;
	
//	delete autrenombre2;
		delete []tab;
//		delete tab2;
	return 0;

}

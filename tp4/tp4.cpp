#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string>

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

	float module() const
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

	void operator =(const  nbComplexe& nbdroite)
	{
		re=nbdroite.re;
		im=nbdroite.im;
	}

const	bool  operator <( const nbComplexe& nbdroite)
	{
		if (module()<nbdroite.module())
		{
			return true;
		}
		else
		{
		return false;
		}
	}

	nbComplexe operator *(nbComplexe& nb2)
	{
		nbComplexe result;
		float tmp;
		tmp=re;
		re=(re*nb2.re-im*nb2.im);
		im=(im*nb2.re+tmp*im);
		result.re=re;
		result.im=im;
		return result;
	}

friend ostream& operator <<(ostream& flux,nbComplexe nb)
	{
		
					if(nb.im>=0.0)
		{
		flux <<nb.re<<"+"<<nb.im<<"i" <<endl;
		}
		else
		{
			flux<<nb.re <<nb.im <<"i"<<endl;
		}
		return flux;
	}

friend istream& operator >>(istream& flux ,nbComplexe& nb)
{
		string chaine;
		flux >> nb.re;
		flux >> nb.im;
		flux >>chaine;
		return flux;
}



};

/*	void tri_par_selection2(nbComplexe *tab,const int taille,float tab2[])
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
*/




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

void tri_par_selection2(nbComplexe *tab,int taille)
{
	int i,j,indmin;
	nbComplexe min;

	for(i=0;i<taille-1;i++)
	{
		indmin=i;
		for(j=1+i;j<=taille-1;j++)
		{
			if((tab[j]<tab[indmin])==1)
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

void tri_par_insertion2(nbComplexe *tab,int taille)
{
  nbComplexe complexeAPlacer;
  for (int j=1; j<taille; j++) {
    complexeAPlacer = tab[j];
    int i = j-1;
    while( i>= 0 && complexeAPlacer < tab[i] ) {
      tab[i+1] = tab[i];
      i--;
    }
    tab[i+1]=complexeAPlacer;
  }
}




void ouvrire_fichier(char nomfichier[],int taille)
{
	int nbligne;
	ifstream random;
	random.open(nomfichier);

	if(random.is_open()){}
	else{cout << "erreur";}
	random >> nbligne;
	cout <<nbligne<<endl;
}



		

/*
void remplir(FILE *fichier, nbComplexe *tab)
{
	int i=0;
	while(fscanf(fichier,"%f %f",&tab[i].re,&tab[i].im)==2)
	{
		i++;
	}
}
*/

void lireTabNbComplexeDepuisFichier(nbComplexe *tab,int taille, char nom[])
{
//	ifstream fichier(nom);
//	float chiffre;
		FILE* fichier=NULL;
		fichier =fopen(nom,"r");
		


	if (fichier != NULL)
	{
	  fseek(fichier,5,SEEK_SET);
	
		for(int i=0;i<taille;i++)
		{
			fscanf(fichier,"%f %f",&tab[i].re,&tab[i].im);

		}
		fclose(fichier);
	}

	else
	{
		cout <<"erreur"<<endl;
	}



}


void ecrireTabNbComplexeDansFichier(char *fichier, nbComplexe *tab,int taille)
{
	FILE *f=fopen(fichier,"w");

	if(f==NULL)
	{
		fprintf(f,"probleme d'affichage de %s\n",fichier);
		exit(EXIT_FAILURE);
	}
	
	for(int i=0;i<taille;i++)
	{
		fprintf(f,"%f %f\n",tab[i].re,tab[i].im);
	}
	fclose(f);
}
		

void trifusion (nbComplexe *tab,int taille)
{
	nbComplexe *tmp1;
	int i,j,k,lg,debutmono1,debutmono2;
	int nbtraites1,nbtraites2;
	lg=1;

	while(lg<taille)
	{
		tmp1 =new nbComplexe[taille];
		debutmono1=0;
		debutmono2=debutmono1+lg;

		while(debutmono2<taille)
		{
			k=debutmono1;
			i=0;
			while(k<debutmono1+lg)
			{
				tmp1[i]=tab[k];
				k++;
				i++;
			}
			j=debutmono2;
			i=0;
			k=debutmono1;
			nbtraites1=0;
			nbtraites2=0;

			while(( nbtraites1<lg)&&(nbtraites2<lg)&&(j<taille))
			{
				if(tmp1[i] < tab[j])
				{
					tab[k]=tmp1[i];
					i++;
					nbtraites1++;
				}
				else
				{
					tab[k]=tab[j];
					j++;
					nbtraites2++;
				}
				k++;
			}
			if((nbtraites2==lg)||(j==taille))
			{
				while(nbtraites1<lg)
				{
					tab[k]=tmp1[i];
					i++;
					k++;
					nbtraites1++;
				}
			}
			debutmono1+=2*lg;
			debutmono2+=2*lg;
		}
		//mettre la liberation
		lg=lg*2;
	}
}
			

								





int main ()
{
/*	nbComplexe nb(5,2);
	nbComplexe nb2(3,3);
	nbComplexe nb3(2,9999);*/

	int taille=20000;
	char nom[]="random.txt";
	char nom2[]="essai.txt";
	nbComplexe *tab=new nbComplexe[taille];
		lireTabNbComplexeDepuisFichier(tab,taille,nom);
	cout<<taille <<endl;
	trifusion (tab,taille);

//	tri_par_insertion2(tab,taille);

	for(int i=0;i<taille;i++)
	{
		tab[i].affiche();
	}


	ecrireTabNbComplexeDansFichier(nom2,tab,taille);
	//delete []tab;
	







/*	nb.affiche();
	cin >>nb3;
 // nb3=nb*nb2;
//	nb.affiche();
	nb3.affiche();

	cout << nb2;
//	cout << nb;
	bool a;
	a=nb2<nb;
	cout<<"la valeur de a est "<<a <<endl;

	int taille=0;
  ouvrire_fichier("texte.txt",taille); */






/*
	//pour les tris 
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



	tri_par_insertion2(tab,taille);

		for(i=0;i<taille;i++)
	{
		tab[i].affiche();
	}*/

	return 0;

}

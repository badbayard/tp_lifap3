#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Vecteur3D
{
	float x;
	float y;
	float z;
}; 

/*struct tabVecteur3D
{
	struct Vecteur3D[];
}; */


float Vecteur3DGetNorme (struct Vecteur3D vect )
{
	float norme;
	norme=sqrt(vect.x*vect.x+vect.y*vect.y+vect.z*vect.z);
	return norme;
}

void Vecteur3DNormaliser(struct Vecteur3D *vect)
{
	vect->x=vect->x/Vecteur3DGetNorme(*vect);
	vect->y=vect->y/Vecteur3DGetNorme(*vect);
	vect->z=vect->z/Vecteur3DGetNorme(*vect);
}

bool Vecteur3DEstNormalise (struct Vecteur3D vect)
{
	return( Vecteur3DGetNorme(vect) == 1);
}

struct Vecteur3D  Vecteur3DAdd (struct Vecteur3D v1,struct Vecteur3D v2)
{
	struct Vecteur3D vectsomme;
	vectsomme.x=v1.x+v2.x;
	vectsomme.y=v1.y+v2.y;
	vectsomme.z=v1.z+v2.z;
	return vectsomme;
}

void Vecteur3DAfficher (struct Vecteur3D vect)
{
	cout <<"le vecteur x= " <<vect.x<<endl;
	cout <<"le vecteur y= " <<vect.y<<endl;
	cout <<"le vecteur z= " <<vect.z<<endl;
}

void Vecteur3DRemplirTabVecteurs (Vecteur3D tab[],int taille)
{
	int i;
	int min=-10;
	int max=10;

	srand((unsigned int)time(NULL));

	for(i=0;i<taille;i++)
	{
		tab[i].x =rand() %(max-min);
		tab[i].y=rand() %(max-min);
		tab[i].z=rand() %(max-min);
	}
}

void Vecteur3DAfficherTabVecteurs (Vecteur3D tab[], int taille)
{
	int i;
	for (i=0;i<taille;i++)
	{
		cout <<"vec"<<i<<tab[i].x<<", "<<tab[i].y<<", " <<tab[i].z<<endl;
	}
}

int Vecteur3DMaxTabVecteurs(Vecteur3D tab[], int taille)
{
	int i;
	int max=0;
	for(i=0;i<taille;i++)
	{
		if(tab[i]>max)
		{
			max=i;
		}
	}
	return max;
}






int main ()
{
 /*struct Vecteur3D vect={ 5, 4, 6};
 bool a;*/
 struct  Vecteur3D vecteur1 = {5,2,1};
 struct  Vecteur3D vecteur2 = {0,3,2};
 cout << "vecteur1 non normalise: ";
 Vecteur3DAfficher (vecteur1);
 cout << endl;

 cout <<"vecteur2 non normalise: " ;
 Vecteur3DAfficher (vecteur2);
 cout <<endl;

 cout <<"somme: ";
 Vecteur3DAfficher(Vecteur3DAdd(vecteur1, vecteur2));
 cout <<endl;

 Vecteur3DNormaliser(&vecteur1);
 Vecteur3DNormaliser(&vecteur2);

 cout <<"vecteur1 normalise : ";
 Vecteur3DAfficher(vecteur1);
 cout<<endl;

 cout<<"vecteur2 normalise: ";
 Vecteur3DAfficher(vecteur2);
 cout <<endl;

 cout <<"somme: ";
 Vecteur3D somme = Vecteur3DAdd(vecteur1, vecteur2);
 Vecteur3DAfficher(somme);
 if (Vecteur3DEstNormalise(somme)) cout<<" est normalise" <<endl;
 else cout <<"n'est pas normalise " <<endl;
	 return 0;


	 
/* float norme= Vecteur3DGetNorme(vect);
 cout <<"la norme est " << norme <<endl ;
 Vecteur3DNormaliser(&vect);
 a=Vecteur3DEstNormalise(vect);
 cout <<a<<endl;
 Vecteur3DAfficher(vect); */

}

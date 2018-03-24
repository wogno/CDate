#include "utils.h"

void insererEmploye(Cemploye *tab, int &i)
{

}

void rechercherEmplpoye(Cemploye *tab, int i)
{
  for(int d=0; d<t; 

}

void supprimerEmploye(Cemploye *tab, int &i)
{

}



void listeRetraite(Cemploye *tab, int i)
{

}

void masseSalariale(Cemploye *tab, int i)
{
  double sum=0;
 for (int d=0; d<i; d++)
   {
      sum+=tab[d].calculerSalaire();
   }
  cout<<"La masse salariale: "<<sum<<endl;
  

}

void calculeSalaireEmp(Cemploye *tab, int i)
{

}

void fonctionnaire(Cemploye *tab, int i)
{
  int nb=0;
  for(int d=0; d<i; d++)
    {
    if(!tab[d].estAuxiliaire())
      {
      nb++;
    }
    }
  cout<<" Le rapport des fonctionnaire est de : "<<endl;


}

void conges(Cemploye *tab, int i)
{

}

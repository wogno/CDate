#include "utils.h"

void insererEmploye(Cemploye tab[], int &i)
{
  string nom_, prenom_, fonction_;
  Status status_;
  CDate dateN, dateE;
  cout <<"Entrer le nom et le prenom  et votre fonction :"<<endl;
  cin>>nom_>>prenom_>>fonction_;
  cout <<"data naissance :"<<endl;
  //cin>>dateN;
  cout <<"Venez vous d'etre embauche \n1: Oui \n2: Non "<<endl;
  int choix ;
  cin>>choix;
  if(!choix)
    cin>> dateE;
  cout <<"";;// demander les renseignement sur l employe
  
    
}

void rechercherEmplpoye(Cemploye tab[], int i)
{
  string nom_;
  cout>>nom_;
  for(int d=0; d<i; d++)
    {
    if (tab[d].getNom() == nom_)
      {
      tab[d].afficher();
      break;// verifier si l employer est unique 
    }
    
  }

}

void supprimerEmploye(Cemploye tab[], int &i)
{
  string matricule_;
  cout <<"entrer votre numero matricule";
  for(int d=0; d<i; d++){
    if(tab[d].getMatricule() == matricule_)
      {
        for(int t=d; t<i; t++)
          {
            tab[t] = tab[t+a'1]
          }
         i--;
      break;
      }
      

}
}



void listeRetraite(Cemploye *tab, int i)
{
  for(int d=0; d<i; d++)
    {
       if (tab[d].dateRetrait().getAnnnee() == CDate().getAnnee)
         {
         tab[i].afficher();
         cout <<"______________ _______  ____ __ "<<endl;
         }
    }
  

}

void masseSalariale(Cemploye tab[], int i)
{
  double sum=0;
 for (int d=0; d<i; d++)
   {
      sum+=tab[d].calculerSalaire();
   }
  cout<<"La masse salariale: "<<sum<<endl;
  

}

void calculeSalaireEmp(Cemploye tab[], int i)
{

}

void fonctionnaire(Cemploye tab[], int i)
{
  int nb=0;
  for(int d=0; d<i; d++)
    {
    if(!tab[d].estAuxiliaire())
      {
      nb++;
    }
    }
  cout<<" Le rapport des fonctionnaire est de : "<<(nb/i)*100<<endl;


}

void conges(Cemploye tab[], int i)
{

}

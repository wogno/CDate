#include "cemploye.h"

const double Cemploye::SALAIRE_BASE_FONCTIONNAIRE_PROTECTION_SOCIAL=0.0275;
const double Cemploye::SALAIRE_BASE_FONCTIONNAIRE_RETRAIT = 0.06;
const double Cemploye::PROTECTION_AUXILIAIRE_INF=0.05;
const double Cemploye::PROTECTION_AUXILIAIRE_SUP=0.067;
const double Cemploye::PLAFOND_AUGMENTE = 0.015;
const double Cemploye::TAUX_HORAIRE = 0.02;
const double Cemploye::TAUX_HORAIRE_MAJORE = 0.025;
const int Cemploye::MAXHEURE = 100;
const double Cemploye::PLAFOND_FIXE=200000;

const double Cemploye::SALAIRE_BASE=200000;

Cemploye::Cemploye()
    :matricule("MDHBSSO")
{

    nom="";
    prenom ="";
    dateNaissance = CDate(1, 1, 2000);
    dateEmbauche  = CDate();
    fonction ="";
    salaireBase = PLAFOND_FIXE;
    status == auxiliaire;



}

Cemploye::Cemploye(string matricule_, string nom_, string prenom_, string adres, string fonction_, double salaire_, CDate dateNaissance_, CDate dateEmbauche_, Statut s)
  :matricule(matricule_)

{
    status = s;
    nom = nom_;
    prenom = prenom_;
    addresse = adres;
    fonction = fonction_;
    salaireBase = salaire_;
    dateNaissance = dateNaissance_;
    dateEmbauche = dateEmbauche_;
}

Cemploye::Cemploye(string matricule_, string nom_, string prenom_, string adrss, double salaire_, string fontion_, CDate dateNaissance_, Statut s)
    :matricule(matricule_)
{
    nom = nom_;
    prenom = prenom_;
    addresse = adrss;
    salaireBase  = salaire_;
    status = s;
    fonction  = fontion_;
    dateNaissance = dateNaissance_;
    dateEmbauche = CDate();
}

Cemploye::Cemploye(const Cemploye &employe)
{
    nom = employe.getNom();
    prenom = employe.getPrenom();
    addresse = employe.getAdresse();
    fonction = employe.getFonction();
    dateNaissance = employe.getDateNaissance();
    dateEmbauche = employe.getDateEmbauche();
    status = employe.status;
}

bool Cemploye::estAuxiliaire()const
{
    return status == Cemploye::auxiliaire;

}

void Cemploye::augmenter(float pourcentage)
{
    salaireBase  =  (salaireBase * pourcentage/100)+ salaireBase;
}


CDate Cemploye::dateRetraite(){
    int age_retraite;
    cout<<"Annee maximal de service: "  <<endl;
    cin>>age_retraite;
    return dateEmbauche.ajouterPeriode(age_retraite, CDate::ANNEE);
}

bool Cemploye::estAnneeRetraite(int annee)
{
    return CDate().ajouterPeriode(annee, CDate::ANNEE) <= dateRetraite();
}

void Cemploye::afficher()const{
    cout<<"Matricule: "<<matricule<<"\nNom: "<<nom<<"\nPrenom: "<<prenom<<"\n DateEmbauche :"<<dateEmbauche<<"\n Fonction: "<<fonction;
       if (status == auxiliaire)
           cout<<"\nStatus : "<<"Auxiliaire\n";
       else
           cout<<"\nStatus : "<<"Fonctionnaire\n";

}

int Cemploye::enciennete(){
    int i=0;
    while (true){

        if (dateEmbauche.ajouterPeriode(i, CDate::ANNEE)>=CDate())
            break;
        i++;
    }

    return i;
}

int Cemploye::nbJoursDeConge(bool cadre)
{
    int nb=0;
    if (dateEmbauche.ajouterPeriode(1, CDate::ANNEE)>=CDate()){
        //determiner le nb mois fais dans la societe*
        int i=0;
        while(dateEmbauche.ajouterPeriode(i, CDate::MOIS)<=CDate()){
            nb+=2;
            i++;
        }

    }else{
        nb+=28;
    }

    if (cadre && enciennete()>3 && ((dateNaissance.ajouterPeriode(35, CDate::ANNEE))<=CDate())){
        nb+=2;
     }
    if (cadre && enciennete()>5 && dateNaissance.ajouterPeriode(45, CDate::ANNEE)<= CDate())
    {
        nb=+4;
    }
    return nb;
}


 double Cemploye::calculerSalaire(int nbHeureSupp) const
{   double somme=0.0;
    //extraie les differentes cotisation
     if (status == fonctionnaire)
     {
       somme = salaireBase - (salaireBase*SALAIRE_BASE_FONCTIONNAIRE_RETRAIT);

       if (salaireBase <PLAFOND_FIXE){
            somme-= (salaireBase) - (salaireBase * SALAIRE_BASE_FONCTIONNAIRE_PROTECTION_SOCIAL);
        }
        else{

            somme-= (PLAFOND_FIXE) - (PLAFOND_FIXE*(SALAIRE_BASE_FONCTIONNAIRE_PROTECTION_SOCIAL));
        }
 }else {
         if(salaireBase<=PLAFOND_FIXE){
         somme=(salaireBase - salaireBase*PROTECTION_AUXILIAIRE_INF/100);
     }else{
         somme = (PLAFOND_FIXE - PLAFOND_FIXE*PLAFOND_AUGMENTE + (salaireBase - PLAFOND_FIXE))*1.5/100;
     }

    //
     if (nbHeureSupp>100){
         somme+= (salaireBase +(salaireBase * TAUX_HORAIRE));
     }else{
         somme+= (salaireBase  + (salaireBase * TAUX_HORAIRE_MAJORE));
     }

 }
      return somme;
 }



#ifndef CEMPLOYE_H
#define CEMPLOYE_H

#include "cdate.h"

class Cemploye

{

     const string matricule;
     string prenom, nom, fonction, addresse;
     static const double SALAIRE_BASE;

    // Statut status;
     CDate dateNaissance, dateEmbauche;
     double salaireBase;
     static const double SALAIRE_BASE_FONCTIONNAIRE_RETRAIT,SALAIRE_BASE_FONCTIONNAIRE_PROTECTION_SOCIAL ;
     static const double PLAFOND_FIXE;
     static const int MAXHEURE;
     //static const double SALAIRE_SUP_BASE;
     static const double PROTECTION_AUXILIAIRE_INF;
     static const double PROTECTION_AUXILIAIRE_SUP/*,DIFF*/, TAUX_HORAIRE, TAUX_HORAIRE_MAJORE, PLAFOND_AUGMENTE;


 public:

    //
      enum Statut{fonctionnaire, auxiliaire};
     Cemploye();
     Cemploye(string matricule_,string nom_, string prenom_, string adres,string fonction_, double salaire_/*, Statut status_*/, CDate dateNaissance_,CDate dateEmbauche_, Statut s);
     Cemploye(string matricule_,string nom_, string prenom_, string adrss, double salaire_, string fontion_/*, Statut status_*/, CDate dateNaissance_, Statut s);
     Cemploye(const Cemploye &employe);

    int enciennete();
     bool estAuxiliaire()const;
     string getPrenom()const{return prenom;}
     string getNom()const{return nom;}
     double getSalaireBase()const{return salaireBase;}
     string getAdresse()const{return addresse;}
     string getFonction()const{return fonction;}
     CDate getDateEmbauche()const{return dateEmbauche;}
     CDate getDateNaissance()const{return dateNaissance;}
     CDate dateRetraite();
     virtual double calculerSalaire(int nbHeureSupp=0)const;
     void augmenter(float pourcentage=.05);

     bool estAnneeRetraite(int annee);

     void afficher()const;

     int nbJoursDeConge (bool cadre = false);
private:
     Statut status;
};

#endif // CEMPLOYE_H

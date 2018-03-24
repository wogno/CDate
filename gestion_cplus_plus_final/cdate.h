#ifndef CDATE_H
#define CDATE_H


#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <time.h>
using namespace std;

class CDate
{
    int jour, mois, annee;


public:
    enum TYPE_PERIODE{JOUR, MOIS, SEMAINE,ANNEE};
   enum FORMAT{MINIMAL, ABREGE, COMPLET};

    CDate(int jour_=0, int mois_=0, int annee_=0);
    CDate( CDate const &date);

    int lireJour()const{return jour;}
    int lireMois()const{return mois;}
    int lireAnnee()const{return annee;}
    static bool bissextile(int date_);
    static bool mois31Day(int mois_);
    string trouverNomMois(string &m, FORMAT f);
    CDate ajouterPeriode(int jour_, TYPE_PERIODE type);
    string formater(string &s , FORMAT f);
   string trouverNomJour(string &j, FORMAT f);

    // operateur de comparaison
    friend istream &operator >>(istream cinstream, CDate &date);
    friend bool operator ==(CDate const &date1, CDate const &date2);
    friend bool operator <(CDate const &date1, CDate const &date2);


    //operation arithmetique
    CDate operator += (int n){
        while(n !=0){
            (*this)++;

            n--;
        }
        return *this;
    }

    CDate operator -= (int jour_){
        while(jour_){
            (*this)--;
            jour_--;
        }
        return *this;
     }
     CDate operator ++(){
         (*this)++;
         return *this;


     }

    CDate operator ++(int){
        CDate date(jour, mois, annee);
       if(mois==12 && jour==31){
           annee++;
           mois=1;
           jour=1;

 }else if(CDate::mois31Day(mois) && jour==31){
    mois++;
    jour=1;
}
 else if (!CDate::mois31Day(mois) && jour == 30){
     mois++;
     jour=1;
}
else{
    jour++;
 }
       return date;
}


CDate operator --(){
(*this)--;
 return *this;

}
CDate operator --(int){
   CDate date(jour, mois, annee);
   if(jour==1){
       if(mois == 1){
           jour=31;
           mois=12;
           annee--;

       }else if(mois==3){
           mois=2;
           if(CDate::bissextile(annee)){
               jour=29;

           }else{
               jour=28;
           }
       }else if(CDate::mois31Day(mois) && mois != 8){
           jour=30;
           mois--;
       }else
       {
           jour=31;
           mois--;
       }

   }else{
       jour--;
   }

  return date;
}


//CDate &operator =(CDate const &date){

// jour = date.lireJour();
// mois = date.lireMois();
// annee = lireAnnee();
// return *this;
//}

};


ostream &operator <<(ostream &stream, CDate const &date);
bool operator !=(CDate const &date1, CDate const &date2);
bool operator <=(CDate const &date1, CDate const &date2);
bool operator >=(CDate const &date1, CDate const &date2);
bool operator >(CDate const &date1, CDate const &date2);

//operation arithmetique

CDate operator - (CDate const &date1, int jour_);
int operator - (CDate const &date1, CDate  const &date2);
CDate operator + (CDate const &date1, int jour_);

#endif // CDATE_H

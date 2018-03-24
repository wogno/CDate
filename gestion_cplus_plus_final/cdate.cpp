

#include "cdate.h"

CDate::CDate(int jour_, int mois_, int annee_)
{
    time_t temps;
    struct tm *today;
    time(&temps);
    today = localtime(&temps);

    if (jour_ == 0 && mois_ == 0 && annee_ == 0){
        jour = today->tm_mday;
        mois = 1 + today->tm_mon;
        annee = 1900 + today->tm_year;
    }else{

        if(jour_ == 0){
            jour = today->tm_mday;

        }else{
            jour = jour_;
        }

        if (mois_ == 0 || mois_>12){
            mois = 1+ today->tm_mon;

        }else{
            mois = mois_;

        }

        if(annee_ <=0){
            annee = 1900 + today->tm_year;
        }else{
            annee = annee_;
        }
//
        if(mois31Day(mois) &&  jour>31){
            jour = 31;
            cout<<"Aucune action"<<endl;
        }
        else if (!mois31Day(mois) && mois != 2 && jour>30){
            jour = 30;
        }
        else if (mois == 2 && bissextile(annee) && jour>29){
            jour = 29;
        }
        else if (mois == 2 && !bissextile(annee) && jour>28){
            jour = 28;
        }

    }
}

CDate::CDate(CDate const &date)
{
    this->jour = date.jour;
    this->mois = date.mois;
    this->annee = date.annee;
}
bool CDate::mois31Day(int mois_)
{
    int tab []= {1, 3, 5, 7, 8, 10 ,12};
    for(int i=0; i<7; i++){
        if(mois_ == tab[i])
            return true;
    }
    return false;
}

bool CDate::bissextile(int date_)
{
    return (date_%4==0 && date_%100!=0) || date_%400==0;//a verifier
}




bool operator ==(CDate const &date1, CDate const &date2)
{
    if(date1.jour == date2.jour && date1.mois == date2.mois && date1.annee == date2.annee)
    {
        return true;
    }
    return false;
}

bool operator !=(CDate const &date1, CDate const &date2)
{
    return !(date1 == date2);
}

bool operator <(CDate const &date1, CDate const &date2){
    if(date1.annee<date2.annee)
    {
        return true;
    }
    else if(date1.annee == date2.annee && date1.mois<date2.mois)
    {
        return true;
    }
    else if(date1.annee == date2.annee && date1.mois == date2.mois && date1.jour<date2.jour)
    {
        return true;
    }
    else {
        return false;
    }
}

bool operator <=(CDate const &date1, CDate const &date2)
{
    return (date1<date2) || (date1 == date2);
}

bool operator > (CDate const &date1, CDate const &date2)
{
    return !(date1 <= date2);
}

bool operator >=(CDate const &date1, CDate const &date2)
{
    return !(date1<date2) || (date1 == date2);
}


ostream & operator <<(ostream &stream, CDate const &date)
{
    stream<<date.lireJour()<<"/"<<date.lireMois()<<"/"<<date.lireAnnee()<<endl;
    return stream;
}

CDate &operator >>(istream &cinstream, CDate &date)
{    int j, m, a;
     cin>>j>>m>>a;
     date = CDate(j, m, a);
     return date;
}




CDate CDate::ajouterPeriode(int jour_, TYPE_PERIODE type)
{
    CDate date(jour, mois, annee);
    if (type == JOUR)
    {   cout<<"jour"<<endl;
        if(jour_>0){
            (date)+=jour_;
        }else{
            date-=(abs(jour_));
        }

    }else if(type==SEMAINE){
        if(jour_>0){
            (date)+=(jour_*7);
         }else{
            (date)-=abs((jour_*7));
        }

    }else if(type == MOIS){
        bool positif  = jour_>=0;
        int add=0;int annee_=annee;int mois_=mois;
        if(mois_==12 )
        {
            mois_ = 1;
            annee_++;

        }else{
            mois_++;
        }
        while(jour_ != 0){
            if(mois31Day(mois_)){
                add+=31;
            }else if(mois == 2 && CDate::bissextile(annee_)){
                add+=29;
            }else if(mois == 2 && !CDate::bissextile(annee_)){
                add+=28;
            }else{
                add+=30;
            }
            if(positif>0){
                jour_--;
            }else{
                jour_++;
            }

            mois_++;

            if(mois_ == 12){
                mois_=1;
                annee_++;
            }
                }

            if(positif){
                date+=add;
            }else{
                date-=add;
            }
            return date;

        }else if(type == ANNEE){
        bool positif = jour_>=0;
        int add = 0;int annee_ =0;
        if (positif){
            annee_ = annee+1;
        }else{
            annee_ = annee-1;
        }

        while(jour_ != 0){
            if(CDate::bissextile(annee_)){
                add+=366;
            }else{
                add+=365;
            }

            if (jour_==0){
                break;
            }
            else if(positif){

                jour_--;
                annee_++;
            }else{
                jour_++;
                annee_--;
            }
        }
        if( positif){

            (date)+=add;
        }else{
            date-=add;
        }
    }
    return date;
}



string CDate::trouverNomMois(string &m, FORMAT f){
    if (f == MINIMAL){
       stringstream ss;

       ss<<mois;
       m  = ss.str();
       return m;
    }else{
    switch (mois) {
    case 1:
       if (f == ABREGE){
            m = "Janv";

        }
        else {
            m = "Janvier";
        }
        break;
    case 2:
        if (f == ABREGE){
            m =  "Feb";

        }
        else {
            m  = "Fevrier";
        }
        break;
    case 3:
        if (f == ABREGE){
            m =  "Mrs";

        }
        else {
            m = "Mars";
        }
        break;
    case 4:

        if (f == ABREGE){
            m = "Avr";

        }
        else {
            m = "Avril";
        }
        break;

    case 5:

         if (f == ABREGE){
            m= "Mai";

        }
        else {
            m= "Mai";
        }
        break;

    case 6:

         if (f == ABREGE){
            m= "Jun";

        }
        else {
            m= "Juin";
        }
        break;
    case 7:

         if (f == ABREGE){
            m= "Jull";

        }
        else {
            m= "Juillet";
        }
        break;

    case 8:

         if (f == ABREGE){
            m= "Aou";

        }
        else {
            m= "Aout";
        }
        break;

    case 9:

         if (f == ABREGE){
            m = "Sept";

        }
        else {
            m= "Septembre";
        }
        break;
    case 10:

         if (f == ABREGE){
            m = "Oct";

        }
        else {
            m = "Octbre";
        }
        break;

    case 11:

         if (f == ABREGE){
            m = "Nov";

        }
        else {
            m = "Novembre";
        }
        break;

    case 12:

          if (f == ABREGE){
            m= "Dec";

        }
        else {
            m = "Decembre";
        }
        break;

    default:
        m = "Erreur";
    }
    return m;
}
}


string CDate::trouverNomJour(string &j, FORMAT f){
    if (f == MINIMAL){
        stringstream ss;
        ss<<jour;
        j = ss.str();
        return j;
    }else{
       int jr;// selon l algorithme de mike Keith
       if (mois>=3){

           jr = (((23*mois)/9)+jour+4+annee+(annee/4)-(annee/100)+(annee/400)-2)%7;
       }else if (mois<3){
           jr = (((23*mois)/9)+jour+4+annee+((annee-1)/4)-((annee-1)/100)+((annee-1)/400))%7;
       }
       cout<<jr<<endl;
       switch (jr) {
       case 0:
           if (f == ABREGE){
               j = "Dim";
           }else{
               j = "Dimanche";
           }
           break;
       case 1:
           if(f == ABREGE){
               j = "Lun";
           }else{
               j = "Lundi";
           }
           break;
       case 2:
           if (f == ABREGE){
               j = "Mar";
           }else{
               j = "Mardi";
           }
           break;

       case 3:
           if (f == ABREGE){
               j = "Merc";
           }else{
               j = "Mercredi";
           }
           break;
       case 4:
              if (f == ABREGE){
                  j = "Jeu";
              }else{
                  j = "Jeudi";
              }
           break;
       case 5:
           if (f == ABREGE){
               j = "Vend";
           }else{
               j = "Vendredi";
           }
           break;
       case 6:
           if (f == ABREGE){
               j = "Sam";
           }else{
               j = "Samedi";
           }
           break;
       default:
           break;
       }

    }
    return j;
}

string CDate::formater(string &s, FORMAT f)
{
    string j,m;
    stringstream ss;
    ss<<annee;
    if (f == MINIMAL){
    s = this->trouverNomJour(j, f)+"/"+this->trouverNomMois(m,f)+"/"+ss.str();
    }else{
        s = this->trouverNomJour(j, f)+" "+this->trouverNomMois(m,f)+" " +ss.str();
    }
    return s;
}

CDate operator - (CDate const &date1, int jour_){
    CDate date = date1;
    while(jour_ != 0){
        date--;
        jour_--;
    }
    return date;
}

int operator - (CDate const &date1, CDate  const &date2)
{
    CDate date_ =date2;
    int i=0;
    while(date1 != date_){
        date_--;
        i++;
    }
    return i;
}


CDate operator + (CDate  const &date1, int  jour_){
    CDate date = date1;
    while(jour_ != 0){
        date++;
        jour_--;
    }
    return date;
}



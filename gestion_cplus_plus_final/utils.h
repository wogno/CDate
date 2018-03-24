#ifndef UTILS_H
#define UTILS_H
# include "cemploye.h"


/*
 *
 *
 * Donner en parametre le tableau et xa taille
 *
 * */



void insererEmploye(Cemploye *tab, int &i);
void rechercherEmplpoye(Cemploye *tab, int i);
void supprimerEmploye(Cemploye *tab, int &i);
void listeRetraite(Cemploye *tab, int i);
void masseSalariale(Cemploye *tab, int i);
void calculeSalaireEmp(Cemploye *tab, int i);
void fonctionnaire(Cemploye *tab, int i);
void conges(Cemploye *tab, int i);
#endif // UTILS_H

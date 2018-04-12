#ifndef BIEN_H
#define BIEN_H
#include <string>
#include "clientvendeur.h"
using namespace std;

class Bien
{

protected:
    unsigned int  identifiant; // tester identifiant non nul
    Adresse adresse; // créer adresse en classe ?
    double prix;
    double mCarre;
    ClientVendeur* refClientVendeur;
    virtual void afficher()=0;


public:
    Bien();
    Bien(unsigned int identifiant, Adresse adresse , double prix, double mCarre,ClientVendeur * refClientVendeur);

    unsigned int getIdentifiant() const;
    void setIdentifiant(unsigned int value);

    Adresse getAdresse() const;
    void setAdresse(const string &value);

    double getPrix() const;
    void setPrix(double value);

    double getCarre() const;
    void setCarre(double carre);


    ClientVendeur *getRefClientVendeur() const;


    unsigned int genererIdentifiant();
    void afficherTout();
    void affichageSimple();



};

#endif // BIEN_H

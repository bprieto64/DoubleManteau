#include "bien.h"
#include <iostream>
using namespace std;


//CONSTRUCTORS

Bien::Bien()
{

}

Bien::Bien(unsigned int identifiant, string adresse , double prix, double mCarre,ClientVendeur * refClientVendeur)
{
    this->identifiant=identifiant;
    this->adresse=adresse;
    this->prix=prix;
    this->mCarre=mCarre;
    this->refClientVendeur=refClientVendeur;

}
//GETTERS AND SETTERS
ClientVendeur *Bien::getRefClientVendeur() const
{
return refClientVendeur;
}
unsigned int Bien::getIdentifiant() const
{
    return identifiant;
}

void Bien::setIdentifiant(unsigned int value)
{
    identifiant = value;
}

string Bien::getAdresse() const
{
    return adresse;
}

void Bien::setAdresse(const string &value)
{
    adresse = value;
}

double Bien::getPrix() const
{
    return prix;
}

void Bien::setPrix(double value)
{
    prix = value;
}

double Bien::getCarre() const
{
    return mCarre;
}

void Bien::setCarre(double carre)
{
    mCarre = carre;
}




//OTHERS METHODS
 void Bien::afficherTout()
{
   cout<<"L'adresse du bien numéro : "<<identifiant<< " est "<<adresse<<"."<<endl;
   cout<<"le prix de bien est : "<< prix << " €."<<endl;
   cout<<"Sa superficie est de "<<mCarre<<" m²."<<endl;
   cout<<"Le numéro du vendeur est "<<refClientVendeur->getIdentifiant()<<"." <<endl;
   afficher();
}



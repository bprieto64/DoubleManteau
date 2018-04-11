#include "adresse.h"

string adresse::getVille() const
{
    return ville;
}

void adresse::setVille(const string &value)
{
    ville = value;
}

int adresse::getCodePostal() const
{
    return codePostal;
}

void adresse::setCodePostal(int value)
{
    codePostal = value;
}

string adresse::getNomRue() const
{
    return nomRue;
}

void adresse::setNomRue(const string &value)
{
    nomRue = value;
}

int adresse::getNumRue() const
{
    return numRue;
}

void adresse::setNumRue(int value)
{
    numRue = value;
}

adresse::adresse()
{
    this->numRue=0;
    this->nomRue="";
    this->ville="";
    this->codePostal=0;
}

adresse::adresse(int num, rue, ville, cp){
    this->numRue=num;
    this->nomRue=rue;
    this->ville=ville;
    this->codePostal=cp;
}

void adresse::afficher() const{
    cout << num << " " << rue << " " << ville << " " << cp;
}

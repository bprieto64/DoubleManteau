#include "adresse.h"

//CONSTRUCTEURS

Adresse::Adresse()
{

}

Adresse::Adresse(unsigned int numRue, string nomRue, unsigned int codePostal, string ville)
{
    this->numRue=numRue;
    this->nomRue=nomRue;
    this->codePostal=codePostal;
    this->ville=ville;
}

//GETTERS ET SETTERS

unsigned int Adresse::getNumRue() const
{
    return numRue;
}

void Adresse::setNumRue(unsigned int value)
{
    numRue = value;
}

unsigned int Adresse::getCodePostal() const
{
    return codePostal;
}

void Adresse::setCodePostal(unsigned int value)
{
    codePostal = value;
}

string Adresse::getNomRue() const
{
    return nomRue;
}

void Adresse::setNomRue(const string &value)
{
    nomRue = value;
}

string Adresse::getVille() const
{
    return ville;
}

void Adresse::setVille(const string &value)
{
    ville = value;
}

//Autres méthodes

void Adresse::afficher(){
    cout << this->numRue << " " << this->nomRue << " " << this->ville << " " << this->codePostal << endl;
}

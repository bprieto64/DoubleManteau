#include "appartement.h"
#include <iostream>


//CONSTRUCTORS
Appartement::Appartement()
{

}

Appartement::Appartement(unsigned int nbrPieces, unsigned int etage, bool hasGarage,
                         bool hasCave, bool hasBalcon, unsigned int identifiant, Adresse adresse,
                         double prix, double mCarre, ClientVendeur *refClientVendeur)
    :Bien(identifiant,adresse,prix,mCarre,refClientVendeur)
{
    this->nbrPieces=nbrPieces;
    this->etage=etage;
    this->hasGarage=hasGarage;
    this->hasCave=hasCave;
    this->hasBalcon=hasBalcon;
}

//GETTERS AND SETTERS


bool Appartement::getHasBalcon() const
{
    return hasBalcon;
}

void Appartement::setHasBalcon(bool value)
{
    hasBalcon = value;
}

bool Appartement::getHasCave() const
{
    return hasCave;
}

void Appartement::setHasCave(bool value)
{
    hasCave = value;
}

bool Appartement::getHasGarage() const
{
    return hasGarage;
}

unsigned int Appartement::getNbrPieces() const
{
    return nbrPieces;
}

void Appartement::setNbrPieces(unsigned int value)
{
    nbrPieces = value;
}

unsigned int Appartement::getEtage() const
{
    return etage;
}

void Appartement::setEtage(unsigned int value)
{
    etage = value;
}

//OTHERS METHODS

void Appartement::afficher()
{
    cout<<"L'appartement possede "<<nbrPieces<< " pieces."<<endl;
    cout<<"Il est situe a l'etage numero "<<etage<<endl;
    if(hasGarage){
        cout<<"L'Appartement possede un garage."<<endl;
    }
    if(hasCave){
        cout<<"L'Appartement possede une cave."<<endl;
    }
    if(hasBalcon){
        cout<<"L'Appartement possede un balcon."<<endl;
    }
}

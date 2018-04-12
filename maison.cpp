#include "maison.h"



//CONSTRUCTOR(S)

Maison::Maison()
{

}

Maison::Maison(unsigned int nbrPieces, bool hasGarage, bool hasJardin, bool hasPiscine,
               unsigned int identifiant, Adresse adresse, double prix,
               double mCarre, ClientVendeur *refClientVendeur)
 :Bien(identifiant,adresse,prix,mCarre, refClientVendeur)
{
    this->nbrPieces=nbrPieces;
    this->hasGarage=hasGarage;
    this->hasJardin=hasJardin;
    this->hasPiscine=hasPiscine;
}

//GETTERS AND SETTERS
bool Maison::getHasGarage() const
{
    return hasGarage;
}

void Maison::setHasGarage(bool value)
{
    hasGarage = value;
}

bool Maison::getHasJardin() const
{
    return hasJardin;
}

void Maison::setHasJardin(bool value)
{
    hasJardin = value;
}

bool Maison::getHasPiscine() const
{
    return hasPiscine;
}

void Maison::setHasPiscine(bool value)
{
    hasPiscine = value;
}

unsigned int Maison::getNbrPieces() const
{
    return nbrPieces;
}

void Maison::setNbrPieces(unsigned int value)
{
    nbrPieces = value;
}

void Maison::afficher()
{
    cout<<"La maison possède "<<nbrPieces<< " pièces."<<endl;
    if(hasGarage){
        cout<<"La maison possède un garage."<<endl;
    }
    if(hasPiscine){
        cout<<"L'Appartement possède une piscine."<<endl;
    }
    if(hasJardin){
        cout<<"L'Appartement possède un jardin."<<endl;
    }

}

//OTHERS METHODS


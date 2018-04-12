#include "locauxpro.h"

//CONSTRUCTOR(S)

LocauxPro::LocauxPro()
{

}
LocauxPro::LocauxPro(double tailleVitrine, bool hasStockageMateriaux, unsigned int identifiant,
                     Adresse adresse, double prix, double mCarre,
                     ClientVendeur* refClientVendeur)
    :Bien(identifiant,adresse,prix,mCarre,refClientVendeur)
{
    this->tailleVitrine=tailleVitrine;
    this->hasStockageMateriaux=hasStockageMateriaux;
}

//GETTERS AND SETTERS
double LocauxPro::getTailleVitrine() const
{
    return tailleVitrine;
}

void LocauxPro::setTailleVitrine(double value)
{
    tailleVitrine = value;
}

bool LocauxPro::getHasStockageMateriaux() const
{
    return hasStockageMateriaux;
}

void LocauxPro::setHasStockageMateriaux(bool value)
{
    hasStockageMateriaux = value;
}


void LocauxPro::afficher()
{
    cout<<"La taille de la vitrine est de "<<tailleVitrine<<" metres"<<endl;
    if(hasStockageMateriaux){
        cout<<"Le local professionnel possede une piece afin de stocker les materiaux."<<endl;
    }
}

//OTHERS METHODS


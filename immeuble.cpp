#include "immeuble.h"

//CONSTRUCTOR(S)

Immeuble::Immeuble()
{

}

//GETTERS AND SETTERS
std::vector<Appartement> Immeuble::getAppartements() const
{
    return appartements;
}

void Immeuble::setAppartements(const std::vector<Appartement> &value)
{
    appartements = value;
}

void Immeuble::ajouterNouveauAppartement(Appartement appartement)
{
appartements.push_back(appartement);


}

//OTHERS METHODS

void Immeuble::supprimerAppartement(unsigned int identifiant)
{
for(vector<Appartement>::iterator i = appartements.begin();i !=appartements.end() ; i++){
        if(i->getIdentifiant()==identifiant){

            appartements.erase(i);
        }
    }
}

unsigned int Immeuble::getNbrAppart() const
{
    return appartements.size();
}






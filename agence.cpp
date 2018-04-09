#include "agence.h"
#include <map>
using namespace std;
std::map<ClientAcheteur *, Visite *> Agence::getCarnetVisites() const
{
    return carnetVisites;
}

Agence::Agence()
{

}


void Agence::ajouterNouvelleVisite(ClientAcheteur *clientAcheteur, Visite *visite)
{
    carnetVisites.insert(pair<ClientAcheteur*,Visite*>(clientAcheteur,visite));
}

void Agence::supprimerVisite(ClientAcheteur *clientAcheteur, double propAchat,unsigned int identifiant) // A TESTER:  PAS SUR DU TOUT
{

    for(map<ClientAcheteur*,Visite*>::iterator it =carnetVisites.begin(); it!=carnetVisites.end() ; it++){

        if(((it->second->getBien()->getIdentifiant())==identifiant) && (it->second->getPropAchat())==propAchat && (clientAcheteur==(it->first))  ){
            carnetVisites.erase(it);
            break;
        }
    }
}



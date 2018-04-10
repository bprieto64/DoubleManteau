#include "agence.h"
#include <iostream>
using namespace std;

std::map<ClientAcheteur *, Visite *> Agence::getCarnetVisites() const
{
    return carnetVisites;
}

std::vector<Client> Agence::getCarnetClients() const
{
    return carnetClients;
}

void Agence::setCarnetClients(const std::vector<Client> &value)
{
    carnetClients = value;
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

void Agence::ajouterNouveauClient(Client client)
{
    carnetClients.push_back(client);
}

void Agence::supprimerClient(unsigned int identifiant)
{
    for(vector<Client>::iterator i = carnetClients.begin();i !=carnetClients.end() ; i++){
        if(i->getIdentifiant()==identifiant){

            carnetClients.erase(i);
        }
    }
}

Client  Agence::isClientExiste(unsigned int identifiant)
{


    for(auto  i = carnetClients.begin();i !=carnetClients.end() ; i++){
        if(i->getIdentifiant()==identifiant){
            cout <<i->getIdentifiant()<<endl;
            return *i;
        }
    }

}






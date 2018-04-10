#include "agence.h"
#include <iostream>
using namespace std;







std::vector<Bien> Agence::getBiens() const
{
    return biens;
}



Agence::Agence()
{

}

std::vector<ClientVendeur> Agence::getCarnetClientsVendeurs() const
{
    return carnetClientsVendeurs;
}
std::vector<ClientAcheteur> Agence::getCarnetClientsAcheteurs() const
{
    return carnetClientsAcheteurs;
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


void Agence::ajouterNouveauClientVendeur(ClientVendeur client)
{
    carnetClientsVendeurs.push_back(client);
}

void Agence::supprimerClientVendeur(unsigned int identifiant)
{
    for(vector<ClientVendeur>::iterator i = carnetClientsVendeurs.begin();i !=carnetClientsVendeurs.end() ; i++){
        if(i->getIdentifiant()==identifiant){

            carnetClientsVendeurs.erase(i);
        }
    }
}

bool Agence::isClientExisteV(unsigned int identifiant)
{

    for(unsigned i=0; i<carnetClientsVendeurs.size();i++){
        if(carnetClientsVendeurs[i].getIdentifiant()==identifiant){

            return true;
        }
    }
    return false;

}

ClientVendeur Agence::recupererClientVendeur(unsigned int identifiant)
{
    for(vector<ClientVendeur>::iterator i = carnetClientsVendeurs.begin();i !=carnetClientsVendeurs.end() ; i++){
        if(i->getIdentifiant()==identifiant){

            return *i;
        }
    }

}

void Agence::ajouterNouveauClientAcheteur(ClientAcheteur client)
{
    carnetClientsAcheteurs.push_back(client);
}

void Agence::supprimerClientAcheteur(unsigned int identifiant)
{
    for(vector<ClientAcheteur>::iterator i = carnetClientsAcheteurs.begin();i !=carnetClientsAcheteurs.end() ; i++){
        if(i->getIdentifiant()==identifiant){

            carnetClientsAcheteurs.erase(i);
        }
    }

}

bool Agence::isClientExisteA(unsigned int identifiant)
{

    for(unsigned i=0; i<carnetClientsAcheteurs.size();i++){
        if(carnetClientsAcheteurs[i].getIdentifiant()==identifiant){

            return true;
        }
    }
    return false;

}

ClientAcheteur Agence::recupererClientAcheteur(unsigned int identifiant)
{
    for(vector<ClientAcheteur>::iterator i = carnetClientsAcheteurs.begin();i !=carnetClientsAcheteurs.end() ; i++){
        if(i->getIdentifiant()==identifiant){

            return *i;
        }
    }

}

void Agence::ajouterNouveauBien(Bien bien)
{
    biens.push_back(bien);
}




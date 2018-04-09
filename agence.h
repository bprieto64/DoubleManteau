#ifndef AGENCE_H
#define AGENCE_H
#include "clientacheteur.h"
#include "visite.h"
#include <map>

class Agence
{
private :
    std::map<ClientAcheteur*,Visite*> carnetVisites;
public:
    Agence();

    void ajouterNouvelleVisite(ClientAcheteur *clientAcheteur,Visite *visite);
    void supprimerVisite(ClientAcheteur *clientAcheteur,double propAchat, unsigned int identifiant);

    std::map<ClientAcheteur *, Visite *> getCarnetVisites() const;

};

#endif // AGENCE_H

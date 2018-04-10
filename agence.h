#ifndef AGENCE_H
#define AGENCE_H

#include "clientacheteur.h"
#include "visite.h"
#include "client.h"
#include <map>
#include <vector>


class Agence
{
private :
    std::map<ClientAcheteur*,Visite*> carnetVisites;
    std::vector<Client> carnetClients;

public:
    Agence();

    void ajouterNouvelleVisite(ClientAcheteur *clientAcheteur,Visite *visite);
    void supprimerVisite(ClientAcheteur *clientAcheteur,double propAchat, unsigned int identifiant);
    void ajouterNouveauClient(Client client);
    void supprimerClient(unsigned int identifiant);
    Client isClientExiste(unsigned int identifiant);

    std::map<ClientAcheteur *, Visite *> getCarnetVisites() const;

    std::vector<Client> getCarnetClients() const;
    void setCarnetClients(const std::vector<Client> &value);
};

#endif // AGENCE_H

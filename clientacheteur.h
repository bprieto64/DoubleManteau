#ifndef CLIENTACHETEUR_H
#define CLIENTACHETEUR_H
#include "client.h"


class ClientAcheteur : public Client
{
public:
    ClientAcheteur();
    ClientAcheteur(unsigned int identifiant, string nom, string adresse);
    void afficher();

};

#endif // CLIENTACHETEUR_H

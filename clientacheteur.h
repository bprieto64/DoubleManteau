#ifndef CLIENTACHETEUR_H
#define CLIENTACHETEUR_H
#include "client.h"


class ClientAcheteur : public Client
{
public:
    ClientAcheteur();
    ClientAcheteur(unsigned int identifiant, string nom, string adresse);

};

#endif // CLIENTACHETEUR_H

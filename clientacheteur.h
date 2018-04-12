#ifndef CLIENTACHETEUR_H
#define CLIENTACHETEUR_H
#include "client.h"
#include "adresse.h"


class ClientAcheteur : public Client
{
public:
    ClientAcheteur();
    ClientAcheteur(unsigned int identifiant, string nom, Adresse adresse);
    void afficher();

};

#endif // CLIENTACHETEUR_H

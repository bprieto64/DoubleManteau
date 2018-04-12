#ifndef AGENCE_H
#define AGENCE_H

#include "clientacheteur.h"
#include "visite.h"
#include "client.h"
#include <map>
#include <vector>
#include "bien.h"
#include <iostream>
#include <string>
#include "appartement.h"


class Agence
{
private :
    std::map<ClientAcheteur*,Visite*> carnetVisites;
    std::vector<ClientVendeur> carnetClientsVendeurs;
    std::vector<ClientAcheteur> carnetClientsAcheteurs;
    std::vector<Bien*> biens;

public:
    Agence();

    void ajouterNouvelleVisite(ClientAcheteur *clientAcheteur,Visite *visite);
    void supprimerVisite(ClientAcheteur *clientAcheteur,double propAchat, unsigned int identifiant);

    void ajouterNouveauClientVendeur(ClientVendeur client);
    void supprimerClientVendeur(unsigned int identifiant);
    bool isClientExisteV(unsigned int identifiant);
    ClientVendeur recupererClientVendeur(unsigned int identifiant);

    void ajouterNouveauClientAcheteur(ClientAcheteur client);
    void supprimerClientAcheteur(unsigned int identifiant);
    bool isClientExisteA(unsigned int identifiant);
    ClientAcheteur recupererClientAcheteur(unsigned int identifiant);

   void ajouterNouveauBien(Bien * bien);
   void AjouterBienAVendre(ClientVendeur *cv);

    std::map<ClientAcheteur *, Visite *> getCarnetVisites() const;




    std::vector<ClientVendeur> getCarnetClientsVendeurs() const;

    std::vector<ClientAcheteur> getCarnetClientsAcheteurs() const;

    std::vector<Bien*> getBiens() const;

};

#endif // AGENCE_H

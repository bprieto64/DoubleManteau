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
#include "maison.h"
#include "terrain.h"
#include "locauxpro.h"
#include <chrono>
#include <thread>
#include <fstream>



class Agence
{
private :
    std::map<Visite*,ClientAcheteur*> carnetVisites;
    std::vector<ClientVendeur> carnetClientsVendeurs;
    std::vector<ClientAcheteur> carnetClientsAcheteurs;
    std::vector<Bien*> biens;

public:
    Agence();

    void ajouterNouvelleVisite(ClientAcheteur *clientAcheteur,Visite *visite);
    void supprimerVisite(ClientAcheteur *clientAcheteur,double propAchat, unsigned int identifiant);
    void supprimerVisiteEtBien(ClientAcheteur *clientAcheteur);

    void ajouterNouveauClientVendeur(ClientVendeur client);
    void supprimerClientVendeur(unsigned int identifiant);
    bool isClientExisteV(unsigned int identifiant);
    ClientVendeur recupererClientVendeur(unsigned int identifiant);
    void consulterMesBiensAVendre(ClientVendeur * cv);

    void ajouterNouveauClientAcheteur(ClientAcheteur client);
    void supprimerClientAcheteur(unsigned int identifiant);
    bool isClientExisteA(unsigned int identifiant);
    ClientAcheteur recupererClientAcheteur(unsigned int identifiant);

   void ajouterNouveauBien(Bien * bien);
   void AjouterBienAVendre(ClientVendeur *cv);

   void consulterBien();
   void consulterDetailsBien(int);
   void faireVisite(ClientAcheteur *ca, int identifiant);
   void consulterMesOffresAchats(ClientVendeur *cv);
   void consulteReponseOffreAchat(ClientAcheteur *ca);
   void creerClient();
   void afficherCategorieBiens();
   void afficherCategorieBiensEtPrix(string cat,unsigned int bInf,unsigned int bSup);
   int split(vector<string>& vecteur, string chaine, char separateur);
   void AjouterBienViaFichier(ClientVendeur *cv);





    std::vector<ClientVendeur> getCarnetClientsVendeurs() const;

    std::vector<ClientAcheteur> getCarnetClientsAcheteurs() const;

    std::vector<Bien*> getBiens() const;

    std::map<Visite *, ClientAcheteur *> getCarnetVisites() const;

};

#endif // AGENCE_H

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
    //GETTERS and SETTERS
    std::vector<ClientVendeur> getCarnetClientsVendeurs() const;
    std::vector<ClientAcheteur> getCarnetClientsAcheteurs() const;
    std::vector<Bien*> getBiens() const;
    std::map<Visite *, ClientAcheteur *> getCarnetVisites() const;

    //CONSTRUCTEUR

    Agence();
    //Visites
    void ajouterNouvelleVisite(ClientAcheteur *clientAcheteur,Visite *visite); //Permet d'ajouter une nouvelle visite
    void supprimerVisite(ClientAcheteur *clientAcheteur,double propAchat, unsigned int identifiant); // Permet de supprimer une visite quelconque

    void supprimerVisiteEtBien(ClientAcheteur *clientAcheteur);//Supprime une visite dont la propostion d'achat
                                                                //a été accepté par le vendeur et visualiser par l'acheteur

    void faireVisite(ClientAcheteur *ca, int identifiant);//Fais le déroulement de la visite en demandant la proposition d'achat de l'acheteur

    //Client Vendeurs
    void ajouterNouveauClientVendeur(ClientVendeur client); // Ajouter un nouveau vendeur via la console
    void supprimerClientVendeur(unsigned int identifiant);// Supprimer un vendeur
    bool isClientExisteV(unsigned int identifiant); // renvoie true si le client est présent dans la liste
    ClientVendeur recupererClientVendeur(unsigned int identifiant); // renvoie le client vendeur demandé en fonction de l'identifiant envoyé
    void consulterMesBiensAVendre(ClientVendeur * cv); // consulter les biens à vendre d'un vendeur en particulier
    void ajouterVendeurViaFichier();

    //Client
    void creerClient();

    //Client Acheteur
    void ajouterNouveauClientAcheteur(ClientAcheteur client);
    void supprimerClientAcheteur(unsigned int identifiant);
    bool isClientExisteA(unsigned int identifiant);
    ClientAcheteur recupererClientAcheteur(unsigned int identifiant);
    void ajouterAcheteurViaFichier();

    //Bien
    void ajouterNouveauBien(Bien * bien);
    void AjouterBienViaFichier(ClientVendeur *cv);
    void AjouterBienAVendre(ClientVendeur *cv);
    void consulterBien();
    void consulterDetailsBien(int);
    void afficherCategorieBiens();
    void afficherCategorieBiensEtPrix(string cat,unsigned int bInf,unsigned int bSup);

    //Offres d'achats
    void consulterMesOffresAchats(ClientVendeur *cv);
    void consulteReponseOffreAchat(ClientAcheteur *ca);

    //méthode usuelle
    int split(vector<string>& vecteur, string chaine, char separateur);









};

#endif // AGENCE_H

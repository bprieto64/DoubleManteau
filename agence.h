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
    bool isClientExisteV(unsigned int identifiant); // renvoie true si le vendeur est present dans le vecteur
    ClientVendeur recupererClientVendeur(unsigned int identifiant); // renvoie le client vendeur demandé en fonction de l'identifiant envoyé
    void consulterMesBiensAVendre(ClientVendeur * cv); // consulter les biens à vendre d'un vendeur en particulier
    void ajouterVendeurViaFichier(); // Ajouter des vendeurs via le fichier : vendeurs.txt

    //Client
    void creerClient(); // Créer un  nouveau client

    //Client Acheteur
    void ajouterNouveauClientAcheteur(ClientAcheteur client); // Ajouter nouveau client Acheteur
    void supprimerClientAcheteur(unsigned int identifiant); // supprimer client acheteur à  partir de l'identifiant
    bool isClientExisteA(unsigned int identifiant);//renvoie true si l'acheteur est présent dans le vecteur
    ClientAcheteur recupererClientAcheteur(unsigned int identifiant); // renvoie le client acheteur demandé en fonction de l'identifiant envoyé
    void ajouterAcheteurViaFichier();// Ajouter des vendeurs via le fichier : acheteurs.txt

    //Bien
    void ajouterNouveauBien(Bien * bien); // Ajouter un nouveau bien
    void AjouterBienViaFichier(ClientVendeur *cv);// Ajoute les biens contenus dans le fichier : biens.txt
    void AjouterBienAVendre(ClientVendeur *cv); // Ajouter un nouveau bien à vendre,
                                                //appelle ajouterNouveauBien pour ajouter le Bien dans le vecteur
    void consulterBien(); //Consulter la liste des biens à vendre
    void consulterDetailsBien(int); // Consulter le détail d'un bien en, particulier
    void afficherCategorieBiens(); // Afficher les biens d'une certaine catégorie
    void afficherCategorieBiensEtPrix(string cat,unsigned int bInf,unsigned int bSup); // aficher les biens d'uen certaine catégorie
                                                                                      //avec une foruchette de prix

    //Offres d'achats
    void consulterMesOffresAchats(ClientVendeur *cv); // Consulter les offres d'achats d'un vendeur en particulier
    void consulteReponseOffreAchat(ClientAcheteur *ca); // Consulter les réponses à ses offres d'achats

    //méthode usuelle
    int split(vector<string>& vecteur, string chaine, char separateur); // permet de séparer uen cahien de caracetères dans un vecteur avec un certain séparateur









};

#endif // AGENCE_H

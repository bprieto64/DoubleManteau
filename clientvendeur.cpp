#include "clientvendeur.h"

ClientVendeur::ClientVendeur()
{

}

ClientVendeur::ClientVendeur(unsigned int identifiant, string nom, Adresse adresse):
    Client(identifiant,nom,adresse)
{

}

std::vector<Bien *> ClientVendeur::getMesbiens() const
{
    return mesbiens;
}

void ClientVendeur::afficher()
{

}


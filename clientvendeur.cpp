#include "clientvendeur.h"

ClientVendeur::ClientVendeur()
{

}

ClientVendeur::ClientVendeur(unsigned int identifiant, string adresse, string nom):
    Client(identifiant,nom,adresse)
{

}

std::vector<Bien *> ClientVendeur::getMesbiens() const
{
    return mesbiens;
}


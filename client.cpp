#include "client.h"


//CONSTRUCTORS

Client::Client()
{
    
}

Client::Client(unsigned int identifiant,string nom, string adresse)
{
    this->identifiant=identifiant;
    this->nom=nom;
    this->adresse=adresse;
}

//GETTERS AND SETTERS

unsigned int Client::getIdentifiant() const
{
    return identifiant;
}

void Client::setIdentifiant(unsigned int value)
{
    identifiant = value;
}


string Client::getNom() const
{
    return nom;
}

void Client::setNom(const string &value)
{
    nom = value;
}

string Client::getAdresse() const
{
    return adresse;
}

void Client::setAdresse(const string &value)
{
    adresse = value;
}



//OTHERS METHODS


#include "client.h"


//CONSTRUCTORS
Client::Client()
{

}

Client::Client(string nom, string adresse)
{
    this->nom=nom;
    this->adresse=adresse;
}

//GETTERS AND SETTERS
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


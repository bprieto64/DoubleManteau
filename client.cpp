#include "client.h"


//CONSTRUCTORS

Client::Client()
{
    
}

Client::Client(unsigned int identifiant,string nom, Adresse a)
{
    this->identifiant=identifiant;
    this->nom=nom;
    this->adresse=a;
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

Adresse Client::getAdresse() const
{
    return adresse;
}

/*void Client::setAdresse(const Adresse &value)
{
    adresse = value;
}*/



//OTHERS METHODS

void Client::afficher()
{
    cout<<"L'identifiant du client est "<<identifiant<<endl;
}



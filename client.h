#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>
#include "adresse.h"
using namespace std;

class Client
{
protected:
    unsigned int identifiant;
    string nom;
    Adresse adresse;
public:
    Client();
    Client(unsigned int identifiant, string nom, Adresse adresse);
    string getNom() const;
    void setNom(const string &value);
    Adresse getAdresse() const;
    void setAdresse(Adresse &value);
    unsigned int getIdentifiant() const;
    void setIdentifiant(unsigned int value);
    virtual void afficher()=0;
};

#endif // CLIENT_H

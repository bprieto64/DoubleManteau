#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>
using namespace std;

class Client
{
protected:
    unsigned int identifiant;
    string nom;
    string adresse;
public:
    Client();
    Client(unsigned int identifiant, string nom, string adresse);
    string getNom() const;
    void setNom(const string &value);
    string getAdresse() const;
    void setAdresse(const string &value);
    unsigned int getIdentifiant() const;
    void setIdentifiant(unsigned int value);
    virtual void afficher()=0;
};

#endif // CLIENT_H

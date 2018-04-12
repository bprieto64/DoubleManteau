
#ifndef ADRESSE_H
#define ADRESSE_H
#include <iostream>
#include <string>
using namespace std;


class Adresse
{
private:
    unsigned int numRue;
    string nomRue;
    unsigned int codePostal;
    string ville;

public:
    Adresse();
    Adresse(unsigned int numRue, string nomRue, unsigned int codePostal,string ville);
    unsigned int getNumRue() const;
    void setNumRue(unsigned int value);
    unsigned int getCodePostal() const;
    void setCodePostal(unsigned int value);
    string getNomRue() const;
    void setNomRue(const string &value);
    string getVille() const;
    void setVille(const string &value);

    void afficher();
};

#endif // ADRESSE_H

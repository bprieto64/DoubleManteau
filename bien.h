#ifndef BIEN_H
#define BIEN_H
#include <string>
using namespace std;


class Bien
{

protected:
    unsigned int identifiant; // tester identifiant non nul
    string adresse; // créer adresse en classe ?
    double prix;
    double mCarre;
    unsigned int refClientVendeur;

public:
    Bien();
    Bien(unsigned int identifiant, string adresse , double prix, double mCarre, unsigned int refClientVendeur);

    unsigned int getIdentifiant() const;
    void setIdentifiant(unsigned int value);

    string getAdresse() const;
    void setAdresse(const string &value);

    double getPrix() const;
    void setPrix(double value);

    double getCarre() const;
    void setCarre(double carre);

    unsigned int getRefClientVendeur() const;
    void setRefClientVendeur(unsigned int value);

    void afficher();


};

#endif // BIEN_H

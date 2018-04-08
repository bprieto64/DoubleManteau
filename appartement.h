#ifndef APPARTEMENT_H
#define APPARTEMENT_H
#include "bien.h"


class Appartement : public Bien
{
private :
    unsigned int nbrPieces;
    unsigned int etage;
    bool hasGarage;
    bool hasCave;
    bool hasBalcon;

//ah bg


public:
    Appartement();
    Appartement(unsigned int nbrPieces,unsigned int etage, bool hasGarage,bool hasCave,bool hasBalcon,unsigned int identifiant, string adresse , double prix, double mCarre, unsigned int refClientVendeur);
    bool getHasBalcon() const;
    void setHasBalcon(bool value);
    bool getHasCave() const;
    void setHasCave(bool value);
    bool getHasGarage() const;
    void setHasGarage(bool value);

    unsigned int getNbrPieces() const;
    void setNbrPieces(unsigned int value);
    unsigned int getEtage() const;
    void setEtage(unsigned int value);
    void afficher();
};
#endif // APPARTEMENT_H

#ifndef MAISON_H
#define MAISON_H
#include"bien.h"


class Maison : public Bien
{
    private:
    unsigned int nbrPieces;
    bool hasGarage;
    bool hasJardin;
    bool hasPiscine;
public:
    Maison();
    Maison(unsigned int nbrPieces, bool hasGarage,bool hasJardin,bool hasPiscine,
           unsigned int identifiant, Adresse adresse , double prix,
           double mCarre,ClientVendeur * refClientVendeur);
    bool getHasGarage() const;
    void setHasGarage(bool value);
    bool getHasJardin() const;
    void setHasJardin(bool value);
    bool getHasPiscine() const;
    void setHasPiscine(bool value);
    unsigned int getNbrPieces() const;
    void setNbrPieces(unsigned int value);
    void afficher();
};

#endif // MAISON_H

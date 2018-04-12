#ifndef LOCAUXPRO_H
#define LOCAUXPRO_H
#include "bien.h"


class LocauxPro : public Bien
{
private:
    double tailleVitrine;
    bool hasStockageMateriaux; // Si le local possède une pièce pour le stockage des matériaux
public:
    LocauxPro();
    LocauxPro(double tailleVitrine, bool hasStockageMateriaux, unsigned int identifiant, string adresse , double prix, double mCarre,ClientVendeur *refClientVendeur);
    double getTailleVitrine() const;
    void setTailleVitrine(double value);
    bool getHasStockageMateriaux() const;
    void setHasStockageMateriaux(bool value);
    void afficher();
};

#endif // LOCAUXPRO_H

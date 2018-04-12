#ifndef TERRAIN_H
#define TERRAIN_H

#include "bien.h"


class Terrain : public Bien
{
private:
    bool estConstructible;
public:
    Terrain();
    Terrain(bool,unsigned int identifiant, Adresse adresse , double prix,
            double mCarre,ClientVendeur *refClientVendeur);

    bool getEstConstructible();
    void setEstConstructible(bool);
    void afficher();
};

#endif // TERRAIN_H

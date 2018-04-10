#ifndef TERRAIN_H
#define TERRAIN_H

#include "bien.h"


class Terrain : public Bien
{
private:
    bool estConstructible;
public:
    Terrain();
    Terrain(bool,unsigned int identifiant, string adresse , double prix, double mCarre,ClientVendeur refClientVendeur);

    bool getEstConstructible();
    void setEstConstructible(bool);
};

#endif // TERRAIN_H

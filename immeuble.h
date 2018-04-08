#ifndef IMMEUBLE_H
#define IMMEUBLE_H
#include "appartement.h"
#include <vector>

class Immeuble
{
private :
    unsigned int nbrAppart;
    std::vector<Appartement> appartements;
public:
    Immeuble();

    std::vector<Appartement> getAppartements() const;
    void setAppartements(const std::vector<Appartement> &value);

    unsigned int getNbrAppart() const;
    void setNbrAppart(unsigned int value);

    void ajouterNouveauAppartement(Appartement);
    void supprimerAppartement(unsigned int);


};

#endif // IMMEUBLE_H

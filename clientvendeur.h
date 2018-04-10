#ifndef CLIENTVENDEUR_H
#define CLIENTVENDEUR_H
#include "client.h"
#include <vector>
class Bien;

class ClientVendeur : public Client
{
private :

public:
    ClientVendeur();
    ClientVendeur(unsigned int identifiant, string adresse, string nom);
    std::vector <Bien*> mesbiens;

    std::vector<Bien *> getMesbiens() const;

};

#endif // CLIENTVENDEUR_H

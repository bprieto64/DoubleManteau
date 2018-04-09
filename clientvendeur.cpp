#include "clientvendeur.h"

ClientVendeur::ClientVendeur()
{

}

std::vector<Bien *> ClientVendeur::getMesbiens() const
{
    return mesbiens;
}


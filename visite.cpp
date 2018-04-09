#include "visite.h"

Bien *Visite::getBien() const
{
    return bien;
}

void Visite::setBien(Bien *value)
{
    bien = value;
}

bool Visite::getIsPropAchat() const
{
    return isPropAchat;
}

void Visite::setIsPropAchat(bool value)
{
    isPropAchat = value;
}

double Visite::getPropAchat() const
{
    return propAchat;
}

void Visite::setPropAchat(double value)
{
    propAchat = value;
}

Etat Visite::getEtat() const
{
    return etat;
}

void Visite::setEtat(const Etat &value)
{
    etat = value;
}

Visite::Visite(Bien bien, bool isPropAchat, double propAchat, Etat etat)
{
    this->bien=&bien;
    this->isPropAchat=isPropAchat;
    this->propAchat=propAchat;
    this->etat=etat;
}

Visite::Visite()
{

}

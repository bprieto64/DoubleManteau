#ifndef VISITE_H
#define VISITE_H
#include "bien.h"

enum Etat{ENATTENTE,ACCEPTER,REFUSER};

class Visite
{
private:
    Bien * bien;
    bool isPropAchat;
    double propAchat;
    Etat etat;


public:
    Visite(Bien bien, bool isPropAchat,double propAchat,Etat etat);
    Visite();
    Bien *getBien() const;
    void setBien(Bien *value);
    bool getIsPropAchat() const;
    void setIsPropAchat(bool value);
    double getPropAchat() const;
    void setPropAchat(double value);
    Etat getEtat() const;
    void setEtat(const Etat &value);
};

#endif // VISITE_H

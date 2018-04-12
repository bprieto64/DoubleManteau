#ifndef VISITE_H
#define VISITE_H
#include "bien.h"



class Visite
{
private:
    Bien * bien;
    bool isPropAchat;
    double propAchat;
   string etat;


public:
    Visite(Bien * bien, bool isPropAchat,double propAchat,string etat);
    Visite();
    Bien *getBien() const;
    void setBien(Bien *value);
    bool getIsPropAchat() const;
    void setIsPropAchat(bool value);
    double getPropAchat() const;
    void setPropAchat(double value);

    string getEtat() const;
    void setEtat(const string &value);
};

#endif // VISITE_H

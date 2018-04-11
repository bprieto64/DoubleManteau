#ifndef ADRESSE_H
#define ADRESSE_H


class adresse
{
private:
    int numRue;
    string nomRue;
    string ville;
    int codePostal;

public:
    adresse();
    adresse(int,string,string,int);


    string getVille() const;
    void setVille(const string &value);

    int getCodePostal() const;
    void setCodePostal(int value);

    string getNomRue() const;
    void setNomRue(const string &value);

    int getNumRue() const;
    void setNumRue(int value);

    void afficher() const;
};

#endif // ADRESSE_H

#ifndef CLIENT_H
#define CLIENT_H
#include <string>
using namespace std;

class Client
{
protected:
    string nom;
    string adresse;
public:
    Client();
    Client(string nom, string adresse);
    string getNom() const;
    void setNom(const string &value);
    string getAdresse() const;
    void setAdresse(const string &value);
};

#endif // CLIENT_H

#include <QCoreApplication>
#include "iostream"
#include "bien.h"
#include "appartement.h"
#include "immeuble.h"
#include "client.h"
#include "clientvendeur.h"
using namespace std;

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

cout<< "Bienvenue sur la nouvelle application de la société Un toit pour TOUS. "<<endl;


while(1==1){
    cout << "Avant de vendre votre toit ou d'en trouver un, merci de nous dire qui vous êtes?"<<endl;
            cout << "(1) Client vendeur"<<endl;
            cout <<"(2) Client acheteur"<<endl;



}











/*

    cout<<"salut"<<endl;
    Bien b1=Bien(12445,"rue des Paumiers 33 Bordeaux",120000,120,125);
    Immeuble im1;
    Appartement ap1=Appartement(2,3,true,false,true,152144,"rue des lilas",540000,121,125);
   Appartement ap2= Appartement(1,2,true,true,true,12,"rue des cordeliers",45000,12,123);
    b1.afficher();
    im1.ajouterNouveauAppartement(ap1);
    im1.ajouterNouveauAppartement(ap2);
    cout<<im1.getNbrAppart()<<endl;
    im1.getAppartements().at(1).afficher();

*/
    return a.exec();
}

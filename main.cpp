#include <QCoreApplication>
#include "iostream"
#include "bien.h"
#include "appartement.h"
#include "immeuble.h"
#include "client.h"
#include "clientvendeur.h"
#include "clientacheteur.h"
#include "agence.h"
using namespace std;

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    cout<< "Bienvenue sur la nouvelle application de la societe Un toit pour TOUS. "<<endl;
    Agence A;
    ClientVendeur *c=  new ClientVendeur(128,"coucou", Adresse(1,"rue des acacias",40160,"Ychoux"));
    A.ajouterNouveauClientVendeur(*c);
    A.ajouterNouveauClientAcheteur(ClientAcheteur(129,"rue des palmiers",Adresse(2,"chemin de Cabeil",40160,"Ychoux")));
    //ClientVendeur * c=A.isClientExiste(128);


    //cout<<c->getNom()<<endl;
    Appartement *appart= new Appartement(2,2,true,true,true,123,Adresse(99,"chemin des choureuts",40160,"Ychoux"),123,123,c);
    A.ajouterNouveauBien(appart);





    string var="10";
    while(1==1){


        do {
            cout << "Avant de vendre votre toit ou d'en trouver un, merci de nous dire qui vous etes?"<<endl;
            cout << "(1) Client vendeur"<<endl;
            cout <<"(2) Client acheteur"<<endl;

            getline(cin,var);

            cout<<var<<endl;


        }
        while(var != "1" && var !="2");


        if(var=="1"){

            //le client est un client vendeur

            var="0";
            do {
                cout<<"Quel est votre identifiant svp?"<<endl;

                getline(cin,var);



            }
            while(A.isClientExisteV(stoi(var))!=true);
            ClientVendeur  cv=A.recupererClientVendeur(stoi(var));

            var="0";
            do {

                cout<<"(1) Ajouter un bien a vendre."<<endl;
                cout<<"(2) Consulter mes biens a vendre."<<endl;
                cout<<"(3) Consulter mes offres d achats."<<endl;

                getline(cin,var);
            }

            while(var != "1" && var !="2" && var !="3");


            if(var=="1"){//ajouter un bien à vendre
            A.AjouterBienAVendre(&cv);
            }
            if(var=="2"){
                A.consulterMesBiensAVendre(&cv);
            }


        }
        else if(var =="2"){// le client est acheteur


        }
    }

    return a.exec();
}













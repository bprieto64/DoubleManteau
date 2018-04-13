#include <QCoreApplication>
#include "iostream"
#include "bien.h"
#include "appartement.h"
#include "immeuble.h"
#include "client.h"
#include "clientvendeur.h"
#include "clientacheteur.h"
#include "agence.h"
#include "terrain.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    cout<< "Bienvenue sur la nouvelle application de la societe Un toit pour TOUS. "<<endl;
    Agence A;
    ClientVendeur *c=  new ClientVendeur(128,"coucou", Adresse(1,"rue des acacias",40160,"Ychoux"));
    A.ajouterNouveauClientVendeur(*c);
    ClientVendeur *iencli=  new ClientVendeur(158,"michel", Adresse(6,"boulevard victor hugo",40160,"Bias"));
    A.ajouterNouveauClientAcheteur(ClientAcheteur(129,"rue des palmiers",Adresse(2,"chemin de Cabeil",40160,"Ychoux")));
    //ClientVendeur * c=A.isClientExiste(128);


    //cout<<c->getNom()<<endl;
    Appartement *appart= new Appartement(2,2,true,true,true,123,Adresse(99,"chemin des choureuts",40160,"Ychoux"),123000,123,c);
    A.ajouterNouveauBien(appart);

    Maison *m = new Maison(5,true,true,true,3,Adresse(24,"chemin d'Usta",64480,"Ustaritz"),127.5,2,c);
    A.ajouterNouveauBien(m);

    Terrain * rrainte=new Terrain(true,125121244,Adresse(18,"rue de la victoire",33000,"Bordeaux"),12500,1256,iencli);
    A.ajouterNouveauBien(rrainte);







    string var="10";
    while(1==1){


        do {
            cout << "Avant de vendre votre toit ou d'en trouver un, merci de nous dire qui vous etes?"<<endl;
            cout << "(1) Client vendeur"<<endl;
            cout <<"(2) Client acheteur"<<endl;
            cout <<"(3) Creer un compte"<<endl;


            getline(cin,var);


        }
        while(var != "1" && var !="2" && var !="3" );


        if(var=="1"){//le client est un client vendeur




            var="0";
            do {
                cout<<"Quel est votre identifiant svp?"<<endl;

                getline(cin,var);
            }
            while(A.isClientExisteV(stoi(var))!=true);

            ClientVendeur cv=A.recupererClientVendeur(stoi(var));
            while(1==1){
                var="0";
                do {
                    cout<<"Que voulez vous faire?"<<endl;
                    cout<<"(1) Ajouter un bien a vendre."<<endl;
                    cout<<"(2) Ajouter un/des bien(s) a vendre a partir d'un fichier."<<endl;
                    cout<<"(3) Consulter mes biens a vendre."<<endl;
                    cout<<"(4) Consulter mes offres d achats."<<endl;
                    cout<<"(5) Deconnexion"<<endl;
                    getline(cin,var);
                }

                while(var != "1" && var !="2" && var !="3" && var !="4" && var !="5");


                if(var=="1"){//ajouter un bien à vendre
                    A.AjouterBienAVendre(&cv);
                }
                if(var=="2"){//ajouter un bien à vendre via fichier
                A.AjouterBienViaFichier(&cv);

                }

                else if(var=="3"){//Consulter mes biens a vendre
                    var="0";
                    A.consulterMesBiensAVendre(&cv);

                    do{
                        cout << "Voulez-vous consulter les details d'une offre ?" << endl;
                        cout<<"(1) Oui"<<endl;
                        cout<<"(2) Non"<<endl;

                        getline(cin,var);
                    }
                    while(var != "1" && var!="2");

                    if(var=="1"){
                        cout << "De quel bien voulez-vous consulter les details ?" << endl;
                        getline(cin,var);
                        int numB=stoi(var);
                        A.consulterDetailsBien(numB);
                    }




                }
                else if(var=="4"){
                    A.consulterMesOffresAchats(&cv);

                }
                else if(var=="5"){
                    cout<<"A bientot sur Un toit pour TOUS"<<endl;
                    break;
                }

            }
        }
        else if(var =="2"){// le client est acheteur
            var="0";
            do {
                cout<<"Quel est votre identifiant svp?"<<endl;

                getline(cin,var);
            }
            while(A.isClientExisteA(stoi(var))!=true);

            ClientAcheteur ca = A.recupererClientAcheteur(stoi(var));

            while(1==1){
                var="0";
                do{
                    cout<<"Que voulez vous faire?"<<endl;
                    cout<<"(1) Consulter les biens."<<endl;
                    cout<<"(2) Consulter un certain type de bien"<<endl;
                    cout<<"(3) Consulter les resultats de mes propositions d'achats."<<endl;
                    cout<<"(4) Deconnexion"<<endl;

                    getline(cin,var);
                }
                while(var != "1" && var!="2" && var!="3" && var!="4");

                if(var=="1"){


                    A.consulterBien();
                    var="0";
                    do{
                        cout << "Voulez-vous consulter les details d'une offre ?" << endl;
                        cout<<"(1) Oui"<<endl;
                        cout<<"(2) Non"<<endl;

                        getline(cin,var);
                    }
                    while(var != "1" && var!="2");
                    if(var=="1"){
                        cout << "De quel bien voulez-vous consulter les details ?" << endl;
                        getline(cin,var);
                        int numB=stoi(var);
                        A.consulterDetailsBien(numB);
                        var="0";
                        do{
                            cout<<"Voulez vous faire une visite?"<<endl;
                            cout<<"(1) Oui"<<endl;
                            cout<<"(2) Non"<<endl;
                            getline(cin,var);

                        }while(var != "1" && var!="2");

                        if(var=="1"){
                            A.faireVisite(&ca,numB);
                        }


                    }




                }
                else if(var=="2"){
                    A.afficherCategorieBiens();
                    var="0";
                    do{
                        cout << "Voulez-vous consulter les details d'une offre ?" << endl;
                        cout<<"(1) Oui"<<endl;
                        cout<<"(2) Non"<<endl;

                        getline(cin,var);
                    }
                    while(var != "1" && var!="2");
                    if(var=="1"){
                        cout << "De quel bien voulez-vous consulter les details ?" << endl;
                        getline(cin,var);
                        int numB=stoi(var);
                        A.consulterDetailsBien(numB);
                        var="0";
                        do{
                            cout<<"Voulez vous faire une visite?"<<endl;
                            cout<<"(1) Oui"<<endl;
                            cout<<"(2) Non"<<endl;
                            getline(cin,var);

                        }while(var != "1" && var!="2");

                        if(var=="1"){
                            A.faireVisite(&ca,numB);
                        }


                    }









                }
                else if(var=="3"){
                    A.consulteReponseOffreAchat(&ca);
                }
                else if(var=="4"){
                    cout<<"A bientot sur Un toit pour TOUS"<<endl;
                    break;
                }

            }
        }
        else if(var=="3"){
            A.creerClient();
        }

    }
    return a.exec();
}













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

    cout<< "Bienvenue sur la nouvelle application de la société Un toit pour TOUS. "<<endl;
    Agence A;
    ClientVendeur c= ClientVendeur(128,"coucou","kiki");
    A.ajouterNouveauClientVendeur(c);
    A.ajouterNouveauClientAcheteur(ClientAcheteur(129,"rue des palmiers","xakura"));
    //ClientVendeur * c=A.isClientExiste(128);
    A.ajouterNouveauBien(Bien(1,"rue des pisicne",12,12,c));

    //cout<<c->getNom()<<endl;


    A.ajouterNouveauBien(Appartement(2,2,true,true,true,123,"kiki",123,123,c));


    string var="10";
    while(1==1){


        do {
            cout << "Avant de vendre votre toit ou d'en trouver un, merci de nous dire qui vous êtes?"<<endl;
            cout << "(1) Client vendeur"<<endl;
            cout <<"(2) Client acheteur"<<endl;
            cin>>var;


        }
        while(var != "1" && var !="2");


        if(var=="1"){//le client est un client vendeur

            var="0";
            do {
                cout<<"Quel est votre identifiant svp?"<<endl;
                cin>>var;



            }
            while(A.isClientExisteV(stoi(var))!=true);
            ClientVendeur cv=A.recupererClientVendeur(stoi(var));

            var="0";
            do {

                cout<<"(1) Ajouter un bien à vendre."<<endl;
                cout<<"(2) Consulter mes biens a vendre."<<endl;
                cout<<"(3) Consulter mes offres d'achats."<<endl;
                cin>>var;
            }

            while(var != "1" && var !="2" && var !="3");


            if(var=="1"){//ajouter un bien à vendre

                //ajout de l'identifiant
                unsigned int identifiant = A.getBiens().back().getIdentifiant() +1;
                cout<<identifiant<<endl;

                //ajout de l'adresse
                cout<<"Quel est l'adresse de votre bien ?"<<endl;
                string adresse;
                cin>>adresse;

                //ajout du prix
                cout<<"Quel est le prix de votre bien? "<<endl;
                double prix;
                cin>>var;
                prix=stod(var);

                //ajout des m²
                cout<<"Quel est le nombre de metres carres de votre bien? "<<endl;
                double mCarre;
                cin>>var;
                mCarre=stod(var);

                var="0";
                do{

                    cout<<"Quel type de bien souhaitez vous ajouter?"<<endl;
                        cout<<"(1) Un appartement "<<endl;
                        cout<<"(2) Une maison"<<endl;
                        cout<<"(3) Un terrain "<<endl;
                        cout<<"(4) Un local professionnel "<<endl;
                        cin>>var;

                } while(var != "1" && var !="2" && var!="3" && var!="4");

                if(var=="1"){ // APPARTEMENT

                    cout<<"A quel etage est situe l'appartement?"<<endl;
                    unsigned int etage;
                    cin>>var;
                    etage=stoul(var);

                    cout<<"Combien de pièces possèdent il ? "<<endl;
                    unsigned int pieces;
                    cin>>var;
                    pieces=stoul(var);


                    do{
                        cout<<"Votre appartement possède il un garage ? "<<endl;
                            cout<<"(1) oui"<<endl;
                            cout<<"(2) non"<<endl;


                    }while(var != "1" && var !="2");
                    bool hasGarage;
                    if(var=="1"){
                        hasGarage=true;

                    }
                    else{
                        hasGarage =false;
                    }




                    do{
                        cout<<"Votre appartement possède il une cave ? "<<endl;
                            cout<<"(1) oui"<<endl;
                            cout<<"(2) non"<<endl;


                    }while(var != "1" && var !="2");

                    bool hasCave;
                    if(var=="1"){
                        hasCave=true;

                    }
                    else{
                        hasCave =false;
                    }

                do{
                    cout<<"Votre appartement possède il un balcon ? "<<endl;
                        cout<<"(1) oui"<<endl;
                        cout<<"(2) non"<<endl;


                }while(var != "1" && var !="2");

                bool hasBalcon;
                if(var=="1"){
                    hasBalcon=true;

                }
                else{
                    hasBalcon =false;
                }



                A.ajouterNouveauBien(Appartement(pieces,etage,hasGarage,hasCave,hasBalcon,identifiant,adresse,prix,mCarre,cv));

                for(int i=0;i<A.getBiens().size();i++){
                    A.getBiens()[i].afficher();
                }

                }


            }





        }
        else if(var =="2"){// le client est acheteur


        }
    }

    return a.exec();
}













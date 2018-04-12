#include "agence.h"

using namespace std;

Agence::Agence()
{

}

std::vector<Bien*> Agence::getBiens() const
{
    return biens;
}

void Agence::consulterBien(){
    for(unsigned i=0; i<biens.size();i++){
        cout << "(" << i << ")";
        biens[i]->affichageSimple();
         cout<<"---------------------------------------------------------"<<endl;
    }
}

void Agence::consulterDetailsBien(int ienb){
    biens[ienb]->afficherTout();
}

void Agence::faireVisite(ClientAcheteur *ca,int identifiant)
{
    Bien * bien=biens[identifiant];
    string var="0";
    cout<<"Visite en cours"<<endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    cout<<"..."<<endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    cout<<"Visite terminer"<<endl;


    do{
        cout<<"Souhaitez vous faire une offre d'achat?"<<endl;
        cout<<"(1) oui"<<endl;
        cout<<"(2) non"<<endl;

        getline(cin,var);

    }while(var != "1" && var !="2");

    if(var=="1"){//veut faire une offre d'achat
                cout<<"Quel est le montant de votre offre d'achat? ( en euros)"<<endl;
                double offreAchat=0;
                getline(cin,var);
               offreAchat=stod(var);
           carnetVisites.insert(pair<ClientAcheteur*,Visite*>(ca,new Visite(bien,true,offreAchat,"ATTENTE")));
    }
    else if(var=="2"){// pas df'offre d'achat
          carnetVisites.insert(pair<ClientAcheteur*,Visite*>(ca,new Visite(bien,false,0,"NOETAT")));
    }


}

void Agence::consulterMesOffresAchats(ClientVendeur *cv)
{
    string var="0";
    for(map<ClientAcheteur*,Visite*>::iterator it =carnetVisites.begin(); it!=carnetVisites.end() ; it++){
        if((it->second->getEtat()=="ATTENTE") && (it->second->getBien()->getRefClientVendeur()->getIdentifiant() == cv->getIdentifiant())){

            cout<<"La proposition d'achat est de : "<<it->second->getPropAchat()<<" euros"<<endl;
            cout <<"Elle a ete fait sur le bien suivant"<<endl;
            it->second->getBien()->affichageSimple();

            do{
                cout<<"Souhaitez vous accepter ou refuser cette offre d'achat ? "<<endl;
                cout<<"(1) Accepter"<<endl;
                cout<<"(2) Refuser "<<endl;

                getline(cin,var);

            }while(var != "1" && var !="2");
            if(var=="1"){
               it->second->setEtat("ACCEPTER");
            cout<<"Vous avez accepté cette offre d'achat"<<endl;
            cout<<"Merci d'avoir fait confiance a Un toit pour TOUS"<<endl;
            }
            else if(var=="2"){
               it->second->setEtat("REFUSER");
            cout<<"Vous avez refuser cette offre d'achat"<<endl;

            }



        }
    }

}


void Agence::consulterMesBiensAVendre(ClientVendeur *cv)
{

    for(unsigned i=0; i<biens.size();i++){
         if(biens[i]->getRefClientVendeur()->getIdentifiant()==cv->getIdentifiant()){
             cout << "(" << i << ")";
         biens[i]->affichageSimple();
         cout<<"---------------------------------------------------------"<<endl;
         }
     }


}
std::vector<ClientVendeur> Agence::getCarnetClientsVendeurs() const
{
    return carnetClientsVendeurs;
}
std::vector<ClientAcheteur> Agence::getCarnetClientsAcheteurs() const
{
    return carnetClientsAcheteurs;
}




void Agence::ajouterNouvelleVisite(ClientAcheteur *clientAcheteur, Visite *visite)
{
    carnetVisites.insert(pair<ClientAcheteur*,Visite*>(clientAcheteur,visite));
}

void Agence::supprimerVisite(ClientAcheteur *clientAcheteur, double propAchat,unsigned int identifiant) // A TESTER:  PAS SUR DU TOUT
{

    for(map<ClientAcheteur*,Visite*>::iterator it =carnetVisites.begin(); it!=carnetVisites.end() ; it++){

        if(((it->second->getBien()->getIdentifiant())==identifiant) && (it->second->getPropAchat())==propAchat && (clientAcheteur==(it->first))  ){
            carnetVisites.erase(it);
            break;
        }
    }
}


void Agence::ajouterNouveauClientVendeur(ClientVendeur client)
{
    carnetClientsVendeurs.push_back(client);
}

void Agence::supprimerClientVendeur(unsigned int identifiant)
{
    for(vector<ClientVendeur>::iterator i = carnetClientsVendeurs.begin();i !=carnetClientsVendeurs.end() ; i++){
        if(i->getIdentifiant()==identifiant){

            carnetClientsVendeurs.erase(i);
        }
    }
}

bool Agence::isClientExisteV(unsigned int identifiant)
{

    for(unsigned i=0; i<carnetClientsVendeurs.size();i++){
        if(carnetClientsVendeurs[i].getIdentifiant()==identifiant){

            return true;
        }
    }
    return false;

}

ClientVendeur Agence::recupererClientVendeur(unsigned int identifiant)
{
    for(vector<ClientVendeur>::iterator i = carnetClientsVendeurs.begin();i !=carnetClientsVendeurs.end() ; i++){
        if(i->getIdentifiant()==identifiant){
            return *i;
        }
    }

}

void Agence::ajouterNouveauClientAcheteur(ClientAcheteur client)
{
    carnetClientsAcheteurs.push_back(client);
}

void Agence::supprimerClientAcheteur(unsigned int identifiant)
{
    for(vector<ClientAcheteur>::iterator i = carnetClientsAcheteurs.begin();i !=carnetClientsAcheteurs.end() ; i++){
        if(i->getIdentifiant()==identifiant){

            carnetClientsAcheteurs.erase(i);
        }
    }

}

bool Agence::isClientExisteA(unsigned int identifiant)
{

    for(unsigned i=0; i<carnetClientsAcheteurs.size();i++){
        if(carnetClientsAcheteurs[i].getIdentifiant()==identifiant){

            return true;
        }
    }
    return false;

}

ClientAcheteur Agence::recupererClientAcheteur(unsigned int identifiant)
{
    for(vector<ClientAcheteur>::iterator i = carnetClientsAcheteurs.begin();i !=carnetClientsAcheteurs.end() ; i++){
        if(i->getIdentifiant()==identifiant){
            return *i;
        }
    }

}

void Agence::ajouterNouveauBien(Bien * bien)
{
    biens.push_back(bien);
}

void Agence::AjouterBienAVendre(ClientVendeur *cv)
{
    string var="0";

    //ajout de l'identifiant
    unsigned int identifiant = biens.back()->getIdentifiant() +1;
    //cout<<identifiant<<endl;

    //ajout de l'adresse
    cout<<"Quel est numero de rue de votre bien ?"<<endl;

    int numRue;
    getline(cin,var);
    numRue=stoi(var);

    cout << "Quel est le nom de rue de votre bien ?" << endl;
    string nomRue;

    getline(cin,nomRue);

    cout << "Quel est le code postal de votre bien ?" << endl;
    int cp;
    getline(cin,var);
    cp=stoi(var);

    cout << "Quelle est la ville de votre bien ?" << endl;
    string ville;
    getline(cin,ville);

    //getline(cin,var);

    //ajout du prix
    cout<<"Quel est le prix de votre bien? "<<endl;
    double prix;

    getline(cin,var);
    prix=stod(var);

    //ajout des m²
    cout<<"Quel est le nombre de metres carres de votre bien? "<<endl;
    double mCarre;

    getline(cin,var);
    mCarre=stod(var);

    var="0";
    do{

        cout<<"Quel type de bien souhaitez vous ajouter?"<<endl;
        cout<<"(1) Un appartement "<<endl;
        cout<<"(2) Une maison"<<endl;
        cout<<"(3) Un terrain "<<endl;
        cout<<"(4) Un local professionnel "<<endl;

        getline(cin,var);

    } while(var != "1" && var !="2" && var!="3" && var!="4");

    if(var=="1"){ // APPARTEMENT

        cout<<"A quel etage est situe l'appartement?"<<endl;
        unsigned int etage;

        getline(cin,var);
        etage=stoul(var);

        cout<<"Combien de pieces possede t il ? "<<endl;
        unsigned int pieces;

        getline(cin,var);
        pieces=stoul(var);

        var="0";
        do{
            cout<<"Votre appartement possede t il un garage ? "<<endl;
            cout<<"(1) oui"<<endl;
            cout<<"(2) non"<<endl;

            getline(cin,var);

        }while(var != "1" && var !="2");

        bool hasGarage;

        if(var=="1"){
            hasGarage=true;


        }
        else{
            hasGarage =false;
        }



        var="0";
        do{
            cout<<"Votre appartement possede t il une cave ? "<<endl;
            cout<<"(1) oui"<<endl;
            cout<<"(2) non"<<endl;

            getline(cin,var);

        }while(var != "1" && var !="2");

        bool hasCave;
        if(var=="1"){
            hasCave=true;

        }
        else{
            hasCave =false;
        }
        var="0";
        do{
            cout<<"Votre appartement possede t il un balcon ? "<<endl;
            cout<<"(1) oui"<<endl;
            cout<<"(2) non"<<endl;
            getline(cin,var);


        }while(var != "1" && var !="2");

        bool hasBalcon;
        if(var=="1"){
            hasBalcon=true;

        }
        else{
            hasBalcon =false;
        }


        Appartement *ap = new Appartement(pieces,etage,hasGarage,hasCave,hasBalcon,identifiant,Adresse(numRue,nomRue,cp,ville),prix,mCarre,cv);
        ajouterNouveauBien(ap);

        for(unsigned int i=0;i<biens.size();i++){
            biens[i]->afficherTout();
        }

    }
    else if(var=="2"){ //Une maison
        var="0";
        cout<<"Combien de  pieces possedent la maison  ?"<< endl;
        unsigned int nbrPieces;
        getline(cin,var);
        nbrPieces=stoul(var);

        var="0";
        do{
            cout<<"Votre Maison possede il un garage ? "<<endl;
            cout<<"(1) oui"<<endl;
            cout<<"(2) non"<<endl;

            getline(cin,var);

        }while(var != "1" && var !="2");

        bool hasGarage;

        if(var=="1"){
            hasGarage=true;


        }
        else{
            hasGarage =false;
        }

        var="0";
        do{
            cout<<"Votre Maison possede il un jardin ? "<<endl;
            cout<<"(1) oui"<<endl;
            cout<<"(2) non"<<endl;

            getline(cin,var);

        }while(var != "1" && var !="2");

        bool hasJardin;
        if(var=="1"){
            hasJardin=true;

        }
        else{
            hasJardin =false;
        }
        var="0";
        do{
            cout<<"Votre maison possede il une piscine  ? "<<endl;
            cout<<"(1) oui"<<endl;
            cout<<"(2) non"<<endl;
            getline(cin,var);


        }while(var != "1" && var !="2");

        bool hasPisine;
        if(var=="1"){
            hasPisine=true;

        }
        else{
            hasPisine =false;
        }

        Maison *mz = new Maison(nbrPieces,hasGarage,hasJardin,hasPisine,identifiant,Adresse(numRue,nomRue,cp,ville),prix,mCarre,cv);
        ajouterNouveauBien(mz);

    }

    else if(var=="3"){//terrain
        var="0";
        do{
            cout<<"Votre terrain est il constructible? "<<endl;
            cout<<"(1) oui"<<endl;
            cout<<"(2) non"<<endl;

            getline(cin,var);

        }while(var != "1" && var !="2");

        bool isConstructible;
        if(var=="1"){
            isConstructible=true;

        }
        else{
            isConstructible =false;
        }

        Terrain *tr = new Terrain(isConstructible,identifiant,Adresse(numRue,nomRue,cp,ville),prix,mCarre,cv);
        ajouterNouveauBien(tr);
    }

    else if(var=="4"){
        var="0";
        cout<<"Quelle est la taille de votre vitrine? (en metres)"<<endl;
        double tailleVitrine;

        getline(cin,var);
        tailleVitrine=stod(var);

        do{
            cout<<"Est ce que vous avez une piece dédie au stockage des materiaux? "<<endl;
            cout<<"(1) oui"<<endl;
            cout<<"(2) non"<<endl;

            getline(cin,var);

        }while(var != "1" && var !="2");

        bool hasStockMat;
        if(var=="1"){
            hasStockMat=true;

        }
        else{
            hasStockMat =false;
        }

        LocauxPro *lc = new LocauxPro(tailleVitrine,hasStockMat,identifiant,Adresse(numRue,nomRue,cp,ville),prix,mCarre,cv);
        ajouterNouveauBien(lc);

    }

}





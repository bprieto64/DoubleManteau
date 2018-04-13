#include "agence.h"
using namespace std;

//CONSTRUCTEUR

Agence::Agence()
{

}

//GETTERS AND SETTERS

std::map<Visite *, ClientAcheteur *> Agence::getCarnetVisites() const
{
    return carnetVisites;
}

std::vector<Bien*> Agence::getBiens() const
{
    return biens;
}

std::vector<ClientVendeur> Agence::getCarnetClientsVendeurs() const
{
    return carnetClientsVendeurs;
}

std::vector<ClientAcheteur> Agence::getCarnetClientsAcheteurs() const
{
    return carnetClientsAcheteurs;
}



//AUTRES METHODES

//Visites

void Agence::ajouterNouvelleVisite(ClientAcheteur *clientAcheteur, Visite *visite)
{
    carnetVisites.insert(pair<Visite*,ClientAcheteur*>(visite,clientAcheteur));
}

void Agence::supprimerVisite(ClientAcheteur *clientAcheteur, double propAchat,unsigned int identifiant)
{
    for(map<Visite*,ClientAcheteur*>::iterator it =carnetVisites.begin(); it!=carnetVisites.end() ; it++){

        if(((it->first->getBien()->getIdentifiant())==identifiant) && (it->first->getPropAchat())==propAchat && (clientAcheteur==(it->second))  ){
            carnetVisites.erase(it);
            break;
        }
    }
}

void Agence::supprimerVisiteEtBien(ClientAcheteur *clientAcheteur)
{
    for(map<Visite*,ClientAcheteur*>::iterator it =carnetVisites.begin(); it!=carnetVisites.end() ; it++){
        if((clientAcheteur==(it->second)) && it->first->getEtat()=="ACCEPTER"){
            carnetVisites.erase(it);
            for(vector<Bien*>::iterator i = biens.begin();i !=biens.end() ; i++){
                if(*i==it->first->getBien()){
                    biens.erase(i);
                }
            }
            break;
        }
    }
}

void Agence::faireVisite(ClientAcheteur *ca,int identifiant)
{
    Bien * bien=biens[identifiant];
    string var="0";
    cout<<"Visite en cours"<<endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    cout<<"..."<<endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    cout<<"Visite terminee"<<endl;

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
        carnetVisites.insert(make_pair(new Visite(bien,true,offreAchat,"ATTENTE"),ca));
    }
    else if(var=="2"){// pas d'offre d'achat
        carnetVisites.insert(make_pair(new Visite(bien,false,0,"NOETAT"),ca));
    }
}

//Client Vendeur

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

void Agence::ajouterVendeurViaFichier(){
    ifstream fichier("./fichierTxt/vendeurs.cpp");

    string ligne;
    vector<string> vecStr;
    unsigned int id;
    string nom;
    unsigned int numRue;
    string nomRue;
    unsigned int cp;
    string ville;
    unsigned int count=0;
    int nbTabl;

    if(fichier){
        while (getline(fichier,ligne)) {
            id=carnetClientsVendeurs.size()+1;
            count++;
            nbTabl=split(vecStr,ligne,'|');
            nom=vecStr[0];
            numRue=stoul(vecStr[1]);
            nomRue=vecStr[2];
            ville=vecStr[3];
            cp=stoul(vecStr[4]);
        }
        ajouterNouveauClientVendeur(ClientVendeur(id,nom,Adresse(numRue,nomRue,cp,ville)));

        cout<<count<< " vendeurs ont ete ajoutes."<<endl;
        fichier.close();
    }
    else
        cout << "Impossible d'ouvrir le fichier" << endl;
}

//Client

void Agence::creerClient()
{
    string var="0";
    unsigned int identifiant;
    if(carnetClientsAcheteurs.back().getIdentifiant()>carnetClientsVendeurs.back().getIdentifiant()){
        identifiant=carnetClientsAcheteurs.back().getIdentifiant()+1;
    }
    else{
        identifiant=carnetClientsVendeurs.back().getIdentifiant()+1;
    }
    string nom="rien";
    cout<<"Quel est votre nom ? "<<endl;
    getline(cin,nom);
    unsigned int numRue;
    string nomAdresse;
    unsigned int codePostal;
    string ville;

    cout <<"Quel est le numero de votre adresse?"<<endl;
    getline(cin,var);
    numRue=stoul(var);

    cout<<"Quel est l'intitule de votre adresse?"<<endl;
    getline(cin,nomAdresse);

    cout<<"Quel est votre code postal?"<<endl;
    getline(cin,var);
    codePostal=stoul(var);

    cout<<"Quel est votre ville?"<<endl;
    getline(cin,ville);
    var="0";

    do{

        cout<<"Etes vous un client acheteur ou un client vendeur?"<<endl;
        cout<<"(1) Client acheteur"<<endl;
        cout<<"(2) Client vendeur"<<endl;
        getline(cin,var);

    } while(var != "1" && var !="2" );

    if(var=="1"){
        carnetClientsAcheteurs.push_back(ClientAcheteur(identifiant,nom,Adresse(numRue,nomAdresse,codePostal,ville)));
    }
    else if(var =="2"){
        carnetClientsVendeurs.push_back(ClientVendeur(identifiant,nom,Adresse(numRue,nomAdresse,codePostal,ville)));
    }
    cout<<"Compte creer. Bienvenue sur Un toit pour TOUS et bonne chance dans vos projets!"<<endl;
    cout<<"Votre identifiant de connexion est le : "<<identifiant<<endl;
    cout<<endl;
}

//Client acheteur

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

void Agence::ajouterAcheteurViaFichier(){
    ifstream fichier("./fichierTxt/acheteurs.cpp");

    string ligne;
    vector<string> vecStr;
    unsigned int id;
    string nom;
    unsigned int numRue;
    string nomRue;
    unsigned int cp;
    string ville;
    unsigned int count=0;
    int nbTabl;

    if(fichier){
        while (getline(fichier,ligne)) {
            id=carnetClientsAcheteurs.size()+1;
            count++;
            nbTabl=split(vecStr,ligne,'|');
            nom=vecStr[0];
            numRue=stoul(vecStr[1]);
            nomRue=vecStr[2];
            ville=vecStr[3];
            cp=stoul(vecStr[4]);
        }
        ajouterNouveauClientAcheteur(ClientAcheteur(id,nom,Adresse(numRue,nomRue,cp,ville)));
        cout<<count<< " acheteurs ont ete ajoutes."<<endl;
        fichier.close();
    }
    else
        cout << "Impossible d'ouvrir le fichier" << endl;
}


//BIEN

void Agence::ajouterNouveauBien(Bien * bien)
{
    biens.push_back(bien);
}

void Agence::AjouterBienViaFichier(ClientVendeur *cv)
{

    ifstream fichier("./fichierTxt/biens.cpp", ios::in);
    string ligne="";
    vector<string> VecStr;

    unsigned int id;


    unsigned int numRue;
    string nomRue;
    string ville;
    unsigned int codePostal;
    unsigned int prix;
    unsigned int nbPiece;
    unsigned int mCarre;

    unsigned int etage;
    double tailleVitrine;
    bool isConstructible;
    bool hasGarage;
    bool hasCave;
    bool hasJardin;
    bool hasPiscine;
    bool hasBalcon;
    bool hasStockMatos;
    unsigned int count=0;
    int nbTabl;


    if(fichier){
        while(getline(fichier,ligne)){
            id=biens.size()+1;
            count++;
            isConstructible=false;
            hasGarage=false;
            hasCave=false;
             hasJardin=false;
            hasPiscine=false;
            hasBalcon=false;
            hasStockMatos=false;


             nbTabl= split(VecStr, ligne, '|');


             numRue=stoul(VecStr[1]);
             nomRue=VecStr[2];
             ville=VecStr[3];
             codePostal=stoul(VecStr[4]);
             prix=stoul(VecStr[5]);
             mCarre=stoul(VecStr[6]);





             if(VecStr[0]=="m"){
                 nbPiece=stoul(VecStr[7]);
                 if(VecStr[8]=="y"){
                    hasGarage=true;
                 }
                 if(VecStr[9]=="y"){
                    hasJardin=true;
                 }
                 if(VecStr[10]=="y"){
                    hasPiscine=true;
                 }

                 ajouterNouveauBien(new Maison(nbPiece,hasGarage,hasJardin,hasPiscine,id,Adresse(numRue,nomRue,codePostal,ville),prix,mCarre,cv));


             }
             if(VecStr[0]=="a"){
                 nbPiece=stoul(VecStr[7]);
                 etage=stoul((VecStr[8]));
                 if(VecStr[9]=="y"){
                    hasGarage=true;
                 }
                 if(VecStr[10]=="y"){
                    hasCave=true;
                 }
                 if(VecStr[11]=="y"){
                    hasBalcon=true;
                 }
                   ajouterNouveauBien(new Appartement(nbPiece,etage,hasGarage,hasCave,hasBalcon,id,Adresse(numRue,nomRue,codePostal,ville),prix,mCarre,cv));

             }
             if(VecStr[0]=="t"){
                 if(VecStr[7]=="y"){
                    isConstructible=true;
                 }
                 ajouterNouveauBien(new Terrain(isConstructible,id,Adresse(numRue,nomRue,codePostal,ville),prix,mCarre,cv));

             }
             if(VecStr[0]=="l"){
                 tailleVitrine=stod(VecStr[7]);
                 if(VecStr[8]=="y"){
                     hasStockMatos=true;
                 }
                 ajouterNouveauBien(new LocauxPro(tailleVitrine,hasStockMatos,id,Adresse(numRue,nomRue,codePostal,ville),prix,mCarre,cv));
             }



        }
        cout<<count<< " biens ont ete ajoutes."<<endl;


        fichier.close();
    }
    else
        cout << "Impossible d'ouvrir le fichier" << endl;
}

void Agence::AjouterBienAVendre(ClientVendeur *cv)
{
    string var="0";
    unsigned int identifiant = biens.back()->getIdentifiant() +1;

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

    cout<<"Quel est le prix de votre bien? "<<endl;
    double prix;
    getline(cin,var);
    prix=stod(var);

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

void Agence::afficherCategorieBiens()
{
    string var="0";
    string var2="0";
    unsigned  int bInf=0;
    unsigned int bSup=99999999;
    do{
        cout<<"Quel type de bien voulait vous afficher?"<<endl;
        cout<<"(1) Appartement"<<endl;
        cout<<"(2) Maison"<<endl;
        cout<<"(3) Local professionnel"<<endl;
        cout<<"(4) Terrain"<<endl;
        getline(cin,var);
    }while(var != "1" && var!="2" && var!="3" && var!="4");

    do{
        cout<<"Voulez vous choisir une gamme de prix ? ( Les prix pouvant etre negocie avec le vendeur)"<<endl;
        cout<<"(1) Oui"<<endl;
        cout<<"(2) Non"<<endl;
        getline(cin,var2);
    }while(var2 != "1" && var2!="2");

    if(var2=="1"){

        cout<<"Merci de preciser la borne inferieur."<<endl;
        getline(cin,var2);
        bInf=stoul(var2);
        var2="0";

        cout<<"Merci de preciser la borne superieur."<<endl;
        getline(cin,var2);
        bSup=stoul(var2);
        if(var=="1"){
            afficherCategorieBiensEtPrix("a",bInf,bSup);
        }
        else if(var=="2"){
            afficherCategorieBiensEtPrix("m",bInf,bSup);
        }
        else if(var=="3"){
            afficherCategorieBiensEtPrix("l",bInf,bSup);
        }
        else if(var=="4"){
            afficherCategorieBiensEtPrix("t",bInf,bSup);
        }
    }
    else if(var2=="2"){
        if(var=="1"){
            afficherCategorieBiensEtPrix("a",bInf,bSup);
        }
        else if(var=="2"){
            afficherCategorieBiensEtPrix("m",bInf,bSup);
        }
        else if(var=="3"){
            afficherCategorieBiensEtPrix("l",bInf,bSup);
        }
        else if(var=="4"){
            afficherCategorieBiensEtPrix("t",bInf,bSup);
        }
    }
}
void Agence::afficherCategorieBiensEtPrix(string cat, unsigned int bInf, unsigned int bSup)
{
    if(cat=="m"){
        for(unsigned i=0; i<biens.size();i++){
            if(biens[i] ==dynamic_cast<Maison*>(biens[i]) && biens[i]->getPrix()>bInf && biens[i]->getPrix()<bSup ){
                cout << "(" << i << ")";
                biens[i]->affichageSimple();
                cout<<"---------------------------------------------------------"<<endl;
            }
        }
    }
    else if(cat=="a"){
        for(unsigned i=0; i<biens.size();i++){
            if(biens[i] ==dynamic_cast<Appartement*>(biens[i]) && biens[i]->getPrix()>bInf && biens[i]->getPrix()<bSup ){
                cout << "(" << i << ")";
                biens[i]->affichageSimple();
                cout<<"---------------------------------------------------------"<<endl;
            }
        }
    }
    else if(cat=="l"){
        for(unsigned i=0; i<biens.size();i++){
            if(biens[i] ==dynamic_cast<LocauxPro*>(biens[i]) && biens[i]->getPrix()>bInf && biens[i]->getPrix()<bSup ){
                cout << "(" << i << ")";
                biens[i]->affichageSimple();
                cout<<"---------------------------------------------------------"<<endl;
            }
        }
    }
    else if(cat =="t"){
        for(unsigned i=0; i<biens.size();i++){
            if(biens[i] ==dynamic_cast<Terrain*>(biens[i]) && biens[i]->getPrix()>bInf && biens[i]->getPrix()<bSup ){
                cout << "(" << i << ")";
                biens[i]->affichageSimple();
                cout<<"---------------------------------------------------------"<<endl;
            }
        }
    }
}

//Offres d'achats

void Agence::consulterMesOffresAchats(ClientVendeur *cv)
{
    string var="0";
    for(map<Visite*,ClientAcheteur*>::iterator it =carnetVisites.begin(); it!=carnetVisites.end() ; it++){
        if((it->first->getEtat()=="ATTENTE") && (it->first->getBien()->getRefClientVendeur()->getIdentifiant() == cv->getIdentifiant())){
            cout<<"La proposition d'achat est de : "<<it->first->getPropAchat()<<" euros"<<endl;
            cout <<"Elle a ete fait sur le bien suivant"<<endl;
            it->first->getBien()->affichageSimple();
            var="0";
            do{
                cout<<"Souhaitez vous accepter ou refuser cette offre d'achat ? "<<endl;
                cout<<"(1) Accepter"<<endl;
                cout<<"(2) Refuser "<<endl;

                getline(cin,var);

            }while(var != "1" && var !="2");

            if(var=="1"){
                it->first->setEtat("ACCEPTER");
                cout<<"Vous avez accepte cette offre d'achat"<<endl;
                cout<<"Merci d'avoir fait confiance a Un toit pour TOUS"<<endl;
                cout<<"L'offre sera supprime de l'application apres visualisation de l'acheteur"<<endl;
                cout<<endl;
            }
            else if(var=="2"){
                it->first->setEtat("REFUSER");
                cout<<"Vous avez refuser cette offre d'achat"<<endl;
            }
        }
    }
}

void Agence::consulteReponseOffreAchat(ClientAcheteur *ca)
{
    string var="0";
    unsigned count=0;
    for(map<Visite*,ClientAcheteur*>::iterator it =carnetVisites.begin(); it!=carnetVisites.end() ; it++){
        if((it->first->getEtat()=="ACCEPTER" || it->first->getEtat()=="REFUSER" ) && (it->second==ca)){

            cout<<"Votre offre de "<<it->first->getPropAchat()<<" euros faite sur le bien suivant a ete "<< it->first->getEtat()<<endl;
            it->first->getBien()->affichageSimple();
            cout<<endl;
            if(it->first->getEtat()=="ACCEPTER"){
                cout<<"Vous etes maintenant l'heureux proprietaire de ce bien, nous vous recontacterons pour la signature du sous-seing de la vente"<<endl;
                cout<<"Le bien va etre maintenant supprime de la base de donnees"<<endl;
                count++;
            }
            do{
                cout<<"Pour passer a votre offre suivante appuye sur la touche : k"<<endl;
                getline(cin,var);
            }while(var != "k");
        }
    }
    for(unsigned int i=0;i<count;i++){
        supprimerVisiteEtBien(ca);
    }
}
//methodes usuelles
int Agence::split(vector<string> &vecteur, string chaine, char separateur)
{
    vecteur.clear();

    string::size_type stTemp = chaine.find(separateur);

    while(stTemp != string::npos)
    {
        vecteur.push_back(chaine.substr(0, stTemp));
        chaine = chaine.substr(stTemp + 1);
        stTemp = chaine.find(separateur);
    }

    vecteur.push_back(chaine);

    return vecteur.size();
}



























#include "terrain.h"

//CONSTRUCTOR(S)
Terrain::Terrain()
{

}

Terrain::Terrain(bool eC, unsigned int identifiant, Adresse adresse, double prix,
                 double mCarre, ClientVendeur* refClientVendeur)
    :Bien(identifiant,adresse,prix,mCarre,refClientVendeur)
{
    this->estConstructible=eC;
}

//GETTERS AND SETTERS
bool Terrain::getEstConstructible(){
    return estConstructible;
}

void Terrain::setEstConstructible(bool constructible){
    this->estConstructible=constructible;
}

void Terrain::afficher()
{
    if(estConstructible){
        cout<<"Le terrain est constructible"<<endl;
    }
}

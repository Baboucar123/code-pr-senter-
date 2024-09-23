#include "Client.h"
using namespace std ;
// Constructeur
Client::Client(const string& CIN, const string& nom, const string& prenom,const string& Numero_telephone ,int codeSecret)
    : CIN(CIN), nom(nom), prenom(prenom), codeSecret(codeSecret) {}
    //definitions des fonctions 
string Client::getNom() const {
    return nom;
}
string Client::getPrenom() const {
    return prenom;
}
string Client:: getNumero_telephone() const {
    return 0;
}
// Vérification du code secret
bool Client::verifierCodeSecret(int code) const {
    return code == codeSecret;
}

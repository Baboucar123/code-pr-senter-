#include <iostream>
#include "Compte.h"

using namespace std;

// Constructeur
Compte::Compte(int rib, double solde, const Client& proprietaire)
    : rib(rib), solde(solde), proprietaire(proprietaire) {}

// Accesseurs
int Compte::getRIB() const {
    return rib;
}
double Compte::getSolde() const {
    return solde;
}
Client Compte::getProprietaire() const {
    return proprietaire;
}

// Méthode pour débiter un compte
void Compte::debiter(double montant) {
    if (montant > solde) {
        cout << "Fonds insuffisants." << endl;
    } else {
        solde -= montant;
        cout << "Votre compte a ete debite de " << montant << " euros." << endl;
    }
}
// Méthode pour créditer un compte
void Compte::crediter(double montant) {
    solde += montant;
    cout << "Votre compte a ete credite de " << montant << " euros." << endl;
}
// Méthode pour effectuer un virement
void Compte::virement(Compte& autreCompte, double montant) {
    if (montant > solde) {
        cout << "Fonds insuffisants pour le virement." << endl;
    } else {
        solde -= montant;
        autreCompte.solde += montant;
        cout << "Virement de " << montant << " euros effectue vers le compte de "
             << autreCompte.proprietaire.getNom() << " " << autreCompte.proprietaire.getPrenom() << "." << endl;
    }
}
// Méthode pour consulter le solde
void Compte::consulterSolde() const {
    cout << "Le solde de votre compte est : " << solde << " euros." << endl;
}

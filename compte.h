#ifndef COMPTE_H
#define COMPTE_H

#include "Client.h"

class Compte {
private:
    int rib;
    double solde;
    Client proprietaire;
public:
    // Constructeur
    Compte(int rib, double solde, const Client& proprietaire);
    // les fonctions gets 
    
    int getRIB() const;
    double getSolde() const;
    Client getProprietaire() const;

    // Méthodes pour effectuer des opérations
    void debiter(double montant);
    void crediter(double montant);
    void virement(Compte& autreCompte, double montant);
    void consulterSolde() const;
};

#endif

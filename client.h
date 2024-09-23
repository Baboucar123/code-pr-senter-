#ifndef CLIENT_H
#define CLIENT_H

#include <string>
using namespace std ;
class Client {
private:
    string CIN;
    string nom;
    string prenom;
    string Numero_telephone ;
    int codeSecret;

public:
    // Constructeur avec ces parametres 
    Client(const string& CIN, const string& nom, const string& prenom, const string& Numero_telephone, int codeSecret);

    // des methodes gets pour obtenir les information 
    string getNom() const;
    string getPrenom() const;
    string getNumero_telephone() const ;
    // Vérifier si le code secret est correct
    bool verifierCodeSecret(int code) const;
};

#endif

#include <iostream>
#include "Client.h"
#include "Compte.h"
using namespace std;

void afficherMenu(Compte& compte, Compte comptes[], int nombreComptes);
int main() {
    // Création de 4 clients et de leurs comptes
    Client client1("CIN12345", "Baboucar", "COLY","07498589", 1234);
    Compte compte1(1001, 5000.0, client1);

    Client client2("CIN67890", "Anas", "Elarbaoui","01457896", 5678);
    Compte compte2(1002, 3000.0, client2);

    Client client3("CIN98765", "Ilyas", "Baibbout","04568789", 4321);
    Compte compte3(1003, 4000.0, client3);

    Client client4("CIN54321", "Seynabou", "Diouf","06489716", 8765);
    Compte compte4(1004, 2500.0, client4);

    Compte comptes[4] = {compte1, compte2, compte3, compte4};
    int nombreComptes = 4;

    cout << "Bienvenue dans notre distributeur LCL !" << endl;

    bool fin = false;
    while (!fin) {
        int essaisRestants = 3;
        bool codeValide = false;
        // Boucle pour demander le code avec 3 essais
        while (essaisRestants > 0) {
            cout << "\nVeuillez inserer votre carte bancaire et entrer votre code secret (4 chiffres) : "<<endl;
            int codeSecret;
            cin >> codeSecret;
            // Vérification du code pour chaque compte
            for (int i = 0; i < nombreComptes; ++i) {
                if (comptes[i].getProprietaire().verifierCodeSecret(codeSecret)) {
                    cout << "Bienvenue " << comptes[i].getProprietaire().getNom() << " "
                         << comptes[i].getProprietaire().getPrenom() << " !" << endl;
                    afficherMenu(comptes[i], comptes, nombreComptes);
                    codeValide = true;
                    break;
                }
            }
            if (codeValide) {
                break;  // Si le code est correct, on sort de la boucle
            } else {
                essaisRestants--;
                cout << "Code incorrect. Il vous reste " << essaisRestants << " essai(s)." << endl;
            }
        }
        // Si tous les essais ont échoué
        if (!codeValide) {
            cout << "Votre carte a ete retenue pour des raisons de securite. Veuillez contacter votre banque." << endl;
            break;  // On quitte la boucle principale
        }
// nous demandons au client s'il veut quitter 
        cout << "\nSouhaitez-vous quitter ? (o/n) : ";
        char quitter;
        cin >> quitter;
        if (quitter == 'o' || quitter == 'O') {
            fin = true;
            cout << " veuillez retirer votre carte bancaire" << endl ;
        }
    }
    cout << "Merci de votre visite. A la prochaine !" << endl;
    return 0;
}

// Fonction pour afficher le menu des opérations
void afficherMenu(Compte& compte, Compte comptes[], int nombreComptes) {
    int choix;
    double montant;

    do {
        cout << "\nChoisissez une operation : " << endl;
        cout << "1. Debiter" << endl;
        cout << "2. Crediter" << endl;
        cout << "3. Virement" << endl;
        cout << "4. Consulter solde" << endl;
        cout << "5. Quitter" << endl;
        cin >> choix;

        switch (choix) {
            case 1:
                cout << "Montant a debiter : ";
                cin >> montant;
                compte.debiter(montant);
                break;
            case 2:
                cout << "Montant a crediter : ";
                cin >> montant;
                compte.crediter(montant);
                break;
            case 3: {
                cout << "RIB du destinataire : ";
                int ribDestinataire;
                cin >> ribDestinataire;

                Compte* destinataire = nullptr;
                for (int i = 0; i < nombreComptes; ++i) {
                    if (comptes[i].getRIB() == ribDestinataire) {
                        destinataire = &comptes[i];
                        break;
                    }
                }

                if (destinataire != nullptr) {
                    cout << "Montant du virement : ";
                    cin >> montant;
                    compte.virement(*destinataire, montant);
                } else {
                    cout << "Destinataire introuvable." << endl;
                }
                break;
            }
            case 4:
                compte.consulterSolde();
                break;
            case 5:
                cout << "Deconnexion." << endl;
                break;
            default:
                cout << "Choix invalide." << endl;
        }
    } while (choix != 5);
}

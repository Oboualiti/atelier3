#include <iostream>
using namespace std;

// Classe Client

class Client {
public:
    int id;
    string nom;
    string prenom;

    // Constructeur vide
    Client() : id(0), nom(""), prenom("") {
        cout << "[Client] Constructeur vide appelé." << endl;
    }

    // Constructeur avec paramètres
    Client(int n, string nn, string nnn) : id(n), nom(nn), prenom(nnn) {
        cout << "[Client] Constructeur avec paramètres appelé." << endl;
    }

    // Constructeur de copie
    Client(const Client &p) {
        id = p.id;
        nom = p.nom;
        prenom = p.prenom;
        cout << "[Client] Constructeur de copie appelé." << endl;
    }

    // Méthode d'affichage
    void afficher() const {
        cout << "---- Informations Client ----" << endl;
        cout << "ID       : " << id << endl;
        cout << "Nom      : " << nom << endl;
        cout << "Prénom   : " << prenom << endl;
        cout << "-----------------------------" << endl;
    }

    // Destructeur
    ~Client() {
        cout << "[Client] Destructeur appelé pour " << nom << " " << prenom << endl;
    }
};

// ======================
// Fonction utilitaire inline
// ======================
inline float calculInteret(float solde, float taux) {
    return solde - (solde * taux / 100);
}

// ======================
// Classe Compte
// ======================
class Compte {
private:
    static int nbComptes; // Variable statique pour compter les comptes

public:
    int numero;
    float solde;
    Client *c;

    // Constructeur vide
    Compte() : numero(0), solde(0), c(nullptr) {
        nbComptes++;
        cout << "[Compte] Constructeur vide appelé." << endl;
    }

    // Constructeur avec paramètres
    Compte(int inumero, float isolde, Client *associe)
        : numero(inumero), solde(isolde), c(new Client(*associe)) {
        nbComptes++;
        cout << "[Compte] Constructeur avec paramètres appelé." << endl;
    }

    // Constructeur de copie
    Compte(const Compte &copie) {
        numero = copie.numero;
        solde = copie.solde;
        c = new Client(*copie.c); // Copie profonde
        nbComptes++;
        cout << "[Compte] Constructeur de copie appelé." << endl;
    }

    // Destructeur
    ~Compte() {
        cout << "[Compte] Destructeur appelé pour le compte n°" << numero << endl;
        delete c;
        nbComptes--;
    }

    // Affichage
    void afficher() const {
        cout << "==== Informations Compte ====" << endl;
        cout << "Numéro de compte : " << numero << endl;
        cout << "Solde            : " << solde << " €" << endl;
        cout << "Titulaire        : " << endl;
        if (c != nullptr)
            c->afficher();
        cout << "Nombre total de comptes : " << nbComptes << endl;
        cout << "=============================" << endl;
    }

    // Appliquer un taux d'intérêt via la fonction globale
    void appliquerInteret(float taux) {
        solde = calculInteret(solde, taux);
    }

    // Méthode statique pour obtenir le nombre de comptes
    static int getNbComptes() {
        return nbComptes;
    }
};

// Initialisation du membre statique
int Compte::nbComptes = 0;

// ======================
// Fonction main()
// ======================
int main() {
    cout << "\n--- Création des clients ---\n";
    Client *c1 = new Client(1, "El Boualiti", "Oussama");
    Client *c2 = new Client(2, "Dupont", "Marie");
    Client *c3 = new Client(3, "Ali", "Karim");

    cout << "\n--- Création des comptes ---\n";
    Compte compte1(1001, 5000, c1);
    Compte compte2(1002, 2500, c2);
    Compte compte3(1003, 10000, c3);

    compte1.afficher();
    compte2.afficher();
    compte3.afficher();

    cout << "\n>>> Nombre total de comptes : " << Compte::getNbComptes() << endl;

    cout << "\n--- Test du constructeur de copie ---\n";
    Compte copieCompte1(compte1);
    copieCompte1.numero = 2001;
    copieCompte1.appliquerInteret(5);
    copieCompte1.afficher();

    cout << "\n>>> Nombre total de comptes : " << Compte::getNbComptes() << endl;

    cout << "\n--- Suppression d'un compte ---\n";
    {
        Compte temp(3001, 7000, c2);
        temp.afficher();
        cout << "Suppression automatique à la fin du bloc..." << endl;
    } // le destructeur est appelé ici automatiquement

    cout << "\n>>> Nombre total de comptes après suppression : " << Compte::getNbComptes() << endl;

    cout << "\n--- Application d'intérêts sur les comptes restants ---\n";
    compte1.appliquerInteret(3);
    compte1.afficher();

    compte2.appliquerInteret(2);
    compte2.afficher();

    cout << "\n>>> Nombre total final de comptes : " << Compte::getNbComptes() << endl;

    // Libération mémoire des clients créés dans le main
    delete c1;
    delete c2;
    delete c3;

    cout << "\n--- Fin du programme ---\n";
    return 0;
}


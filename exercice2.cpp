#include <iostream>

using namespace std;

class Fichier {
private:
    char* P;      
    int longueur; 

public:
    // Constructeur
    Fichier() {
        P = nullptr;
        longueur = 0;
        cout << "Constructeur : objet Fichier créé." << endl;
    }

    //  Méthode Creation 
    void Creation(int n) {
        longueur = n;
        P = new char[longueur]; // allocation dynamique
        cout << "Espace mémoire de " << longueur << " octets alloué." << endl;
    }

    //Méthode Remplit 
    void Remplit() {
        if (P == nullptr) {
            cout << "Erreur : mémoire non allouée !" << endl;
            return;
        }

        // remplir arbitrairement (par exemple des lettres A, B, C, ...)
        for (int i = 0; i < longueur; ++i)
            P[i] = 'A' + (i % 26);

        cout << "Mémoire remplie avec des données fictives." << endl;
    }

    //  Méthode Affiche 
    void Affiche() {
        if (P == nullptr) {
            cout << "Erreur : rien à afficher (mémoire vide) !" << endl;
            return;
        }

        cout << "Contenu du fichier en mémoire : ";
        for (int i = 0; i < longueur; ++i)
            cout << P[i];
        cout << endl;
    }

    // Destructeur 
    ~Fichier() {
        if (P != nullptr) {
            delete[] P;
            cout << "Destructeur : mémoire libérée (" << longueur << " octets)." << endl;
        } else {
            cout << "Destructeur : aucune mémoire à libérer." << endl;
        }
    }
};


int main() {
    


    Fichier* f = new Fichier();

    // Appels des trois méthodes
    f->Creation(20); 
    f->Remplit();    
    f->Affiche();     

    // Destruction de l’objet
    delete f; 

    cout << "=== Fin du programme ===" << endl;
    return 0;
}


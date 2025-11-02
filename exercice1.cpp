#include <iostream>
using namespace std;

class Pile {
private:
    int elements[100]; // tableau de 100 éléments max
    int taille;        // nombre d’éléments dans la pile

public:
    // --- Constructeur ---
    Pile() {
        taille = 0;
        cout << "Pile créée avec succès !" << endl;
    }

    // --- Vérifie si la pile est vide ---
    bool pileVide() {
        return taille == 0;
    }

    // --- Vérifie si la pile est pleine ---
    bool pilePleine() {
        return taille >= 100;
    }

    // --- Empiler un élément ---
    void empiler(int x) {
        if (pilePleine()) {
            cout << "Erreur : la pile est pleine !" << endl;
            return;
        }
        elements[taille] = x;
        taille++;
        cout << "Élément " << x << " empilé. Taille actuelle : " << taille << endl;
    }

    // --- Dépiler un élément ---
    int depiler() {
        if (pileVide()) {
            cout << "Erreur : la pile est vide !" << endl;
            return -1;
        }
        taille--;
        cout << "Élément " << elements[taille] << " dépilé. Taille actuelle : " << taille << endl;
        return elements[taille];
    }

    // --- Afficher le contenu de la pile ---
    void afficher() {
        cout << "Contenu de la pile : ";
        for (int i = 0; i < taille; i++)
            cout << elements[i] << " ";
        cout << endl;
    }

    // --- Destructeur ---
    ~Pile() {
        cout << "Pile détruite." << endl;
    }
};

// =======================
// Programme principal
// =======================
int main() {
    Pile p; // création automatique (appelle le constructeur)

    p.empiler(5);
    p.empiler(10);
    p.empiler(15);
    p.afficher();

    p.depiler();
    p.afficher();

    return 0; // destructeur appelé automatiquement ici
}


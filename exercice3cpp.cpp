#include <iostream>
using namespace std;


struct Element {
    int valeur;          
    Element* suivant;    // pointeur vers l'élément suivant
};


class Liste {
private:
    Element* premier; 

public:
    // --- Constructeur ---
    Liste() {
        premier = nullptr;
        cout << "Liste créée (vide)." << endl;
    }

    //  Méthode pour ajouter au debut
    void ajouterDebut(int val) {
        Element* nouveau = new Element; 
        nouveau->valeur = val;
        nouveau->suivant = premier;    
        premier = nouveau;              
        cout << "Élément ajouté au début : " << val << endl;
    }

    //  Méthode pour supprimer un élément au début
    void supprimerDebut() {
        if (premier == nullptr) {
            cout << "La liste est vide, rien à supprimer." << endl;
            return;
        }

        Element* temp = premier;      // garder l'adresse du premier
        premier = premier->suivant;   // avancer la tête
        cout << "Élément supprimé : " << temp->valeur << endl;
        delete temp;                  // libérer la mémoire
    }

    //  Méthode pour afficher la liste entière 
    void afficher() const {
        if (premier == nullptr) {
            cout << "La liste est vide." << endl;
            return;
        }

        Element* courant = premier;
        cout << "Contenu de la liste : ";
        while (courant != nullptr) {
            cout << courant->valeur << " ";
            courant = courant->suivant;
        }
        cout << endl;
    }

    // Destructeur : libère toute la mémoire 
    ~Liste() {
        Element* courant = premier;
        while (courant != nullptr) {
            Element* suivant = courant->suivant;
            delete courant;
            courant = suivant;
        }
        cout << "Destructeur appelé : mémoire libérée." << endl;
    }
};


// Programme principal

int main() {
    Liste maListe;

    maListe.ajouterDebut(10);
    maListe.ajouterDebut(20);
    maListe.ajouterDebut(30);

    maListe.afficher();

    maListe.supprimerDebut();
    maListe.afficher();

    maListe.supprimerDebut();
    maListe.supprimerDebut();
    maListe.supprimerDebut(); 

    return 0;
}


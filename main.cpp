#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Article {
protected:
    int ref;
    string nom;
    int prix;
    int qte;
public:
    Article();
    virtual ~Article();
    //Getters
    int getRef();
    string getNom();
    int getPrix();
    int getQte();
    //Setters
    void setRef(int r);
    void setNom(string n);
    void setPrix(int p);
    void setQte(int q);
    //toString
    string toString();
};

Article::Article() {
    ref = 0;
    nom = "";
    prix = 0;
    qte = 0;
}

Article::~Article() {
    //Destructeur!
}

int Article::getRef() {
    return ref;
}
string Article::getNom() {
    return nom;
}
int Article::getPrix() {
    return prix;
}
int Article::getQte() {
    return qte;
}

void Article::setRef(int r) {
    ref = r;
}
void Article::setNom(string n) {
    nom = n;
}
void Article::setPrix(int p) {
    prix = p;
}
void Article::setQte(int q) {
    qte = q;
}

string Article::toString() {
    return ("Article: " + nom + " - Référence: " + to_string(ref) + " - Prix: " + to_string(prix) + " - Quantité: " + to_string(qte));
}

class Stock {
protected:
    vector <Article> stock;
public:
    Stock();
    virtual ~Stock();
    Article cherchParRef(int r);
    void ajouterArticle(Article a);
    void afficherArticles();
    void supprimerParRef(int r);
    void modifierParRef(int r);
    Article chercherParNom(string n);
    void chercherParPrix();
    void stockerFichier();
};

Stock::Stock() : stock() {}

Stock::~Stock() {}


Article Stock::cherchParRef(int r) {
    vector<Article>::iterator it=stock.begin();
    while (it != stock.end()) {
        if ((*it).getRef() == r) {
            return *it;
        }
        else ++it;
    }
    if (it == stock.end()) {
        cout << "Inexistant !" << endl;
        return Article();
    }
}

void Stock::ajouterArticle(Article a) {
    vector<Article>::iterator it=stock.begin();
    while (it != stock.end()) {
        if ((*it).getRef() == a.getRef()) {
            break;
        }
        else {
            ++it;
        }
    }
    if (it == stock.end()) stock.push_back(a);
}

void Stock::afficherArticles() {
    vector<Article>::iterator it=stock.begin();
    while (it != stock.end()) {
        cout << (*it).toString() << endl;
        ++it;
    }
}

void Stock::supprimerParRef(int r) {
    vector<Article>::iterator it=stock.begin();
    while (it != stock.end()) {
        if ((*it).getRef() == r) {
            stock.erase(it);
        }
        else {
            ++it;
        }
    }
    if (it == stock.end()) cout << "Inexistant !" << endl;
}

void Stock::modifierParRef(int r) {
    for (int i =0; i < stock.size(); i++) {
        if (stock[i].getRef() == r) {
            int choix;
            cout << "Sélectionner rubrique à modifier: "<< endl;
            cout << "1 pour Nom" << endl;
            cout << "2 pour Prix" << endl;
            cout << "3 pour Quantité" << endl;
            cout << "Autre bouton pour Annuler" << endl;
            cin >> choix;
            if (choix == 1) {
                string newNom;
                cout << "Nouveau Nom: " << endl;
                cin >> newNom;
                stock[i].setNom(newNom);
            }
            else if (choix == 2) {
                int newPrix;
                cout << "Nouveau Prix: " << endl;
                cin >> newPrix;
                stock[i].setPrix(newPrix);
            }
            else if (choix == 3) {
                int newQte;
                cout << "Nouvelle Quantité: " << endl;
                cin >> newQte;
                stock[i].setQte(newQte);
            }
            else cout << "Modification annulée." << endl;
            return;
        }
    }
    cout << "Référence non trouvée !" << endl;
}

Article Stock::chercherParNom(string n) {
    vector<Article>::iterator it=stock.begin();
    while (it != stock.end()) {
        if ((*it).getNom() == n) {
            return *it;
        }
        else {
            ++it;
        }
    }
    if (it == stock.end()) {cout << "Inexistant !" << endl; return Article();}
}

void Stock::chercherParPrix() {
    int pmin, pmax;
    cout << "Saisir les bornes de l'intervalle des prix: " << endl;
    cin >> pmin;
    cin >> pmax;
    vector<Article>::iterator it=stock.begin();
    while (it != stock.end()) {
        if ((*it).getPrix() >= pmin && (*it).getPrix() <= pmax) {
            cout<< it->toString() << endl ;
            ++it;
        }
        else {
            ++it;
        }
    }
    if (it == stock.end()) cout << "Inexistant !" << endl;
}

void Stock::stockerFichier() {
    fstream f("Stock.txt", ios::out|ios::app);
    f << "===== WELCOME TO GRAJA STORE =====" << endl;
    if (!f) {
        cout << "Erreur ouverture du fichier (inexistant)" << endl;
    }
    else {
        for (int i=0; i<stock.size(); i++) {
            f << stock[i].toString() << endl;
        }
        f.close();
    }
}

int main() {
    Stock s;
    int choix;

    do {
        cout << "\n===== WELCOME TO THE GRAJA STORE PRODUCT CUSTOMIZATION =====\n";
        cout << "1. Ajouter un article\n";
        cout << "2. Afficher tous les articles\n";
        cout << "3. Chercher par référence\n";
        cout << "4. Chercher par nom\n";
        cout << "5. Chercher par intervalle de prix\n";
        cout << "6. Supprimer par référence\n";
        cout << "7. Modifier par référence\n";
        cout << "8. Sauvegarder dans le fichier\n";
        cout << "9. Quitter\n";
        cout << "Votre choix : ";
        cin >> choix;

        if (choix == 1) {
            Article a;
            int ref, prix, qte;
            string nom;

            cout << "Nom : ";
            cin >> nom;
            cout << "Référence : ";
            cin >> ref;
            cout << "Prix : ";
            cin >> prix;
            cout << "Quantité : ";
            cin >> qte;

            a.setRef(ref);
            a.setNom(nom);
            a.setPrix(prix);
            a.setQte(qte);

            s.ajouterArticle(a);
        }

        else if (choix == 2) {
            s.afficherArticles();
        }

        else if (choix == 3) {
            int ref;
            cout << "Référence à chercher : ";
            cin >> ref;
            Article a = s.cherchParRef(ref);
            cout << a.toString() << endl;
        }

        else if (choix == 4) {
            string nom;
            cout << "Nom à chercher : ";
            cin >> nom;
            Article a = s.chercherParNom(nom);
            cout << a.toString() << endl;
        }

        else if (choix == 5) {
            s.chercherParPrix();

        }

        else if (choix == 6) {
            int ref;
            cout << "Référence à supprimer : ";
            cin >> ref;
            s.supprimerParRef(ref);
        }
        else if (choix == 7) {
            int ref;
            cout << "Référence à modifier : ";
            cin >> ref;
            s.modifierParRef(ref);
        }
        else if (choix == 8) {
            s.stockerFichier();
            cout << "INFO ACQUIRED" << endl;;
        }
    } while (choix != 9);
    return 0;
}
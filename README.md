🛒 Graja Store — Système de Gestion de Stock
Un programme C++ en ligne de commande pour gérer l'inventaire d'un magasin ou supermarché. Il permet d'ajouter, rechercher, modifier, supprimer des articles, et de sauvegarder le stock dans un fichier.

📋 Fonctionnalités
#FonctionnalitéDescription1Ajouter un articleSaisir nom, référence, prix et quantité2Afficher tous les articlesLister l'ensemble du stock3Chercher par référenceRetrouver un article via son numéro de référence4Chercher par nomRetrouver un article via son nom5Chercher par intervalle de prixFiltrer les articles entre un prix minimum et maximum6Supprimer par référenceRetirer un article du stock7Modifier par référenceMettre à jour le nom, le prix ou la quantité d'un article8SauvegarderExporter le stock dans un fichier Stock.txt9QuitterFermer l'application

🏗️ Architecture du projet
GrajaStore/
├── main.cpp        # Code source principal
├── Stock.txt       # Fichier de sauvegarde (généré à l'exécution)
└── README.md
Classes principales
Article
Représente un produit en stock avec les attributs :

ref — Référence unique (entier)
nom — Nom du produit
prix — Prix unitaire
qte — Quantité disponible

Stock
Gère une collection d'articles (vector<Article>) et expose les opérations CRUD :

ajouterArticle() — Ajoute un article (ignore les doublons de référence)
afficherArticles() — Affiche tout le stock
cherchParRef() — Recherche par référence
chercherParNom() — Recherche par nom
chercherParPrix() — Filtre par intervalle de prix
supprimerParRef() — Supprime un article
modifierParRef() — Modifie un article existant
stockerFichier() — Sauvegarde dans Stock.txt


⚙️ Prérequis

Compilateur C++ supportant C++11 ou supérieur (g++, clang++, MSVC…)
Système : Windows, Linux ou macOS


🚀 Compilation & Exécution
Avec g++ (Linux / macOS / MinGW)
bashg++ -std=c++11 -o graja_store main.cpp
./graja_store
Avec g++ (Windows)
bashg++ -std=c++11 -o graja_store.exe main.cpp
graja_store.exe

💾 Sauvegarde
Le fichier Stock.txt est créé (ou mis à jour) dans le répertoire courant lors de l'utilisation de l'option 8 — Sauvegarder. Chaque appel ajoute les données à la suite du fichier existant (ios::app).
Exemple de contenu généré :
===== WELCOME TO GRAJA STORE =====
Article: Lait - Référence: 101 - Prix: 2 - Quantité: 50
Article: Pain - Référence: 102 - Prix: 1 - Quantité: 120

⚠️ Limitations connues

Les doublons de référence sont ignorés à l'ajout, mais aucun message d'avertissement n'est affiché.
La recherche par prix affiche toujours « Inexistant ! » après avoir itéré, même si des résultats ont été trouvés.
Le fichier Stock.txt est en mode ajout : relancer la sauvegarde plusieurs fois duplique les entrées.
Les noms d'articles contenant des espaces ne sont pas supportés (cin >> s'arrête au premier espace).


🔧 Améliorations possibles

 Utiliser getline() pour les noms avec espaces
 Ajouter un constructeur paramétré à Article
 Réécrire le fichier en mode ios::trunc plutôt qu'ios::app
 Charger le stock depuis le fichier au démarrage
 Ajouter une interface graphique (Qt, wxWidgets…)


👤 Auteur
Projet développé dans le cadre d'un exercice de programmation orientée objet en C++.

// 4D_test.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit

#include <iostream>

using namespace std;

int main()
{
    string chaine;
    int i;

    cout << "Bonjour !" << endl;
    cout << "Entrez la chaine de caracteres a examiner." << endl;
    cin >> chaine;

    for (i = 0; i < chaine.size(); i++) {
        cout << chaine.at(i) << endl;
    }
}

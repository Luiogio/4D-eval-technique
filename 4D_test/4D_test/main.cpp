// 4D_test.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit

#include <iostream>

int main()
{
    std::string chaine;
    int i;

    std::cout << "Bonjour !\n";
    std::cout << "Entrez la chaine de caracteres a examiner.\n";
    std::cin >> chaine;

    for (i = 0; chaine.size(); i++) {
        std::cout << chaine[i] << "\n";
    }
}

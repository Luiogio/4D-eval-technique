// 4D_test.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit

#include <iostream>

using namespace std;

int main()
{
    string chaine;
    string res = "true";
    int i, j;

    cout << "Bonjour !" << endl;
    cout << "Entrez la chaine de caracteres a examiner." << endl;
    cin >> chaine;

    // Vérification des accolades de début et fin
    if (chaine.at(0) != *"{" || chaine.at(chaine.size() - 1) != *"}")
        res = "false";
    else {

        for (i = 1; i < chaine.size(); i++) 
        {
            // Vérification si une string
            if (chaine.at(i) == *"\"")
            {
                //Lecture de la string tant qu'on ne détecte pas des guillemets ou fin de json
                j = i + 1;
                while (j < chaine.size() && (chaine.at(j) != *"\"" || chaine.at(j) != *"}"))
                {
                    cout << j << endl;
                    cout << chaine.at(j) << endl;
                    j++;
                }

                if (chaine.at(j-2) != *"\"")
                {
                    res = "false";
                    break;
                }

                i = j;
            }

            cout << "flag" << endl;
        }
    }

    cout << res << endl;

    return EXIT_SUCCESS;
}

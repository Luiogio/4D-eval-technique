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
    //chaine = "{\"test\": \"tes\"}";

    // Vérification des accolades de début et fin
    if (chaine.at(0) != *"{" || chaine.at(chaine.size() - 1) != *"}")
        res = "false";
    else {

        for (i = 1; i < chaine.size(); i++) 
        {
            if (chaine.at(i) == *"}")
                break;

            // Vérification conformité si la value est une string ou number
            cout << chaine.at(i) << endl;
            if (chaine.at(i) == *"\"")
            {
                //Lecture de la string tant qu'on ne détecte pas des guillemets ou fin de json
                j = i + 1;
                while (chaine.at(j) != *"\"" && chaine.at(j) != *"}")
                {
                    cout << j << endl;
                    cout << chaine.at(j) << endl;
                    j++;
                }

                if (chaine.at(j++) != *"\"" || chaine.at(j++) != *":")
                {
                    res = "false";
                    break;
                }

                //Vérification value
                //Cas d'une string
                if (chaine.at(j++) == *"\"")
                {
                    while (chaine.at(j) != *"\"" && chaine.at(j) != *"}")
                        j++;

                    if (chaine.at(j) != *"\"")
                    {
                        res = "false";
                        break;
                    }

                    j++;
                }
                //Cas d'un chiffre
                else if (chaine[j] > 47 && chaine[i] < 58)
                {
                    while (chaine[j] > 47 && chaine[i] < 58)
                        j++;
                }

                if (chaine.at(j) == *",") continue;

                i = ++j;
            }
            else 
            {
                res = "false";
                break;
            }

            cout << "flag" << endl;
        }
    }

    cout << res << endl;

    return EXIT_SUCCESS;
}

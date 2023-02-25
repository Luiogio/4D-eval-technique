// 4D_test.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit

#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    string chaine;
    string res = "true";
    int i, j;
    int retflag;

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
                    cout << "chaine: " << chaine.at(j) << endl;
                    j++;
                }

                if (chaine.at(j++) != *"\"" || chaine.at(j++) != *":")
                {
                    res = "false";
                    break;
                }

                //Vérification si tableau
                if (chaine.at(j) == *"[")
                {
                    j += 2;

                    int retflag;
                    ArrayAnalyse(chaine, j, res, retflag);
                    if (retflag == 2) break;
                }
                else
                {
                    //Vérification value
                    StringOrNumberAnalyse(chaine, j, res, retflag);
                    if (retflag == 2) break;
                }

                i = j;
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

void ArrayAnalyse(std::string& chaine, int& j, std::string& res, int& retflag)
{
    retflag = 1;
    while (chaine.at(j) != *"\"" && chaine.at(j) != *"}")
    {
        cout << j << endl;
        cout << "chaine: " << chaine.at(j) << endl;
        j++;
    }

    if (chaine.at(j++) != *"\"" || chaine.at(j++) != *":")
    {
        res = "false";
        { retflag = 2; return; };
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
            { retflag = 2; return; };
        }

        if (chaine.at(++j) != *"]")
        {
            res = "false";
            { retflag = 2; return; };
        }
    }
    //Cas d'un chiffre
    else if (chaine[j] > 47 && chaine[j] < 58)
    {
        while (chaine[j] > 47 && chaine[j] < 58)
            j++;

        if (chaine.at(++j) != *"]")
        {
            res = "false";
            { retflag = 2; return; };
        }
    }
}

void StringOrNumberAnalyse(std::string& chaine, int& j, std::string& res, int& retflag)
{
    retflag = 1;

    //Cas d'une string
    if (chaine.at(j++) == *"\"")
    {
        while (chaine.at(j) != *"\"" && chaine.at(j) != *"}")
            j++;

        if (chaine.at(j) != *"\"")
        {
            res = "false";
            { retflag = 2; return; };
        }

        j++;
    }
    //Cas d'un chiffre
    else if (chaine[j] > 47 && chaine[j] < 58)
    {
        while (chaine[j] > 47 && chaine[j] < 58)
            j++;
        j++;
    }
}

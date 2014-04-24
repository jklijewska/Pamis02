#ifndef PLIK_HPP
#define PLIK_HPP

#include <iostream>
#include <fstream>

#include "BST.hpp"
#include "hasz.hpp"
#include "tabAso.hpp"
using namespace std;
/*! \brief Read BST 
*
* Odpowiada za czyta z pliku danych do drzewa binarnego BST.
*/
bool Read(const char * name, BST * bst);
/*! \brief Read tablica haszujaca
*
* Odpowiada za czyta z pliku danych do tablicy haszujacej.
*/
bool Read(const char * name, THasz * hasz);
/*! \brief Read tablica asocjacyjna 
*
* Odpowiada za czyta z pliku danych do tablicy asocjacyjnej.
*/
bool Read(const char * name, Tab_Aso<string, int> * aso);


#endif

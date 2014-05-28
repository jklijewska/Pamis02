#ifndef PLIK_HPP
#define PLIK_HPP

#include <iostream>
#include <fstream>

#include "NWP.hpp"

using namespace std;
/*!
*	Czytanie z pliku dwoch lancuchow znakowych
*	param1 name - nazwa pliku z ktorego czyta
*	param2 *tab - wskaznik na obiekt klasy NWP
*/
bool Read(const char * name, NWP *tab);

#endif

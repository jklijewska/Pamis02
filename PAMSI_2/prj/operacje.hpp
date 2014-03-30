#ifndef OPERACJE_HPP
#define OPERACJE_HPP
#include "tablica.hpp"
/*! 
	* \file
	* \brief Definicja funkcji ZamienEle
	*
	*  Funkcja, ktora zamienia elementy.

*/
void ZamienEle(Tablica &T, int m1, int m2);
/*! 
	* \file
	* \brief Definicja funkcji OdwrocTab
	*
	*  Funkcja, ktora odwraca tablice.

*/
void OdwrocTab(Tablica &T);
/*! 
	* \file
	* \brief Definicja funkcji DodajEle
	*
	*  Funkcja, ktora dodaje element.

*/
void DodajEle(Tablica &T, double ele);
/*! 
	* \file
	* \brief Definicja funkcji DodajEle
	*
	*  Funkcja, ktora dodaje elementy.

*/
void DodajEle(Tablica &T1, Tablica &T2, double ele);
/**********************/


#endif

#ifndef PLIK_HPP
#define PLIK_HPP

#include <iostream>
#include <fstream>

#include "stos.hpp"
#include "kolejka.hpp"
using namespace std;
   /*! 
	* \file
	* \brief Definicja funkcji Read
	*
	* Funkcja odpowiedzialna za za czytanie Stosu.
*/  
bool Read(const char * name, Stos * sto);
 /*! 
	* \file
	* \brief Definicja funkcji Write
	*
	* Funkcja odpowiedzialna za zapisywanie do pliku Stosu
*/
void Write(const char * name, Stos * sto);    // Uwaga. Zapisuje do pliku w odwrotnej kolejnoœci ni¿ czyta³. Powód jest prosty. LIFO.
 /*! 
	* \file
	* \brief Definicja funkcji Read
	*
	* Funkcja odpowiedzialna za za czytanie Kolejki.
*/
bool Read(const char * name, Queue * que);
/*! 
	* \file
	* \brief Definicja funkcji Write
	*
	* Funkcja odpowiedzialna za zapisywanie do pliku Kolejki*/
void Write(const char * name, Queue * que);    // Uwaga. Zapisuje do pliku w odwrotnej kolejnoœci ni¿ czyta³. Powód jest prosty. LIFO.

#endif

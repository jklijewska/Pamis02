#ifndef ZEGAR_HPP
#define ZEGAR_HPP

#include <ctime>
#include <iostream>
using namespace std;
    /*! 
	* \brief Definicja klasy Tablica
	*
	* Klasa odpowiadaj¹ca za operacje wykonujace sie na tablicy takie jak:
	* zamienienie elementow, odwrocenie tablicy, dodanie elementu, dodanie elementow, operator + operator, operato ==
	* \param[in] clock_t start, koniec - zmienne przechowuja aktualny czas systemu
	* \param[in] czas - przechowuje roznice czasow koniec i start
*/  
class Zegar     
{
 private:
      clock_t start, koniec;
      double czas;
 
 public:
      void Start();
      void Koniec();
      double Wynik();
      };
 
#endif

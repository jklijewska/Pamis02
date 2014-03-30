#ifndef TABLICA_HPP
#define TABLICA_HPP
#include <vector>
#include <iostream>
using namespace std;
/*! 
	* \file
	* \brief Definicja klasy Tablica
	*
	* Klasa odpowiadaj¹ca za operacje wykonujace sie na tablicy takie jak:
	* zamienienie elementow, odwrocenie tablicy, dodanie elementu, dodanie elementow, operator + operator, operato ==
	* \param[in] tab - kontener dynamicznej tablicy jednowymiarowej o typie double 
*/
class Tablica
{
private:
      vector < double > tab;
public:
	  void Czytaj(char* plik);
	
      void DodajNaKoniec(double ele);
      void DodajNaPoczatek(double ele);
      double PobierzPierwszyEle();
      double PobierzOstatniEle();
      double PobierzRozmiar();
      //*********************************************//
      void ZamienEle(int pierwszy, int drugi);
      bool OdwrocTab();
      bool DodajNaMiejsce(double ele, int miejsce);
      double PobierzWskazanyEle(int miejsce);
      void WyswietlTab();
      bool UsunEle(int miejsce);
      //**//
      Tablica operator+ (Tablica & T2);
      Tablica operator= (Tablica & T2);
      Tablica operator== (Tablica & T2);
      };

#endif

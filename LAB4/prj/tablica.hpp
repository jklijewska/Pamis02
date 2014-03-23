#ifndef TABLICA_HPP
#define TABLICA_HPP
#include <vector>
#include <iostream>
using namespace std;
/*! 
	* \file
	* \brief Definicja klasy Tablica
	*
	* Klasa odpowiadajšca za operacje wykonujace sie na tablicy takie jak:
	* zamienienie elementow, odwrocenie tablicy, dodanie elementu, dodanie elementow, operator + operator, operato ==
	* Oraz sortowania wykonywane dla stosu, a mianowicie quicksort, mergesort oraz heapsort.
*/
class Tablica
{
private:
      vector < double > tab;
public:

      Tablica() { tab.reserve(0); }
      //void DodajNaKoniec(double ele);
      void Push(double ele);
      double Pop();
      double Pop_Back();
      //double PobierzOstatniEle();
      int Size();
      void Isempty();
      
      //*********************************************//
      //void ZamienEle(int pierwszy, int drugi);
      //bool OdwrocTab();
      //bool DodajNaMiejsce(double ele, int miejsce);
      //double PobierzWskazanyEle(int miejsce);
      void Show_Tab();
      //bool UsunEle(int miejsce);
      //**//
      Tablica operator+ (Tablica & T2);
      Tablica operator* (double M);
      Tablica operator= (Tablica & T2);
      Tablica operator== (Tablica & T2);
      
      friend void Quick_Sort( Tablica & T, int left, int right );
      friend void Heap_Sort(Tablica & T);
      friend void Merge(Tablica & T, int left, int cent, int right);
      };

#endif


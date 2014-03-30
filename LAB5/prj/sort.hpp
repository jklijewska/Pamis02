#ifndef SORT_HPP
#define SORT_HPP

#include "tablica.hpp"
 /*! 
	* \brief Definicja funkcji QuickSort .
	*
	*  Funkcja odpowiadajaca za szybkie sortowanie. Dziala na zasadzie dziel i zwyciezaj. 
	*  Dzieli ona na mniejsze czesci, nastêpnie je porownuje i zamienia.

*/ 
void Quick_Sort( Tablica & T, int left, int right );
/*! 
	* \brief Definicja funkcji HeapSort .
	*
	*  Funkcja odpowiadajaca za sortowanie przez kopcowanie. Po utworzeniu kopca usuwa siê jego maksymalny wierzcholek i wstawia
	*  w jego miejsce element z konca kopca. W zwolnione dzieki temu miejsce wstawia sie obiekt maksymalny.

*/
void Heap_Sort( Tablica & T );
/*! 
	* \brief Definicja funkcji MergeSort .
	*
	*  Dzieli tablice na mniejsze czêœci, a nastêpnie wywo³uje funkcje sortuj¹c¹ Merge

*/
void Merge_Sort( Tablica & T, int left, int right );
/*! 
	* \brief Definicja funkcji Merge .
	*
	*  Funkcja odpowiadajaca za sortowanie przez scalanie. 

*/
void Merge( Tablica & T, int left, int cent, int right );

#endif

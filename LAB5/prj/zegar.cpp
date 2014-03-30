#include "zegar.hpp"
/*! 
	* \brief Definicja metody Start
	*
	*  Metoda, ktora powoduje start zegara.

*/
void Zegar::Start()
{
    start = clock();
    }
    /*! 
	* \brief Definicja metody Koniec
	*
	*  Metoda, ktora powoduje stop zegara i oblicza czas.

*/
void Zegar::Koniec()
{
     koniec = clock();
     
     czas = (double)(koniec-start)/CLOCKS_PER_SEC;
     
     //cout << "Czas: " << czas << endl;
     
     }
     /*! 
	* \brief Definicja metody Wynik
	*
	*  Metoda, ktora wyswietla wynik.

*/
double Zegar::Wynik()
{
    return (double)czas;
    }


#ifndef NWP_HPP
#define NWP_HPP

#include <cstring>
#include <iostream>
using namespace std;
/*!
*	\brief Klasa NWP, zajmuje sie wszystkim co potrzebne do tego aby znalezc podciag
*
*	**Macierz - Tablica dwuwymiarowa
*	\param  - M, N - Rozmiary tablicy
*	\param *A - Wskaznik na ciag
*   \param *B - Wskaznik na ciag
*/
class NWP
{
	private:
		int **Macierz;
		int M, N;
		char *A, *B;
		
	public:
	/*! \brief Destruktor NWP*/
		~NWP();
		/*!
		*	\brief Metoda  StwórzMacierzo
		*
		*	Odpowiada za dynamiczne utworzenie macierzy dwuwymiarowej, zapisanie dlugosci ciagow do M i N, oraz przekopiowanie tych ciagow do *A i *B
		*	\param *C1 - Wskaznik do pierwszego ciagu
		*	\param*C2 - Wskaznik do drugiego ciagu
		*/
		void StworzMacierz(char *C1, char *C2);
		
		/*!
		*	\brief Metoda WyliczMacierz
		*
		*	Metoda odpowiada za wyliczenia macierzy.
		*/
		void WyliczMacierz();
		/*! 
		*	\brief Metoda OdtworzNWP
		*
		*	Metoda odtwarza NWP.
		*/
		void OdtworzNWP();
		/*!
		*	\brief Metoda Show
		*
		*	Metoda wyswietlaj¹ca.  
		*/
		void Show();
	
}; 

#endif

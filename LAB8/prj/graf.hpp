#ifndef GRAF_HPP
#define GRAF_HPP

#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>

using namespace std;
/*!
 * \brief Klasa reprezentuje graf nieskierowany
 *
 * Graf jest zaimplementowany na macierzy s�siedztwa
 */
class Graf {
private:

	int **Macierz;
	int Wierzcholki;
	int Krawedzie;

public:
	/*!
	*	\brief Wy�wietla macierz dwuwymiarow� i pokazuje zwi�zki pomi�dzy wierzcho�kami
	*
	*/
	void WyswietlGraf();
	/*!
	*	\brief Zapisuje ile kraw�dzi b�dzie zawiera� graf
	*
	*	\param K - Ilo�� kraw�dzi w grafie
	*/
	void IloscKrawedzi(int K);
	/*!
		 * \brief Tworzy macierz dwuwymiarow� o rozmiarze M
		 *
		 * M jest jednocze�nie ilo�ci� wierzcho�k�w
		 *
		 * \param M - Ilo�� wierzcho�k�w oraz rozmiar macierzy
		 */
	void StworzGraf(int M);
	/*!
		 * \brief ��czy dwa wierzcho�ki
		 *
		 * \param W1 - wierzcho�ek pocz�tkowy kraw�dzi
		 * \param W2 - wierzcho�ek ko�cowy kraw�dzi
		 *
		 */
	void DodajKrawedz(int W1, int W2, int C);
	/*!
		 * \brief Usuwa po��czenie pomi�dzy dwoma wierzcho�kami
		 *
		 * \param W1 - wierzcho�ek pocz�tkowy kraw�dzi
		 * \param W2 - wierzcho�ek ko�cowy kraw�dzi
		 */
	void UsunKrawedz(int W1, int W2);
	/*!
	*	/brief Sprawdza czy dwa wierzcho�ki s� ze sob� po��czone
	*
	*	/param W1 - wierzcho�ek pocz�tkowy kraw�dzi
	*	/param W2 - wierzcho�ek ko�cowy kraw�dzi
	*/
	bool CzyPolaczone(int W1, int W2);
	/*!
		 * \brief Sprawdza i wypisuje s�siedztwo wierzcho�ka
		 *
		 * \param W - wierzcho�ek kt�rego s�siedztwa szukamy
		 */
	void Sasiedztwo(int W);
	/*!
	*	/brief Algorytm przeszukania grafu w g��b
	*	
	*	Algorytm przeszukuje graf i wy�wietla �cie�ke kolejno odwiedzonych wierzcho�k�w
	*
	*	/param W - wierzcho�ek pocz�tkowy
	*/
	void DFS(int W);
	/*!
	*	/brief Algorytm przeszukania grafu w szerz
	*	
	*	Algorytm przeszukuje graf i wy�wietla �cie�ke kolejno odwiedzonych wierzcho�k�w
	*
	*	/param W - wierzcho�ek pocz�tkowy
	*/
	void BFS(int W);
};

#endif

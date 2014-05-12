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
 * Graf jest zaimplementowany na macierzy s¹siedztwa
 */
class Graf {
private:

	int **Macierz;
	int Wierzcholki;
	int Krawedzie;

public:
	/*!
	*	\brief Wyœwietla macierz dwuwymiarow¹ i pokazuje zwi¹zki pomiêdzy wierzcho³kami
	*
	*/
	void WyswietlGraf();
	/*!
	*	\brief Zapisuje ile krawêdzi bêdzie zawiera³ graf
	*
	*	\param K - Iloœæ krawêdzi w grafie
	*/
	void IloscKrawedzi(int K);
	/*!
		 * \brief Tworzy macierz dwuwymiarow¹ o rozmiarze M
		 *
		 * M jest jednoczeœnie iloœci¹ wierzcho³ków
		 *
		 * \param M - Iloœæ wierzcho³ków oraz rozmiar macierzy
		 */
	void StworzGraf(int M);
	/*!
		 * \brief £¹czy dwa wierzcho³ki
		 *
		 * \param W1 - wierzcho³ek pocz¹tkowy krawêdzi
		 * \param W2 - wierzcho³ek koñcowy krawêdzi
		 *
		 */
	void DodajKrawedz(int W1, int W2, int C);
	/*!
		 * \brief Usuwa po³¹czenie pomiêdzy dwoma wierzcho³kami
		 *
		 * \param W1 - wierzcho³ek pocz¹tkowy krawêdzi
		 * \param W2 - wierzcho³ek koñcowy krawêdzi
		 */
	void UsunKrawedz(int W1, int W2);
	/*!
	*	/brief Sprawdza czy dwa wierzcho³ki s¹ ze sob¹ po³¹czone
	*
	*	/param W1 - wierzcho³ek pocz¹tkowy krawêdzi
	*	/param W2 - wierzcho³ek koñcowy krawêdzi
	*/
	bool CzyPolaczone(int W1, int W2);
	/*!
		 * \brief Sprawdza i wypisuje s¹siedztwo wierzcho³ka
		 *
		 * \param W - wierzcho³ek którego s¹siedztwa szukamy
		 */
	void Sasiedztwo(int W);
	/*!
	*	/brief Algorytm przeszukania grafu w g³¹b
	*	
	*	Algorytm przeszukuje graf i wyœwietla œcie¿ke kolejno odwiedzonych wierzcho³ków
	*
	*	/param W - wierzcho³ek pocz¹tkowy
	*/
	void DFS(int W);
	/*!
	*	/brief Algorytm przeszukania grafu w szerz
	*	
	*	Algorytm przeszukuje graf i wyœwietla œcie¿ke kolejno odwiedzonych wierzcho³ków
	*
	*	/param W - wierzcho³ek pocz¹tkowy
	*/
	void BFS(int W);
};

#endif

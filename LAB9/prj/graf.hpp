#ifndef GRAF_HPP
#define GRAF_HPP

#include<list>

using namespace std;

/*!
*\brief Deklaracja klasy Graf.
*
* Klasa odpowiedzialna za dodawanie wierzcholkow, krawedzi itd.
*/

class Graf 
{
	private:
		int **Macierz;
		int rozm;

	public:
		Graf(int M);
	   ~Graf();
	   
		bool DodajWierzcholek(int W);
		bool DodajKrawedz(int W1, int W2, double C);
		bool UsunKrawedz(int W1, int W2);
		bool UsunWierzcholek(int W);
		double CzyPolaczone(int W1, int W2);
		list<int> Sasiedztwo(int W);
		const int Rozmiar() const;
		void BFS(int W);
		void DFS(int W);

};

#endif

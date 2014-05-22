#include <list>
#include <stack>
#include <iostream>
#include <queue>

#include "graf.hpp"

/*!
 *  \brief Konstruktor grafu.
 *
 */
Graf::Graf(int M)
{
	rozm = M;
	
	Macierz = new int*[M];
	for(int i = 0; i < M; i++)
		Macierz[i] = new int[M];

	for(int i = 0; i < M; i++)
		for(int j = 0; j < M; j++)
			Macierz[i][j]=0;
}
/*
 * \brief Destruktor grafu.
 *
 */
Graf::~Graf()
{
	for(int i = 0; i < rozm; i++)
			delete [] Macierz[i];  

	delete [] Macierz;
}
/*
 * \brief Metoda DodajWierzcholek.
 *
 * Metoda odpowiedzialna za dodawanie wierzcholka.
 */
bool Graf::DodajWierzcholek(int W)
{
	return true;
}
/*
 * \brief Metoda DodajKrawedz.
 *
 * Metoda odpowiedzialna za dodawanie krawedzi.
 */
bool Graf::DodajKrawedz(int W1, int W2, double C) 
{
	Macierz[W1][W2] = Macierz[W2][W1] = C;
	return true;
}
/*
 * \brief Metoda UsunKrawedzk.
 *
 * Metoda odpowiedzialna za usuwanie krawedzi.
 */
bool Graf::UsunKrawedz(int W1, int W2) 
{
	Macierz[W1][W2] = Macierz[W2][W1] = 0;
	return true;
}
/*
 * \brief Metoda UsunWierzholek.
 *
 * Metoda odpowiedzialna za usuwanie wierzcholka.
 */
bool Graf::UsunWierzcholek(int W) 
{
	return true;
}
/*
 * \brief Metoda CzyPolaczone.
 *
 * Metoda odpowiedzialna sprawdzanie, czy wierzcholki sa polaczone.
 */
double Graf::CzyPolaczone(int W1, int W2) 
{
	return Macierz[W1][W2];
}
/*
 * \brief Metoda Sasiedztwo.
 *
 * Metoda odpowiedzialna za sprawdzanie sasiedztwa.
 */
list<int> Graf::Sasiedztwo(int W) 
{
	list<int> ret;
	for(int i = 0; i<rozm; i++)
	if(CzyPolaczone(W, i)) ret.push_back(i);
	return ret;
}
/*
 * \brief Metoda Rozmiar.
 *
 * Metoda odpowiedzialna za podawanie rozmiaru grafu.
 */
const int Graf::Rozmiar() const 
{
	return rozm;
}
/*
 * \brief Metoda DFS.
 *
 * Metoda odpowiedzialna za wyszukiwanie DFS.
 */
void Graf::DFS(int W) 
{
	bool *odwiedzony = new bool[rozm];
		
	for(int i = 0; i < rozm; i++) 
		odwiedzony[i] = false;
			
	stack<int> stos;
	stos.push(W);
		
	cout << "DFS:  ";
		
	while(!stos.empty())
	{
		W = stos.top();  
		stos.pop();
			
		if(!odwiedzony[W])
    	{
   		 odwiedzony[W] = true;
          			
         for(int i = 0; i < rozm; i++) 
			if(Macierz[W][i] && !odwiedzony[i]) 
				stos.push(i);
				
         	cout << W << " ";
      	}
	} 
	cout << endl;
}
/*
 * \brief Metoda BFS.
 *
 * Metoda odpowiedzialna za wyszukiwanie BFS.
 */
void Graf::BFS(int W)
{
	bool *odwiedzony = new bool[rozm];
		
	for(int i = 0; i < rozm; i++) 
		odwiedzony[i] = false;
			
	queue<int> kolejka;
	kolejka.push(W);
		
	cout << "BFS:  ";
		
	while(!kolejka.empty())
	{
		W = kolejka.front(); 
		kolejka.pop();
			
		if(!odwiedzony[W])
     	{
          	odwiedzony[W] = true;
          			
          	for(int i = 0; i < rozm; i++) 
				if(Macierz[W][i] && !odwiedzony[i]) 
					kolejka.push(i);
          		
			cout << W << " ";
      	}
	} 
	cout << endl;
}

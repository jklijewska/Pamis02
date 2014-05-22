#include <iostream>
#include <list>
#include <algorithm>
#include <limits>
#include <set>

#include "search.hpp"

list<int> A_star(Graf& graf, int poczatek, int koniec) 
{
	int* odleglosc = new int[graf.Rozmiar()];
	fill(odleglosc, odleglosc+graf.Rozmiar(), numeric_limits<int>::max() );
	
	int* f = new int[graf.Rozmiar()];
	fill(f, f+graf.Rozmiar(), numeric_limits<int>::max() );
	
	int* odwiedzone = new int[graf.Rozmiar()]();
	
	int* rodzic = new int[graf.Rozmiar()+1]; 
	for(int i = 1; i < graf.Rozmiar()+1; ++i) 
		rodzic[i] = i;
	/*!
*\brief Deklaracja klasy heuristic.
*
*  Klasa heuristic s³u¿y znalezieniu jak najlepzego rozwiazania. Aby tego dokonac liczona jest odleglosc.
*/
	class heurestic 
	{
		public:
			int operator()(int n) { return 0; }
	} h;
	
	rodzic[poczatek] = -1;
	odwiedzone[poczatek] = 1;
	odleglosc[poczatek] = 0;
	f[poczatek] = h(poczatek);

	set<int> query;
	query.insert(poczatek);
	
	while(!query.empty() ) 
	{		
		int u = *query.begin();
		query.erase(query.begin());
		
		list<int> lista = graf.Sasiedztwo(u);
		for(list<int>::iterator it = lista.begin(); it != lista.end(); it++) 
		{
			if(graf.CzyPolaczone(u,*it) + odleglosc[u] < odleglosc[*it]) 
			{
				odleglosc[*it] = graf.CzyPolaczone(u,*it) + odleglosc[u];
				f[*it] = odleglosc[*it] + h(*it);
				rodzic[*it] = u;
				if(odwiedzone[*it] == 0) 
				{
					odwiedzone[*it] = 1;
					query.insert(*it);
				}
				else if( odwiedzone[*it] == 2 ) 
				{
					odwiedzone[*it] = 1;
					query.insert(*it);
				}
			} 
		}
		odwiedzone[u] = 2; 
	}

	list<int> ret;
	for(int i = koniec; i != -1; i = rodzic[i]) ret.push_front(i);
	
	return ret;
}

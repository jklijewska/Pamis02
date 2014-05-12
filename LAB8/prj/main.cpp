/*! 
   \mainpage Dokumentacja zadania PAMSI LAB 8
   \author Justyna Klijewska
   \date 12.05.2014
   \version 0.1

 */
#include "graf.hpp"

int main() 
{
	Graf graf;
	
	graf.StworzGraf(10);
	graf.IloscKrawedzi(15);
	
	graf.DodajKrawedz(0,1,1);
	graf.DodajKrawedz(0,2,1);
	graf.DodajKrawedz(0,3,1);
	graf.DodajKrawedz(1,3,1);
	graf.DodajKrawedz(2,3,1);
	graf.DodajKrawedz(2,4,1);
	graf.DodajKrawedz(3,5,1);
	graf.DodajKrawedz(4,6,1);
	graf.DodajKrawedz(2,8,1);
	graf.DodajKrawedz(3,9,1);
	graf.DodajKrawedz(8,9,1);
	graf.DodajKrawedz(2,6,1);
	graf.DodajKrawedz(7,5,1);
	graf.DodajKrawedz(4,9,1);
	graf.DodajKrawedz(9,1,1);
	
	graf.WyswietlGraf();
	graf.Sasiedztwo(5);
	graf.DFS(0);
	graf.BFS(0);

return 0;
}

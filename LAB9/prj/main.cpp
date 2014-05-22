/*! 
   \mainpage Dokumentacja zadania PAMSI LAB 9
   \author Justyna Klijewska
   \date 21.05.2014
   \version 0.1

 */
#include <iostream>

#include "graf.hpp"
#include "search.hpp"
#include "czas.hpp"

/*!
* \file
* \brief Plik zawiera glowna funkcje programu.
*/

int main() 
{
	Graf graf1(5);
	Graf graf2(6);
	Graf graf3(21);
	LARGE_INTEGER Start, End; double T;
	
	/*PIERWSZY GRAF*/
	graf1.DodajKrawedz(1, 2, 7);
	graf1.DodajKrawedz(1, 3, 8);
	graf1.DodajKrawedz(2, 3, 9);
	graf1.DodajKrawedz(3, 4, 10);
	/*DRUGI GRAF*/
	graf2.DodajKrawedz(1, 2, 10);
	graf2.DodajKrawedz(2, 3, 11);
	graf2.DodajKrawedz(3, 4, 12);
	graf2.DodajKrawedz(4, 5, 13);
	graf2.DodajKrawedz(3, 5, 14);
	/*DUZY GRAF*/
	graf3.DodajKrawedz(1, 16, 5);
	graf3.DodajKrawedz(1, 8, 4);
	graf3.DodajKrawedz(2, 16, 2);
	graf3.DodajKrawedz(2, 4, 5);
	graf3.DodajKrawedz(2, 3, 3);
	graf3.DodajKrawedz(4, 15, 6);
	graf3.DodajKrawedz(4, 5, 9);
	graf3.DodajKrawedz(5, 6, 10);
	graf3.DodajKrawedz(5, 7, 11);
	graf3.DodajKrawedz(5, 9, 12);
	graf3.DodajKrawedz(6, 13, 8);
	graf3.DodajKrawedz(7, 11, 13);
	graf3.DodajKrawedz(7, 19, 14);
	graf3.DodajKrawedz(8, 13, 24);
	graf3.DodajKrawedz(9, 10, 15);
	graf3.DodajKrawedz(9, 18, 23);
	graf3.DodajKrawedz(9, 14, 16);
	graf3.DodajKrawedz(11, 12, 22);
	graf3.DodajKrawedz(12, 18, 17);
	graf3.DodajKrawedz(12, 17, 21);
	graf3.DodajKrawedz(13, 15, 7);
	graf3.DodajKrawedz(13, 17, 20);
	graf3.DodajKrawedz(14, 20, 19);
	graf3.DodajKrawedz(18, 20, 18);
	/**********************PIERWSZY GRAF***************************/
	
	Start = startTimer();
	list<int> lista1 = A_star(graf1, 1, 4);
	End = endTimer();
	T = End.QuadPart - Start.QuadPart;
	
	for(list<int>::iterator it = lista1.begin(); it != lista1.end(); it++) cout << *it << ", ";
	cout << endl << "Czas wykonywania A*: " << T << "ns." << endl;
	
	cout << endl;
	
	Start = startTimer();
	graf1.DFS(1);
	End = endTimer();
	T = End.QuadPart - Start.QuadPart;
	
	cout << "Czas wykonywania DFS: " << T << "ns." << endl << endl;

	Start = startTimer();	
	graf1.BFS(1);
	End = endTimer();
	T = End.QuadPart - Start.QuadPart;
	
	cout << "Czas wykonywania BFS: " << T << "ns." << endl << endl;
	
	/**************************DRUGI GRAF*******************************/ cout << "/***************************************\\" << endl << endl;
	
	Start = startTimer();
	list<int> lista2 = A_star(graf2, 1, 5);
	End = endTimer();
	T = End.QuadPart - Start.QuadPart;
	
	for(list<int>::iterator it = lista2.begin(); it != lista2.end(); it++) cout << *it << ", ";
	cout << endl << "Czas wykonywania A*: " << T << "ns." << endl;
	
	cout << endl;
	
	Start = startTimer();
	graf2.DFS(1);
	End = endTimer();
	T = End.QuadPart - Start.QuadPart;
	
	cout << "Czas wykonywania DFS: " << T << "ns." << endl << endl;

	Start = startTimer();	
	graf2.BFS(1);
	End = endTimer();
	T = End.QuadPart - Start.QuadPart;
	
	cout << "Czas wykonywania BFS: " << T << "ns." << endl << endl;
	
	/**************************DUZY GRAF*******************************/ cout << "/***************************************\\" << endl << endl;
	
	Start = startTimer();
	list<int> lista3 = A_star(graf3, 1, 20);
	End = endTimer();
	T = End.QuadPart - Start.QuadPart;
	
	for(list<int>::iterator it = lista3.begin(); it != lista3.end(); it++) cout << *it << ", ";
	cout << endl << "Czas wykonywania A*: " << T << "ns." << endl;
	
	cout << endl;
	
	Start = startTimer();
	graf3.DFS(1);
	End = endTimer();
	T = End.QuadPart - Start.QuadPart;
	
	cout << "Czas wykonywania DFS: " << T << "ns." << endl << endl;

	Start = startTimer();	
	graf3.BFS(1);
	End = endTimer();
	T = End.QuadPart - Start.QuadPart;
	
	cout << "Czas wykonywania BFS: " << T << "ns." << endl;
	
	return 0;
}

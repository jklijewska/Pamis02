/*! 
   \mainpage Dokumentacja zadania PAMSI LAB 7
   \author Justyna Klijewska
   \date 21.04.2014
   \version 0.1

 */
#include <iostream>
#include "BST.hpp"
#include "hasz.hpp"
#include "plik.hpp"
#include "tabAso.hpp"
#include "zegar.hpp"

string gen_random(const int len) 
{
   	string s="";
   
   	static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
   
   	for (int i = 0; i < len; ++i) 
   	{
    	s += alphanum[rand() % (sizeof(alphanum) - 1)];
   	}
	
    return s;
}

int main()
{
	srand(time(NULL));
	Zegar zeg;	
	
	long int N;
	cout << "Rozmiar: ";
	cin >> N;
	cout << endl;
	
	string *tab = new string[N];
	for(long int j = 0; j < N; j++)
		tab[j] = gen_random(10);
	
	Tab_Aso<string, long int> * A_tab = new Tab_Aso<string, long int>;
	BST * tree = new BST;
	THasz * H_tab = new THasz(N);
	
	TabAsoEle<string, long int> * i = new TabAsoEle<string, long int>;
	Node * n = new Node;
	vector<string>::iterator it;
	
	/**********************************/
	cout << "TABLICA ASOCJACYJNA" << endl << endl;
	//Dla Tablicy Asocjacyjnej
	
	for(long int j = 0; j < N; j++)
		A_tab->AddKey(tab[j], rand());
		
	cout << "Wczytalem" << endl << endl;
	
	zeg.Start();
	
	i = A_tab->TakeKey(tab[rand()%N]);
	cout << "Klucz: " << i->key << ", Dane: " << i->dane << endl;
	
	zeg.Koniec();
	cout << "Czas szukania klucza: " << i->key << ", wynosi: " << zeg.Wynik();
	
	cout << endl << endl;
	
	zeg.Start();
	
	i = A_tab->TakeKey("Zuzi");
	cout << "Klucz: " << i->key << ", Dane: " << i->dane << endl;
	
	zeg.Koniec();
	cout << "Czas szukania nieistniejacego klucza: " << zeg.Wynik();
	
	/**********************************/
	cout << endl << endl;
	cout << "DRZEWO BINARNE" << endl << endl;
	//Dla Drzewa Binarnego
	
	for(long int j = 0; j < N; j++)
		tree->AddKey(rand()%N);
	
	cout << "Wczytalem" << endl << endl;
	
	zeg.Start();
	
	n = tree->TakeKey(2);
	cout << "Klucz: " << n->key << endl;		zeg.Koniec();
	cout << "Czas szukania klucza na poczatku drzewa: " << zeg.Wynik(); 
	
	cout << endl << endl;
	
	zeg.Start();
	
	n = tree->TakeKey(N-2);
	cout << "Klucz: " << n->key << endl;		zeg.Koniec();
	cout << "Czas szukania klucza na koncu drzewa: " << zeg.Wynik();
	
	cout << "SizE: " << tree->Size() << endl;
	/**********************************/
	cout << endl << endl;
	cout << "Hera, koka, Hasz Hasz Bejbe, LSD" << endl << endl;
	//Dla Tablicy Haszujacej
	
	for(long int j = 0; j < N; j++)
		H_tab->AddKey(tab[j]);
		
	cout << "Wczytalem" << endl << endl;
	
	zeg.Start();
	
	it = H_tab->TakeKey(tab[rand()%N]);
	cout << "Klucz: " << *it << endl;
	
	zeg.Koniec();
	cout << "Czas szukania klucza: " << *it << ", o haszu: " << H_tab->HF(*it) << ", wynosi: " << zeg.Wynik();
	
	cout << endl << endl;
	
	zeg.Start();
	
	it = H_tab->TakeKey("Adam");
	//cout << "Klucz: " << *it;

	zeg.Koniec();
	cout << "Czas szukania nieistniejacego klucza: " << zeg.Wynik();
	
	/**********************************/
	cout << endl << endl;
	
	cin.get();
	
	delete A_tab, tree, H_tab, i, n; 
	
	return 0;
}

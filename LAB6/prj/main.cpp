/*! 
   \mainpage Dokumentacja zadania PAMSI LAB 6
   \author Justyna Klijewska
   \date 4.06.2014
   \version 0.1

 */
#include <iostream>
#include <string>
#include "tabAso.hpp"
using namespace std;

int main()
{
	/*! \brief Main
	*
	* Przykladowe operacje na tablicy alokacyjnej. 
	* Wyswietlanie operacji.
	*/
	Tab_Aso<string, int> tab;
	TabAsoEle<string, int> *i, *o, *p;
	
	if(tab.IsEmpty()) cout << "Pusty" << endl; else cout << "Zawiera " << tab.Size() << " elementow" << endl;
	
	tab.AddKey("nine",1);
	
	if(tab.IsEmpty()) cout << "Pusty" << endl; else cout << "Zawiera " << tab.Size() << " elementow" << endl;
	
	tab.AddKey("eight", 2);
	
	if(tab.IsEmpty()) cout << "Pusty" << endl; else cout << "Zawiera " << tab.Size() << " elementow" << endl;
	
	tab.DeleteKey("nine");
	if(tab.IsEmpty()) cout << "Pusty" << endl; else cout << "Zawiera " << tab.Size() << " elementow" << endl;
	tab.DeleteKey("eight");
	if(tab.IsEmpty()) cout << "Pusty" << endl; else cout << "Zawiera " << tab.Size() << " elementow" << endl;
	
	tab.AddKey("nine", 9);
	tab.AddKey("eight", 8);
	tab.AddKey("seven", 7);
	cout << "nine: " << tab["nine"]->dane << endl;
	cout << "eight: " << tab["eight"]->dane << endl;
	cout << "seven: " << tab["seven"]->dane << endl;
	
	tab.Change("nine", 7);
	tab.Change("eight", 8);
	tab.Change("seven", 9);
	cout << "nine: " << tab["nine"]->dane << endl;
	cout << "eight: " << tab["eight"]->dane << endl;
	cout << "seven: " << tab["seven"]->dane << endl;
	
	i = tab.TakeKey("nine");
	o = tab.TakeKey("eight");
	p = tab.TakeKey("seven");
	i->dane = 9;
	o->dane = 8;
	p->dane = 7;
	cout << "nine: " << tab["nine"]->dane << endl;
	cout << "eight: " << tab["eight"]->dane << endl;
	cout << "seven: " << tab["seven"]->dane << endl;
	
	tab["nine"]->dane = 7;
	tab["eight"]->dane = 8;
	tab["seven"]->dane = 9;
	cout << "nine: " << tab["nine"]->dane << endl;
	cout << "eight: " << tab["eight"]->dane << endl;
	cout << "seven: " << tab["seven"]->dane << endl;
	
	cout << "1: " << " key: " << tab[1]->key << ", dane: " << tab[1]->dane << endl;
	cout << "2: " << " key: " << tab[2]->key << ", dane: " << tab[2]->dane << endl;
	cout << "3: " << " key: " << tab[3]->key << ", dane: " << tab[3]->dane << endl;
	
	cout << endl << endl;
	cout << "BLEDY" << endl;
	cout << endl << endl;
	
	tab.DeleteKey("six");
	tab.DeleteKey("eight");
	if(tab.IsEmpty()) cout << "Pusty" << endl; else cout << "Zawiera " << tab.Size() << " elementow" << endl;
	cout << "1: " << " key: " << tab[1]->key << ", dane: " << tab[1]->dane << endl;
	cout << "2: " << " key: " << tab[2]->key << ", dane: " << tab[2]->dane << endl;
	cout << "nine: " << tab["nine"]->dane << endl;
	cout << "eight: " << tab["eight"]->dane << endl;
	cout << "seven: " << tab["seven"]->dane << endl;
	
	cout << endl;
	
	tab.DeleteKey("seven");
	if(tab.IsEmpty()) cout << "Pusty" << endl; else cout << "Zawiera " << tab.Size() << " elementow" << endl;
	cout << "1: " << " key: " << tab[1]->key << ", dane: " << tab[1]->dane << endl;
	cout << "2: " << " key: " << tab[2]->key << ", dane: " << tab[2]->dane << endl;
	cout << "seven: " << tab["seven"]->dane << endl;
	cout << "nine: " << tab["nine"]->dane << endl;
	
	
	cout << endl;
	
	tab["nine"]->dane = 9;
	tab["seven"]->dane = 7;
	cout << "seven: " << tab["seven"]->dane << endl;
	cout << "nine: " << tab["nine"]->dane << endl;
	
	cin.get();
}

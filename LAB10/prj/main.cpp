/*! 
   \mainpage Dokumentacja zadania PAMSI LAB 10
   \author Justyna Klijewska
   \date 28.05.2014
   \version 0.1

 */
#include <iostream>
#include "plik.hpp"
#include "NWP.hpp"
using namespace std;

int main()
{
	NWP tab;
	
	Read("plik.txt", &tab);
	
	tab.WyliczMacierz();
	tab.Show();
	tab.OdtworzNWP();
	
	cin.get();
	
	return 0;
}

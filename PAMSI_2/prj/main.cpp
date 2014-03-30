/*! 
   \mainpage Dokumentacja zadania PAMSI LAB 2
   \author Justyna Klijewska
   \date 09.03.2014
   \version 0.1

 */

#include <iostream>
#include "tablica.hpp"
#include "operacje.hpp"
#include "zegar.hpp"
using namespace std;

int main()
{
    Tablica tab1, tab2;
    Zegar zeg;
       
    zeg.Start();
    char *plik1 = "plik1.txt";  //Plik z pierwszym zestawem liczb
	char *plik2 = "plik2.txt";  //Plik z drugim zestawem liczb
    
	tab1.Czytaj(plik1);
    tab2.Czytaj(plik2);
    
    /*for(int i = 0; i < 5; i++)
    {
            tab1.DodajNaKoniec(i*5);
            tab2.DodajNaPoczatek(i*5);
            }*/
    //*****************//
    cout << "Punkt 1." << endl;
    cout << "Tablica 1: " << endl;
    tab1.WyswietlTab();
    cout << endl << "Tablica 2: " << endl;
    tab2.WyswietlTab();
    ZamienEle(tab1, 2, 4);
    cout << endl << "Po zamianie miejscami 2 i 4 elementu pierwszej tablicy." << endl;
    tab1.WyswietlTab();
    cout << endl << endl << "Punkt 2." << endl;
    cout << "Tablica 1: " << endl;
    tab1.WyswietlTab();
    OdwrocTab(tab1);
    cout << endl << "Po odwroceniu tablicy." << endl;
    tab1.WyswietlTab();
    cout << endl << endl << "Punkt 3." << endl;
    cout << "Tablica 1: " << endl;
    tab1.WyswietlTab();
    DodajEle(tab1, 15);
    cout << endl << "Po dodaniu elementu 15 na koniec." << endl;
    tab1.WyswietlTab();
    cout << endl << endl << "Punkt 4." << endl;
    cout << "Tablica 1: " << endl;
    tab1.WyswietlTab();
    cout << "Tablica 2: " << endl;
    tab2.WyswietlTab();
    DodajEle(tab1, tab2, 25);
    cout << endl << "Po dodaniu do obu tablic na koniec elementu 25." << endl;
    cout << endl << "Tablica 1: " << endl;
    tab1.WyswietlTab();
    cout << endl << "Tablica 2: " << endl;
    tab2.WyswietlTab();
    cout << endl << endl << "Punkt 5." << endl;
    cout << "Tablica 1: " << endl;
    tab1.WyswietlTab();
    cout << "Tablica 2: " << endl;
    tab2.WyswietlTab();
    tab1+tab2;
    cout << endl << "Po dodaniu (dolaczeniu) tablicy 2 do 1." << endl;
    cout << "Tablica 1: " << endl;
    tab1.WyswietlTab();
    cout << endl << endl << "Punkt 6." << endl;
    cout << "Tablica 1: " << endl;
    tab1.WyswietlTab();
    cout << "Tablica 2: " << endl;
    tab2.WyswietlTab();
    tab1=tab2;
    cout << endl << "Po przypisaniu do tablicy 1 tablicy 2." << endl;
    cout << "Tablica 1: " << endl;
    tab1.WyswietlTab();
    cout << "Tablica 2: " << endl;
    tab2.WyswietlTab();
    cout << endl << endl << "Punkt 7." << endl;
    tab1==tab2;
    cout << endl;
    /*****************************/
    
    zeg.Koniec();
    zeg.Wynik();
    
    cin.get();
    
    return 0;
    }

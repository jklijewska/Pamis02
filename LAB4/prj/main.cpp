/*! 
   \mainpage Dokumentacja zadania PAMSI LAB 4
   \author Justyna Klijewska
   \date 23.03.2014
   \version 0.1

 */
#include <iostream>
#include "zegar.hpp"
#include "stos.hpp"
#include "kolejka.hpp"
#include "plik.hpp"
using namespace std;


int main()
{
    Stos sto1(1), sto2(1), sto3(1);    // 0 - lista, 1 - tablica
    Queue que1(1), que2(0);
    Zegar zeg1, zeg2, zeg3;    
    const char * plik1 = "plik1.txt";  // Plik odczytu 1
    const char * plik2 = "plik2.txt";  // Plik odczytu 2
    const char * plik3 = "plik3.txt";  // Plik zapisu 1
    const char * plik4 = "plik4.txt";  // Plik zapisu 2
    
    
    
    Read(plik1, &sto1);
    zeg1.Start();
    sto1.HS();
    zeg1.Koniec();
    zeg1.Wynik();
    
    Read(plik1, &sto2);
    zeg2.Start();
    sto2.MS();
    zeg2.Koniec();
    zeg2.Wynik();
    
    Read(plik1, &sto3);
    zeg3.Start();
    sto3.HS();
    zeg3.Koniec();
    zeg3.Wynik();
    
    cin.get();
    
    return 0;
    }


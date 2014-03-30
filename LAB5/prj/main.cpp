/*! 
   \mainpage Dokumentacja zadania PAMSI LAB 5
   \author Justyna Klijewska
   \date 30.03.2014
   \version 0.1

 */
#include <iostream>
#include "zegar.hpp"
#include "stos.hpp"
#include "kolejka.hpp"
#include "plik.hpp"
#include <cstdlib>
using namespace std;


int main()
{
	/*! \brief Main
 *
 *  Wykonywane s¹ g³ówne za³o¿enia programu. Wczytuje siê tu plik (którego zawartoœæ jest losowana za pomoc¹ rand). Mo¿liwe
 * jest zwiêkszenie iloœci wykonywania siê programu. Odpowiadzialny jest równie¿ za wyœwietlanie wyników.
 */
    Stos sto1(1), sto2(1), sto3(1);    // 0 - lista, 1 - tablica
    Queue que1(1), que2(0);
    Zegar zeg1, zeg2, zeg3;    
    const char * plik1 = "plik1.txt";  // Plik odczytu 1
    const char * plik2 = "plik2.txt";  // Plik odczytu 2
    const char * plik3 = "plik3.txt";  // Plik zapisu 1
    const char * plik4 = "plik4.txt";  // Plik zapisu 2
        
    int j, i;    
    
    fstream file;
    file.open("plik1.txt", ios::out);
    srand(time(NULL)); 
    file << 10000 << endl;
    for(i = 0; i < 10000; i++)
	{
		j = rand();
		file << j << endl;
	}   
	
	for(i = 0; i < 1; i++)
	{
	
	Read(plik1, &sto1);
	//sto1.QS();										// Dla pesymistycznego, pamiêtaæ aby w sortowaniu QS zmieniæ na malej¹cy
	//sto1.QS();										// Dla optymistycznego, pamiêtaæ aby w sortowaniu QS zmieniæ na rosn¹cy
    zeg1.Start();
	sto1.HS();
	zeg1.Koniec();
	cout << "Heap Sort, przebieg: " << i << ", wynik: " << zeg1.Wynik() << endl;
	//Write(plik2, &sto1);
	
	Read(plik1, &sto2);
    zeg2.Start();
	sto2.QS();
	zeg2.Koniec();
	cout << "Quick Sort, przebieg: " << i << ", wynik: " << zeg2.Wynik() << endl;
	zeg2.Wynik();
	//Write(plik2, &sto2);
	
	Read(plik1, &sto3);
	//sto1.QS();										// Dla pesymistycznego, pamiêtaæ aby w sortowaniu QS zmieniæ na malej¹cy
	//sto1.QS();										// Dla optymistycznego, pamiêtaæ aby w sortowaniu QS zmieniæ na rosn¹cy
    zeg3.Start();
	sto3.MS(); 
	zeg3.Koniec();
	cout << "Merge Sort, przebieg: " << i << ", wynik: " << zeg3.Wynik() << endl;
	//Write(plik2, &sto3);
	
	sto1.Clear();
	sto2.Clear();
	sto3.Clear();
	
	cout << endl;
	}
	
    cin.get();
    
    return 0;
    }


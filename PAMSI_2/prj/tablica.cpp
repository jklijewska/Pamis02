#include "tablica.hpp"
#include <fstream>
using namespace std;
/*! 
	* \file
	* \brief Definicja metody DodajNaKoniec
	*
	*  Metoda, ktora dodaje na koniec element.

*/
void Tablica::DodajNaKoniec(double ele)
{
     tab.push_back(ele);
     }
/*! 
	* \file
	* \brief Definicja metody DodajNaPoczatek
	*
	*  Metoda, ktora dodaje na poczatek element.

*/
void Tablica::DodajNaPoczatek(double ele)
{
     tab.insert(tab.begin(), ele);
     }
/*! 
	* \file
	* \brief Definicja metody PobierzPierwszyEle
	*
	*  Metoda, ktora pobiera pierwszy element.

*/
double Tablica::PobierzPierwszyEle()
{
       return *tab.begin();
       }
/*! 
	* \file
	* \brief Definicja metody PobierzOstatniEle
	*
	*  Metoda, ktora pobiera ostatni element.

*/
double Tablica::PobierzOstatniEle()
{
       return *tab.end();
       }
/*! 
	* \file
	* \brief Definicja metody PobierzRozmiar
	*
	*  Metoda, ktora pobiera pobiera rozmiar tablicy.

*/
double Tablica::PobierzRozmiar()
{
       return tab.size();
       }
       
//***********************************//
/*! 
	* \file
	* \brief Definicja metody zamien elementy
	*
	*  Metoda, ktora zamienia dwa wybrane elementy.

*/
void Tablica::ZamienEle(int pierwszy, int drugi)
{
     double l1, l2;
     bool resize;
     
     /*if(tab.size() < pierwszy || pierwszy < 1)
        if(tab.size() < drugi || drugi < 1)
           { cout << "Wskazane miejsca nie istnieja." << endl; return; }
        else
           { cout << "Miejsce " << pierwszy << " nie istnieje." << endl; return; }        
else if(tab.size() < drugi || drugi < 1)
           { cout << "Miejsce " << drugi << " nie istnieje." << endl; return; }
     */    
      
     l1 = *(tab.begin()+(pierwszy-1));
     l2 = *(tab.begin()+(drugi-1));
     
     tab.erase(tab.begin()+(pierwszy-1));
     tab.erase(tab.begin()+(drugi-2));

     tab.insert(tab.begin()+(pierwszy-1), l2);
     if(tab.size() < drugi) { tab.resize(tab.size()+1); resize = true; }
     tab.insert(tab.begin()+(drugi-1), l1);
     if(resize) tab.resize(tab.size()-1);

     }
   /*! 
	* \file
	* \brief Definicja metody OdwrocTab
	*
	*  Metoda, ktora odwraca tablice.

*/  
bool Tablica::OdwrocTab()
{
     if(!tab.size()) { cout << "Tablica jest pusta." << endl; return false; }
     if(tab.size() == 1) { cout << "Tablica zawiera jedynie jeden element. Dodaj kolejny aby moc ja obrocic." << endl; return false; }
     vector <double> tmp;
     vector <double>::iterator it_tab = tab.begin();
     
     for(; it_tab != tab.end(); it_tab++)
         tmp.insert(tmp.begin(), *it_tab);
     
     tab = tmp;
     
     return true;
     }
/*! 
	* \file
	* \brief Definicja metody DodajNaMiejsce
	*
	*  Metoda, ktora dodaje element na konretne miejsce.

*/
bool Tablica::DodajNaMiejsce(double ele, int miejsce)
{
     if(tab.size() < miejsce || miejsce < 1) { cout << "Podane miejsce nie istnieje. Wartosc nie zostala dodana do tablicy." << endl; return false; }
     tab.insert(tab.begin()+(miejsce-1), ele);
     return true;
     }
/*! 
	* \file
	* \brief Definicja metody PobierzWskazanyEle
	*
	*  Metoda, ktora pobiera wskazany element.

*/
double Tablica::PobierzWskazanyEle(int miejsce)
{
       if(tab.size() < miejsce || miejsce < 1) { cout << "Podane miejsce nie istnieje. Wartosc zwrotna -1" << endl; return -1;} 
       return *(tab.begin()+(miejsce-1));
       }
/*! 
	* \file
	* \brief Definicja metody WyswietlTab
	*
	*  Metoda, ktora wyswietla tabilce.

*/
void Tablica::WyswietlTab()
{
     if(!tab.size()) { cout << "Tablica jest pusta." << endl; return; }
          
     vector <double>::iterator it_tab = tab.begin();
     for(int i=1; it_tab != tab.end(); it_tab++)
         {  
           cout << i << ". " << *it_tab << endl;
           i++;
           }
     }
/*! 
	* \file
	* \brief Definicja metody UsunEle
	*
	*  Metoda, ktora dusuwa elementy.

*/
bool Tablica::UsunEle(int miejsce)
{
     if(tab.size() < miejsce || miejsce < 1) { cout << "Taki element nie istnieje." << endl; return false;}
     tab.erase(tab.begin()+(miejsce-1));
     return true;
     }
/*! 
	* \file
	* \brief Definicja przeladowania operatora + .
	*
	*  W celu lacznia dwoch tablic w jedna.

*/
Tablica Tablica::operator+ (Tablica & T2)
{
     vector <double>::iterator it_tab = T2.tab.begin();
     for(; it_tab != T2.tab.end(); it_tab++)
     {
           tab.insert(tab.end(), *it_tab);
           }
     }
/*! 
	* \file
	* \brief Definicja przeladowania operatora = .
	*
	*  W celu przypisania dwoch tablic.

*/
Tablica Tablica::operator= (Tablica & T2)
{
     tab = T2.tab;
     }
 /*! 
	* \file
	* \brief Definicja przeladowania operatora == .
	*
	*  W celu lacznia porownania tablic.

*/   
Tablica Tablica::operator== (Tablica & T2)
{
     bool roznica = false;   
        
     if(tab.size() != T2.tab.size())
                   cout << "Tablice maja rozne rozmiary." << endl;
     
     vector <double>::iterator it_tab = tab.begin();
     vector <double>::iterator it_tab2 = T2.tab.begin();
     
     if(tab.size() <= T2.tab.size())
     for(int i = 1; it_tab != tab.end(); it_tab++)
           {
                  if(*it_tab != *it_tab2)
                  {
                             cout << "Elementy na pozycji " << i << " roznia sie." << endl;
                             roznica = true;
                             }
                  it_tab2++;
                  i++;
                  }
     else
     for(int i = 1; it_tab2 != T2.tab.end(); it_tab2++)
           {
                  if(*it_tab != *it_tab2)
                  {
                             cout << "Elementy na pozycji " << i << " roznia sie." << endl;
                             roznica = true;
                             }
                  it_tab++;
                  i++;
                  }
     
     if(!roznica)
                 cout << "Tablice sa jednakowe." << endl;
     }
     
void Tablica::Czytaj(char* plik)
{
    int nic;
    double tmp;
    fstream txt;
    txt.open(plik); 
    
    txt>>nic;
    
    for(int i=0; !txt.eof(); i++)
        {
			txt >> tmp;
			tab.insert(tab.begin(), tmp);
			}
     }

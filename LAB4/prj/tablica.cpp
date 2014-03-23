#include "tablica.hpp"
using namespace std;
/*
void Tablica::DodajNaKoniec(double ele)
{
     tab.push_back(ele);
     }
*/  
 
        /*! 
	* \file
	* \brief Definicja konstruktora Push .
	*
	*  Metoda dodaje elementy. Przy uzyciu capacity metoda zwraca iloœæ zaalokowanej pamiêci wyra¿onej w liczbie znaków.

*/
void Tablica::Push(double ele)
{
     if(tab.size() == tab.capacity())             // W wersji zwiêkszaj¹cej o jeden wystarczy usun¹æ te dwie linie
                   tab.reserve((tab.size()*2));      // Kontener vector sam dba o relokacjê pamiêci i gdy jest to potrzebne zwiêksza rozmiar tablicy o 1
     cout << "Wkladam: " << ele << ", size: " << tab.size() << " , capa: " << tab.capacity() << endl;
     tab.insert(tab.begin(), ele);
     }
     
      /*! 
	* \file
	* \brief Definicja konstruktora Pop .
	*
	*  Metoda kopiuje wszystkie elementy z tab do tymczasowego. Nastpenie odbywa sie czyszczenie tab, wymiana odbiektow 
	* miedzy vectorami, a potem rezerwuje miejsce w vectorze na drukrotnosc jego elementow.

*/
double Tablica::Pop()
{
     vector <double> * tmp = new vector <double>;      
     double liczba = *tab.begin();
     
     tab.erase(tab.begin());   
     cout << "size: " << tab.size() << " , capa: " << tab.capacity() << endl;
     if(tab.size() <= tab.capacity()/4)                
        {                                              
                                                     
             *tmp = tab;                               
             tab.clear();                              
             tab.swap(*tmp);                            
             tab.reserve(tab.size()*2);                
             }                                        
        delete tmp;
        return liczba;
       }
      /*! 
	* \file
	* \brief Definicja konstruktora Pop_Back .
	*
	*  Metoda kopiuje wszystkie elementy z tab do tymczasowego. Nastpenie odbywa sie czyszczenie tab, wymiana odbiektow 
	* miedzy vectorami, a potem rezerwuje miejsce w vectorze na drukrotnosc jego elementow..

*/
double Tablica::Pop_Back()
{
     vector <double> * tmp = new vector <double>;      
     double liczba = *(tab.end()-1);                   

     tab.erase(tab.end()-1);                           

     cout << "size: " << tab.size() << " , capa: " << tab.capacity() << endl;
     if(tab.size() <= tab.capacity()/4)                
        {                                              
                                                    
             *tmp = tab;                            
             tab.clear();                          
             tab.swap(*tmp);                       
             tab.reserve(tab.size()*2);            
             }                                       
             
        delete tmp;
        return liczba;
       }
    /*! 
	* \file
	* \brief Definicja konstruktora Size .
	*
	*  W celu sprawdzania rozmiaru tablicy.

*/   
int Tablica::Size()
{
        //cout << "Rozmiar: " << tab.size() << ", Capacity: " << tab.capacity() << endl;
       return tab.size();
       }
/*! 
	* \file
	* \brief Definicja konstruktora Isempty .
	*
	*  W celu sprawdzania czy tablica jest pusta.

*/
void Tablica::Isempty()
{
       if(!tab.size()) cout << "Stos jest pusty." << endl;
       else cout << "Stos zawiera " << tab.size() << " elementow." << endl;
       }
//***********************************//
/*
void Tablica::ZamienEle(int pierwszy, int drugi)
{
     double l1, l2;
     bool resize;
     
     if(tab.size() < pierwszy || pierwszy < 1)
        if(tab.size() < drugi || drugi < 1)
           { cout << "Wskazane miejsca nie istnieja." << endl; return; }
        else
           { cout << "Miejsce " << pierwszy << " nie istnieje." << endl; return; }        
else if(tab.size() < drugi || drugi < 1)
           { cout << "Miejsce " << drugi << " nie istnieje." << endl; return; }
        
      
     l1 = *(tab.begin()+(pierwszy-1));
     l2 = *(tab.begin()+(drugi-1));
     
     tab.erase(tab.begin()+(pierwszy-1));
     tab.erase(tab.begin()+(drugi-2));

     tab.insert(tab.begin()+(pierwszy-1), l2);
     if(tab.size() < drugi) { tab.resize(tab.size()+1); resize = true; }
     tab.insert(tab.begin()+(drugi-1), l1);
     if(resize) tab.resize(tab.size()-1);

     }
     
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
     
bool Tablica::DodajNaMiejsce(double ele, int miejsce)
{
     if(tab.size() < miejsce || miejsce < 1) { cout << "Podane miejsce nie istnieje. Wartosc nie zostala dodana do tablicy." << endl; return false; }
     tab.insert(tab.begin()+(miejsce-1), ele);
     return true;
     }
     
double Tablica::PobierzWskazanyEle(int miejsce)
{
       if(tab.size() < miejsce || miejsce < 1) { cout << "Podane miejsce nie istnieje. Wartosc zwrotna -1" << endl; return -1;} 
       return *(tab.begin()+(miejsce-1));
       }
*/     
/*! 
	* \file
	* \brief Definicja konstruktora Show_Tab .
	*
	*  Pokazuje tablice.

*/      
void Tablica::Show_Tab()
{
     if(!tab.size()) { cout << "Tablica jest pusta." << endl; return; }
          
     vector <double>::iterator it_tab = tab.begin();
     for(int i=1; it_tab != tab.end(); it_tab++)
         {  
           cout << i << ". " << *it_tab << endl;
           i++;
           }
     }
/*
bool Tablica::UsunEle(int miejsce)
{
     if(tab.size() < miejsce || miejsce < 1) { cout << "Taki element nie istnieje." << endl; return false;}
     tab.erase(tab.begin()+(miejsce-1));
     return true;
     }
*/

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
 /*! 
	* \file
	* \brief Definicja przeladowania operatora * .
	*
	*  W celu mnozenia tablic.

*/   
Tablica Tablica::operator* (double M)
{
        vector <double>::iterator it_tab = tab.begin();

        while(it_tab != tab.end())
        {
                     *it_tab = *it_tab * M;
                     it_tab++;
                     }
        }


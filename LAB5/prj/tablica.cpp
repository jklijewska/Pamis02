#include "tablica.hpp"
using namespace std;

  /*! 
	* \brief Definicja konstruktora Push .
	*
	*  Metoda dodaje na pocz¹tek elementy. Przy uzyciu capacity metoda 
	*  zwraca iloœæ zaalokowanej pamiêci na podstawie której metoda push decyduje czy podwoiæ jej wartoœæ.

*/
void Tablica::Push(double ele)
{
     if(tab.size() == tab.capacity())             
                   tab.reserve((tab.size()*2));     
     tab.insert(tab.begin(), ele);
     }

     
      /*! 
	* \brief Definicja metody Pop .
	*
	*  Metoda usuwa pocz¹tkowy element tablicy
	* nastêpnie sprawdza czy iloœc elementów jest mniejsza lub równa niŸ 1/4 zaalokowanej pamiêci, jezeli tak jest
	* to kopiuje wszystkie elementy z tab do tymczasowego. Nastpenie odbywa sie czyszczenie tab, wymiana odbiektow 
	* miedzy vectorami, a potem rezerwuje miejsce w vectorze na drukrotnosc jego elementow.

*/
double Tablica::Pop()
{
     vector <double> * tmp = new vector <double>;      // Tymczasowy pojemnik na dane z tab
     double liczba = *tab.begin();
     
     tab.erase(tab.begin());   
    
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
	* \brief Definicja metody Pop_Back .
	*
	*  Dzia³a podobnie jak Pop tylko usuwa ostatni element a nastêpnie kopiuje wszystkie elementy z tab do tymczasowego. Nastpenie odbywa sie czyszczenie tab, wymiana odbiektow 
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
	* \brief Definicja metoda Size .
	*
	*  W celu sprawdzania rozmiaru tablicy.

*/   
int Tablica::Size()
{
       return tab.size();
       }
/*! 
	* \file
	* \brief Definicja metoda Isempty .
	*
	*  W celu sprawdzania czy tablica jest pusta.

*/
void Tablica::Isempty()
{
       if(!tab.size()) cout << "Stos jest pusty." << endl;
       else cout << "Stos zawiera " << tab.size() << " elementow." << endl;
       }
   
   /*! 
	* \brief Definicja metody Clear .
	*
	*  W celu sprawdzania czy tablica jest pusta.

*/    
void Tablica::Clear()
{
	tab.clear();
}
/*! 
	* \brief Definicja metody Show_Tab .
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
/*! 
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
	*  W celu porownywania tablic.

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
	*  W celu mnozenia tablicy przez liczbê.

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


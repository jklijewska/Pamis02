#ifndef TABASO_HPP
#define TABASO_HPP

#include <string>
#include "zegar.hpp"
using namespace std;

/*! \brief Szablon struktury element�w tablicy asocjacyjnej.
*
* key - Klucz 
* dane - Dane
* isend - Warto�� logiczna, przyjmuje true tylko w przypadku gdy jest to ostatni element tablicy. Element ten jest dodawany przy utworzeniu obiektu klasy Tab_Aso i reprezentuje stra�nika ustawionego na ko�cu.
*/
template<class T_K, class T_D>
struct TabAsoEle
{
       TabAsoEle<T_K, T_D> *next; 
	   T_K key;  
       T_D dane;   
       
       bool isend;
       
       TabAsoEle<T_K, T_D>(T_K inkey, T_D indane){ T_K key = inkey; T_D dane = indane; }
       TabAsoEle<T_K, T_D>(){ };
       
       };

/*! \brief Szablon klasy obs�uguj�cy tablice asocjacyjn� opart� na li�cie jednokierunkowej gdzie elementem listy jest struktura TabAsoEle
 *
 * T_K - Typ danych klucza
 * T_D - Typ danych warto�ci
 */
template<class T_K, class T_D>
class Tab_Aso
{
	private:
		TabAsoEle<T_K, T_D> * front, * back;   // Wska�niki na pierwszy i ostatni element listy
		TabAsoEle<T_K, T_D> * end;
        unsigned counter;          // Zawiera ile element�w ma lista
		
	public:
		Tab_Aso();
       ~Tab_Aso();
		
		
		void AddKey(T_K inkey, T_D indane);
		void DeleteKey(T_K inkey);
		TabAsoEle<T_K, T_D> * TakeKey(T_K inkey);		
		bool IsEmpty();
		void Change(T_K inkey, T_D indane);
		int Size();
		
		TabAsoEle<T_K, T_D> * operator [] (T_K inkey);
		TabAsoEle<T_K, T_D> * operator [] (int index);
		
		
};

/*! \brief Kontruktor klasy Tab_Aso
 *
 *Przy tworzeniu nowego obiektu tej klasy dodaje stra�nika kt�ry nie wskazuje na nic, natomiast koniec i pocz�tek listy wskazuje na stra�nika.
*/
template<class T_K, class T_D>
Tab_Aso<T_K, T_D>::Tab_Aso()
{
			  TabAsoEle<T_K, T_D> * i = new TabAsoEle<T_K, T_D>;
			  
			  i -> next = NULL; 
        	  i -> isend = true;
			  	
              front = back = i;
              end = i;
              counter = 0; 
              }
       
/*! \brief Destruktor klasy Tab_Aso   
*/    
template<class T_K, class T_D>           
Tab_Aso<T_K, T_D>::~Tab_Aso()
{ 
               TabAsoEle<T_K, T_D> * i; 
               while(front)
               {
                  i = front -> next;
                  delete front;
                  front = i;        
                  }
               }

/*! \brief Metoda AddKey, dodaje par�, klucz - warto�� do tablicy
*
* key - klucz
* dane - warto��
*/
template<class T_K, class T_D>
void Tab_Aso<T_K, T_D>::AddKey(T_K inkey, T_D indane)
{
        TabAsoEle<T_K, T_D> * i = new TabAsoEle<T_K, T_D>;
        
        i -> next = front; 
        i -> dane = indane;
        i -> key = inkey;
        i -> isend = false;
        
        front = i;
        
        if(!back) back = front;
        
        counter++;
        }

/*! \brief Metoda DeleteKey, usuwa par�, klucz - warto��.
*
* key - klucz*/
 
template<class T_K, class T_D>
void Tab_Aso<T_K, T_D>::DeleteKey(T_K inkey)
{
        TabAsoEle<T_K, T_D> * i, *b;
      
        if(front->isend) cout << "Tablica jest pusta." << endl;
        else
        {
         i = front;
         while(i->key != inkey)
         {
          b = i;	
          i = i -> next;
          if(i->isend){ cout << "Podany klucz nie istnieje." << endl; return; }
         }
         
         if(i == front)
         {
         	front = i -> next;
         	delete i;
    	 }
         else
         {
         	b -> next = i -> next;
         	delete i;
     	 }
        }
        counter--;
}

/*! \brief Metoda TakeKey, zwraca wska�nik na par� klucz - warto��.
*
* key - klucz
* Zwraca par� klucz - warto�� je�eli podany klucz istnieje
* Je�eli tablica jest pusta, lub klucz nie istnieje, zwraca wska�nik na stra�nika.
*/
template<class T_K, class T_D>
TabAsoEle<T_K, T_D> * Tab_Aso<T_K, T_D>::TakeKey(T_K inkey)
{
	
	TabAsoEle<T_K, T_D> * i; 
    
    if(front->isend) cout << "Tablica jest pusta." << endl;
    else
    {
        i = front;
        
        while(i->key != inkey)
        {	
         i = i -> next;
         if(i->isend)
		 { 
		  cout << "Klucz " << inkey << " nie istnieje." << endl; 
		  return i;
		 }
        }
        
		return i;
    }
}

      /*! 
	* \file
	* \brief Definicja metody Isempty
	*
	* Sprawdza czy lista jest pusta
*/
template<class T_K, class T_D>
bool Tab_Aso<T_K, T_D>::IsEmpty()
{
     if(counter == 0) return true;
     else return false;
     }   

/*! \brief Metoda Change 
*
* zmienia warto�� dane na indane w podanym kluczu inkey
*/
template<class T_K, class T_D>
void Tab_Aso<T_K, T_D>::Change(T_K inkey, T_D indane)
{
	TabAsoEle<T_K, T_D> * i = TakeKey(inkey);
	
	if(i->isend){ return; }
	
	i->dane = indane;
}

/*! \brief Metoda Size, 
*
* zwraca ilo�� element�w w tablicy.
*/
template<class T_K, class T_D>
int Tab_Aso<T_K, T_D>::Size()
{
	return counter;
}

/*! \brief Przeci��enie operatora []
*
*  Wyszukuje element po warto�ci inkey i zwraca jego wska�nik je�eli istnieje.
* Je�eli taki element nie istnieje, zwraca wska�nik na stra�nika. */
template<class T_K, class T_D>
TabAsoEle<T_K, T_D> * Tab_Aso<T_K, T_D>::operator [] (T_K inkey)
{
	TabAsoEle<T_K, T_D> * i = TakeKey(inkey);
	
	return i;
}

/*! \brief Przeci��enie operatora []
*
* Zwraca wska�nik na element pod podanym indeksem index.
*W przypadku gdy tablica jest pusta, lub index przekracza ilo�� element�w w tablicy, zwraca wska�nik na stra�nika. */
template<class T_K, class T_D>
TabAsoEle<T_K, T_D> * Tab_Aso<T_K, T_D>::operator [] (int index)
{
	TabAsoEle<T_K, T_D> * i;
	int x = 1;
	
	if(front->isend) cout << "Tablica jest pusta." << endl;
	else if(index > counter) cout << "Index poza zakresem tablicy." << endl;
    else
    {
        i = front;
        
        while(x != index)
        {	
         i = i -> next;
         x++;
        }
        
		return i;
    }
    
    return end;
}
#endif

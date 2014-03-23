#ifndef KOLEJKA_HPP
#define KOLEJKA_HPP

#include "tablica.hpp"
#include "lista.hpp"
   /*! 
	* \file
	* \brief Definicja klasy Queue
	*
	* Klasa odpowiadaj¹ca za metody wykonywane na tablicy takie jak:
		Enqueue, Dequeue, Isempty, Size, Show, operatory: == *
*/  
class Queue
{
private:
        
      Tablica tab;
      List lista;
      TYP T;
      
public:
      Queue(int typ) { if(typ == 0){T = list;} else {T = stack;} }
      
      void Enqueue(double ele) { if(T == list){ lista.Push_Front(ele); } else { tab.Push(ele); } }
      double Dequeue() { if(T == list){ return lista.Pop_Back(); } else { return tab.Pop_Back(); } }
      void Isempty() { if(T == list){ lista.Isempty(); } else { tab.Isempty(); } }
      int Size() { if(T == list){ return lista.Size(); } else { return tab.Size(); } } 
      
      void QS() { if(T == list){  } else { Quick_Sort(tab, 0, (tab.Size()-1)); } }
      void HS() { if(T == list){  } else { Heap_Sort(tab); } }
      void MS() { if(T == list){  } else { Merge_Sort(tab, 0, tab.Size()-1); } }
      
      void Show() { if(T == list){ lista.Show_List(); } else { tab.Show_Tab(); } }
      Queue & operator == (Queue & que){ if(T == list){ lista == que.lista; } else { tab == que.tab; } }
      Queue & operator * (double M){ if(T == list){ lista*M; } else { tab*M; } }
      };

#endif

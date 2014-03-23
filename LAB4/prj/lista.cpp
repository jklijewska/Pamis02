#include "lista.hpp"
using namespace std;
  /*! 
	* \file
	* \brief Definicja konstruktora List
	*
	* Prztwarza obiekt do znaczniku front i back, przypisuje NULL i liczy ile el. ma lisya
*/  
List::List()
{
              front = back = NULL;
              counter = 0; 
              }

    /*! 
	* \file
	* \brief Definicja destruktora List
	*
	* Usuwa wszystkie elementy*/
List::~List()
{ 
               ListEle * i; 
               while(front)
               {
                  i = front -> next;
                  delete front;
                  front = i;        
                  }
               }
      /*! 
	* \file
	* \brief Definicja konstruktora Isempty
	*
	* Sprawdza czy lista jest pusta
*/
void List::Isempty()
{
     if(counter == 0) cout << "Stos jest pusty." << endl;
     else cout << "Stos zawiera " << counter << " elementow." << endl;
     }     
       /*! 
	* \file
	* \brief Definicja konstruktora Size
	*
	* Rozmiar listy
*/        
int List::Size()
{
         return counter;
         }
        
 /*! 
	* \file
	* \brief Definicja konstruktora Push_Front
	*
	* Dodawanie na poczatek
*/
void List::Push_Front(double number)
{
        ListEle * i = new ListEle;
        
        i -> next = front; 
        i -> dane = number;

        front = i;
        
        if(!back) back = front;
        
        counter++;
        }
        

 /*! 
	* \file
	* \brief Definicja konstruktora Pop_Front
	*
	* Jest to dla stosu. Dodaje na poczatek.
*/
double List::Pop_Front()
{
        ListEle * i;
      
        if(front)
        {
         i = front;
         front = front -> next;
        
         if(!front) back = NULL;
        
         counter--;
         return i->dane;
         } 
      }

  /*! 
	* \file
	* \brief Definicja konstruktora Pop_Back
	*
	* Jest to dla kolejki. Dodaje na koniec.
*/
double List::Pop_Back()
{
        ListEle * i;
      
        if(back)
        {
         i = back;
         if(i == front) front = back = NULL;
         else
         {
             back = front;
             while(back -> next != i) back = back -> next;
             back->next = NULL;
             }
        counter--;
        
        return i->dane;
        }
      } 
  /*! 
	* \file
	* \brief Definicja konstruktora Show_List
	*
	* Pokazuje liste.
*/
void List::Show_List()
{
        ListEle * i;
      
        if(!front) cout << "Lista jest pusta." << endl;
        else
        {
         i = front;
         while(i)
         {
          cout << i -> dane << endl;
          i = i -> next;
          }
        cout << endl;
         }
     }

 /*! 
	* \file
	* \brief Przeciazenie operatora ==
	*
	* sprawdzanie czy nie sa puste, jezeli nie to:
	* 1- 1>2 wykonywany 1 if
	* 2>1 drugi if 
	* else kiedy takie same
*/
List & List::operator == (List & lista)
{
     ListEle * i1;
     ListEle * i2;
     int place = 1;
     bool roznica = false;
     
     if(!front) cout << "Lista pierwsza jest pusta." << endl;
     if(!lista.front) cout << "Lista druga jest pusta." << endl;
     if(!(front == lista.front))
     {
         i1 = front;
         i2 = lista.front;
         
         if(Size() > lista.Size())
         {
                   cout << "Lista pierwsza ma wiekszy rozmiar od drugiej." << endl;
                   
                   while(i2)
                   {
                            if(i1->dane != i2->dane)
                            {            
                                        cout << "Elementy na pozycji " << place << " roznia sie." << endl;
                                        roznica = true;
                                        }
                            i1 = i1 -> next;
                            i2 = i2 -> next;
                            place++;
                            }                   
                   }
         else if(lista.Size() > Size())
         {
                   cout << "Lista druga ma wiekszy rozmiar od pierwszej." << endl;
                   
                   while(i1)
                   {
                            if(i1->dane != i2->dane)
                            {
                                        cout << "Elementy na pozycji " << place << " roznia sie." << endl;
                                        roznica = true;
                                        }
                            i1 = i1 -> next;
                            i2 = i2 -> next;
                            place++;
                            }
                   }
         
         else
         {
                   while(i1)
                   {
                            if(i1->dane != i2->dane)
                            {
                                        cout << "Elementy na pozycji " << place << " roznia sie." << endl;
                                        roznica = true;
                                        }
                            i1 = i1 -> next;
                            i2 = i2 -> next;
                            place++;
                            }
             }
             }
         if(!roznica) cout << "Listy sa takie same." << endl;
     }
 /*! 
	* \file
	* \brief Przeciazenie operatora*
	*
	* Przeciazenie operatora*
*/
List & List::operator* (double M)
{
     ListEle * i;
     
     if(!front) cout << "Lista jest pusta." << endl;
     else
     {
         i = front;
         while(i)
         {
                 i->dane = i->dane * M;
                 i = i->next;
                 }
         }
     }

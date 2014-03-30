#include "plik.hpp"
  /*! 
	* \brief Definicja funkcji Read
	*
	* Funkcja odpowiedzialna za czytanie z  pliku i wk³adanie elementu do stosu.
*/ 
bool Read(const char * name, Stos * sto)
{
     fstream file;
     double tmp;
     int ile;
     
     file.open(name);
     if(!file.good())
         return false;
         
     file >> ile;    
         
     while(ile > 0)
     {
         file >> tmp;
         sto->Push(tmp);    
         ile--;          
         }
     
     file.close();
     return true;
     }
/*! 
	* \brief Definicja funkcji Write
	*
	* Funkcja odpowiedzialna za zapisywanie do pliku elementów stosu.
*/
bool Write(const char * name, Stos * sto)   
{
     fstream file(name, ios::out);
     file << sto->Size() << endl;
     while(sto->Size())
         file << sto->Pop()<< endl; 
     
     file.close();
     return true;
     }
 /*! 
	* \file
	* \brief Definicja funkcji Read
	*
	* Funkcja odpowiedzialna za czytanie z plikuKolejki.
*/
bool Read(const char * name, Queue * que)
{
     fstream file;
     double tmp;
     int ile;
     
     file.open(name);
     if(!file.good())
         return false;
         
     file >> ile;     
         
     while(ile > 0)
     {
         file >> tmp;
         que->Enqueue(tmp);    
         ile--;          
         }
     
     file.close();
     return true;
     }
     /*! 
	* \file
	* \brief Definicja funkcji Write
	*
	* Funkcja odpowiedzialna za zapisywanie do pliku i wk³adanie elementów do Kolejki*/
bool Write(const char * name, Queue * que)   
{
     fstream file(name, ios::out);
     
     file << que->Size() << endl;
     
     while(que->Size())
         file << que->Dequeue() << endl;
     
     file.close();
     return true;
     }

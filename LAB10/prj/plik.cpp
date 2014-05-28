#include "plik.hpp"

bool Read(const char *name, NWP *tab)
{
     fstream file;
     char *tmp1 = new char;
     char *tmp2 = new char;
     
     file.open(name);
     if(!file.good())
         return false;  
         
	 file >> tmp1; 
     file >> tmp2; 
    
     tab->StworzMacierz(tmp1, tmp2);
     
     file.close();

     delete tmp1, tmp2;
     
     return true;
     }

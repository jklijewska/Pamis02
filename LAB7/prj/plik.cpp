#include "plik.hpp"

bool Read(const char * name, BST * bst)
{
     fstream file;
     int tmp;
     int ile;
     
     file.open(name);
     if(!file.good())
         return false;
         
     file >> ile;    
         
     while(ile > 0)
     {
         file >> tmp;
         bst->AddKey(tmp);    
         ile--;          
         }
     
     file.close();
     }
     
bool Read(const char * name, THasz * hasz)
{
     fstream file;
     string tmp;
     int ile;
     
     file.open(name);
     if(!file.good())
         return false;
         
     file >> ile;    
         
     while(ile > 0)
     {
         file >> tmp;
         hasz->AddKey(tmp);    
         ile--;          
         }
     
     file.close();
     }
     
bool Read(const char * name, Tab_Aso<string, int> * aso)
{
     fstream file;
     string tmp1;
     int tmp2;
     int ile;
     
     file.open(name);
     if(!file.good())
         return false;
         
     file >> ile;    
         
     while(ile > 0)
     {
         file >> tmp1;
         file >> tmp2;
         aso->AddKey(tmp1, tmp2);    
         ile--;          
         }
     
     file.close();
     }

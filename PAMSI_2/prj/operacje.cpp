#include "operacje.hpp"
using namespace std;

void ZamienEle(Tablica &T, int m1, int m2)
{
     T.ZamienEle(m1, m2);
     }
     
void OdwrocTab(Tablica &T)
{
     T.OdwrocTab();
     }
     
void DodajEle(Tablica &T, double ele)
{
     T.DodajNaKoniec(ele);
     }


void DodajEle(Tablica &T1, Tablica &T2, double ele)
{
     T1.DodajNaKoniec(ele);
     T2.DodajNaKoniec(ele);
     }

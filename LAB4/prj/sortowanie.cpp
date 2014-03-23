 #define N 10
using namespace std;

int tab[N] = {1, 2, 3, 4, 5, 10, 8, 9, 6};
int t[N];  // Tablica pomocnicza
 
/* Scalanie dwoch posortowanych ciagow
tab[pocz...sr] i tab[sr+1...kon] i
wynik zapisuje w tab[pocz...kon] */
void merge(int pocz, int sr, int kon)
{
int i,j,q;
for (i=pocz; i<=kon; i++) t[i]=tab[i];  // Skopiowanie danych do tablicy pomocniczej
i=pocz; j=sr+1; q=pocz;                 // Ustawienie wskaŸników tablic
while (i<=sr && j<=kon) {         // Przenoszenie danych z sortowaniem ze zbiorów pomocniczych do tablicy g³ównej
if (t[i]<t[j])
tab[q++]=t[i++];
else
tab[q++]=t[j++];
}
while (i<=sr) tab[q++]=t[i++]; // Przeniesienie nie skopiowanych danych ze zbioru pierwszego w przypadku, gdy drugi zbiór siê skoñczy³
}
 
/* Procedura sortowania tab[pocz...kon] */
void mergesort(int pocz, int kon)
{
int sr;
if (pocz<kon) {
sr=(pocz+kon)/2;
mergesort(pocz, sr);    // Dzielenie lewej czêœci
mergesort(sr+1, kon);   // Dzielenie prawej czêœci
merge(pocz, sr, kon);   // £¹czenie czêœci lewej i prawej
}
}
 

int i;
 
cout<<"Zbior przed sortowaniem:";
for (i=0; i<N; i++)
cout<< tab[i], " ";
 
mergesort(0,N-1);
 
cout<<"\nZbior po sortowaniu:\n";
for (i=0; i<N; i++)
cout<< tab[i], " ";


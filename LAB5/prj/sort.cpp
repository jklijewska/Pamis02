#include "sort.hpp"
#include <ctime>
#include <cstdlib>
/*! 
	* \brief Definicja funkcji Quick_Sort .
	*
	*  Wykonywane sa 3 warianty (w zaleznosci od wyboru):
	* - optymistyczny -wybierana jest metoda z 3 z podanego zakresu liczb
	* - typowy - losowy element z zakresu liczb
	* - pesymistyczny - za kazdym razem wybierany jest najmniejszy element z zakresu

*/
void Quick_Sort( Tablica & T, int left, int right )
{
	srand(time(NULL));
	
	if(!T.Size()) return;
	
	int x;
    int i = left;
    int j = right;
    
	x = T.tab[( left + right ) / 2 ];					// Œrodkowy element tablicy
    //x = T.tab[rand()%( right - left ) + left];		// Losowy element tablicy

	/*													// Wariant pesymistyczny
	for(int y = left; y < right; y++)
	{
		x = T.tab[y];
		if(T.tab[y+1] < x)	x = T.tab[y+1];
	}
	*/
	/*													// Wariant optymistyczny ??
	int a, s, d;
	a = T.tab[rand()%( right - left ) + left];
	s = T.tab[rand()%( right - left ) + left];
	d = T.tab[rand()%( right - left ) + left];
	
	 if(a >= s && s <=d ) x = s;
else if(d >= a && a <=s ) x = a;
else 				  	  x = d;
	*/
	
    do
    {
        while( T.tab[ i ] < x )							// < dla sortowanie rosnacego, > dla malejacego
             i++;
       
        while( T.tab[ j ] > x )							// > dla sortowanie rosnacego, < dla malejacego
             j--;
       
        if( i <= j )
        {
            swap( T.tab[ i ], T.tab[ j ] );
           
            i++;
            j--;
        }
    } while( i <= j );
   
    if( left < j ) Quick_Sort( T, left, j );
   
    if( right > i ) Quick_Sort( T, i, right );
   
}
/*! 

	* \brief Definicja funkcji Heap_Sort .
	*
	*  Wykonywane sa 3 warianty (w zaleznosci od wyboru):
	* - optymistyczny -dla wstepnie posortowanych zbiorow
	* - typowy - ldla losowych elementow o losowym rozkladzie
	* - pesymistyczny - dla uporzadkowanych odwrotnie


*/
void Heap_Sort( Tablica & T )
{
	int i, j, k, m;
	
	T.Push(0);								// Wk³adamy dodatkowy element na pocz¹tek tablicy poniewa¿ sortowanie zaczyna siê od 2 elementu
	
	for(i = 2; i <= (T.Size()-1); i++)		// Budowanie kopca
  	{
    	j = i; 
		k = j / 2;
    	int x = T.tab[i];
    	
    	while((k > 0) && (T.tab[k] < x))
    	{
      		T.tab[j] = T.tab[k];
      		j = k; 
			k = j / 2;
    	}
    	T.tab[j] = x;
  	}
  	
  	for(i = (T.Size()-1); i > 1; i--)				// Rozbieranie kopca, w³aœciwe sortowanie
  	{
    	swap(T.tab[1], T.tab[i]);
    	j = 1;
		k = 2;
    	
		while(k < i)
    	{
      		if((k + 1 < i) && (T.tab[k + 1] > T.tab[k]))
        		m = k + 1;
      		else
        		m = k;
        		
      		if(T.tab[m] <= T.tab[j]) break;
      		
			swap(T.tab[j], T.tab[m]);
			j = m; 
			k = j + j;
    	}
  	}
	
	T.Pop();										// Zdejmujemy wczeœniej dodany element z tablicy
}
/*! 

	* \brief Definicja funkcji Merge .
	*
	*  Wykonywane sa 3 warianty (w zaleznosci od wyboru):
	* - optymistyczny -dla wstepnie posortowanych zbiorow
	* - typowy - ldla losowych elementow o losowym rozkladzie
	* - pesymistyczny - dla uporzadkowanych odwrotnie
*/
void Merge( Tablica & T, int left, int cent, int right )	// Funkcja Merge sortuj¹ca tablice
{
	double *tmp = new double[(right-left+1)];
	int i = left, j = cent+1, k = 0; 

	while (i <= cent && j <= right)
	{
		if (T.tab[j] < T.tab[i])
		{
			tmp[k] = T.tab[j];
			j++;
		}
		else
		{
			tmp[k] = T.tab[i];
			i++;
		}
		k++;
	}
 
	if (i <= cent)
	{
		while (i <= cent)
		{
			tmp[k] = T.tab[i];
			i++;
			k++;
		}
	}
	else
	{
		while (j <= right)
		{
			tmp[k] = T.tab[j];
			j++;
			k++;
		}
	}
 
	for (i = 0; i <= right-left; i++)
		T.tab[left+i] = tmp[i];
		
	delete tmp;

}
/*! 

	* \brief Definicja funkcji Merge .
	*
	* Funkcja Merge_Sort, dzieli tablice na mniejsze czêœci, a nastêpnie wywo³uje funkcje sortuj¹c¹ Merge 
*/

void Merge_Sort( Tablica & T, int left, int right )		
{

	int cent;
	if (left != right && T.Size()+1)
	{
		cent = (left + right)/2;
		Merge_Sort(T, left, cent);
		Merge_Sort(T, cent+1, right);
		Merge(T, left, cent, right);
	}
}

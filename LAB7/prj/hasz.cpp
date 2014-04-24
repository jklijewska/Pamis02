#include "hasz.hpp"
#include "zegar.hpp"

/*!
* \brief Metoda THasz.
*
* Zmienia rozmiar tablicy na 100. 
*/
THasz::THasz(int N)
	: L(N)
{
	tab.resize(N, "");
}
/*!
* \brief Metoda HF.
*
* Zmienia tekst na jakas liczbe z przedzialu 0-100.
* \return Modulo, aby nie wyjsc poza zakres tablicy.
*/
int THasz::HF(string s)
{
	unsigned h = 0;
	
	for(int i = 0; i < s.length(); i++)
	{
		h = 2 * h + 1 - ( (int)s[i] );
	}
	return h % L;	
}
/*! \brief Metoda AddKey
*
* Dodaje element.
*/
void THasz::AddKey(string s)
{
	int hf = HF(s), j = hf;
	vector<string>::iterator it = tab.begin() + j;
	
	//cout << "Nazwa: " << s << ", hf: " << hf << endl;
	
	while(true)
	{
		it = tab.begin() + j;
		
		if(*it == "")
		{
			*it = s;
			break;
		}
		if(*it == s) break;
		j = (j + 1) % L;
		if(j == hf) break;
	}
}
/*! \brief Metoda TakeKey
*
* Zwraca wartosc przypisana do klucza. Tu mierzony jest czas.
*/
vector<string>::iterator THasz::TakeKey(string s)
{
	unsigned hf = HF(s), j = hf;
	
	vector<string>::iterator it;
	
	while(true)
	{
		it = tab.begin() + j;
		
		if(*it == s)
		{
			cout << "Miejsce: " << j << endl;
			return it;
		}

		j = (j + 1) % L;
		//cout << "j: " << j << endl;
		if(j == hf)
		{ 
			cout << "Podany klucz nie istnieje." << endl;
			return it;
		} 
	}		
}
/*! \brief Metoda DeleteKey
*
* Usuwa element.
*/
void THasz::DeleteKey(string s)
{
	unsigned hf = HF(s), j = hf;
	
	while(true)
	{	
		if(tab[j] == s) tab.erase(tab.begin() + j);
		j = (j + 1) % 100;
		if(j == hf) break;
	}
}
/*! \brief Metoda Size
*
* Zwraca rozmiar tablicy.
*/
int THasz::Size()
{
	return tab.size();
}

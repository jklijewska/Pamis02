#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <cstdlib>
using namespace std;
/*! \brief Struktura Node
*
*Struktura wezla. Mamy ty wezel 'parent', lewy oraz prawy (ktore sa tworzone wg danego algorytmu). */
struct Node
{
	Node * parent, * left, * right;
	int key;
};
/*! \brief Klasa BST
*
* Klasa drzewa binarnego. Odpowiada za nizej opisane metody */
class BST
{
private:
	Node * root;
	int counter;
public:
	/*! \brief Konstruktor BST
*
*Konstruktor drzewa binarnego BST. */
	BST();
	/*! \brief Destruktor BST
*
*Destruktor drzewa BST */
   ~BST();
   /*! \brief Metoda AddKey
*
* Dodaje wartosc do naszego drzewa. Sprawdza, czy ma sie on znajdowac po lewej czy po prawej stronie (jak w zalozeniu drzewa).
*/
    bool AddKey(int inkey);
    /*! \brief Metoda TakeKey
*
*Zwraca wartosc przypisana do klucza. Tutaj mierzony jest tez czas*/
    Node * TakeKey(int inkey);
    /*! 
* \brief Metoda DeleteKey.
*
* Usuwa wezel z drzewa.
*/
    Node * DeleteKey(int inkey);
      /*! 
* \brief Metoda next.
*
* Tworzenie nastepnika.
*/
    Node * next(Node * n);
    /*!
* \brief Metoda prev.
*
* Tworzenie poprzednika.
*/
    Node * prev(Node * n);
      /*! \brief Metoda maxN
*
*Wyszukuje najwieksza wartosc wezla*/
    Node * maxN(Node * n);
     /*! \brief Metoda minN
*
*Wyszukuje najmniejsza wartosc wezla*/
    Node * minN(Node * n);
    /*! \brief Metoda Size, 
*
* zwraca iloœæ elementów w tablicy.
*/
    int Size();
	
};

#endif

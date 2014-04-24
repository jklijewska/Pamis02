#include "BST.hpp"
#include "zegar.hpp"
/*! \brief Konstruktor BST
*
*Konstruktor drzewa binarnego BST. */
BST::BST()
{
	root = NULL;
	counter = 0;
}

/*! \brief Destruktor BST
*
*Destruktor drzewa BST */
BST::~BST()
{
	while(root) delete(DeleteKey(root->key));
}

/*! \brief Metoda AddKey
*
* Dodaje wartosc do naszego drzewa. Sprawdza, czy ma sie on znajdowac po lewej czy po prawej stronie (jak w zalozeniu drzewa).
*/
bool BST::AddKey(int inkey)
{
	Node * n = new Node;
	Node * r = root, * p = NULL;
	
	int i = 0;
	
	n->key = inkey;
	n->left = n->right = NULL;

	while(r)
	{
		if(n->key == r->key)
		{
			delete n;
			return false;
		}
		
		//cout << "Dzialam! i: " << i << ", klucz: " << inkey << endl; i++;
		
		p = r;
		
		if(n->key < r->key) 
		  r = r->left;
		else
		  r = r->right;
	}
	
	n->parent = p;
	
	if(!p) root = n;
	else if(n->key < p->key) p->left = n;
	else p->right = n;
	
	counter++;
	return true;
}
/*! \brief Metoda TakeKey
*
*Zwraca wartosc przypisana do klucza. Tutaj mierzony jest tez czas*/
Node * BST::TakeKey(int inkey)
{
	Node * n = root;
	
	while(n)
	{
		if(n->key == inkey)
			return n;	
		
		if(inkey < n->key) 
		  n = n->left;
		else
		  n = n->right;
	}
	
	cout << "Podany klucz nie istnieje." << endl;
	
	return root;
}
/*! 
* \brief Metoda DeleteKey.
*
* Usuwa wezel z drzewa.
*/
Node * BST::DeleteKey(int inkey)
{
	Node * n = TakeKey(inkey);
	Node * p = n->parent;
	Node * x = NULL;
	
	if(n)
	{
		if((n->left) && (n->right))
		{
			x = (rand() % 2) ? DeleteKey(prev(n)->key) : DeleteKey(next(n)->key);
			x->left = n->left;
			if(x->left) x->left->parent = x;
			
			x->right = n->right;
			if(x->right) x->right->parent = x;
			
			counter++;
		}
		else
		x = (n->left) ? n->left : n->right;
		
		if(x) x->parent = p;
		
		if(!p) root = x;
		else if(p->left == n) p->left = x;
		else p->right = x;
		
		counter--;
		return n;
	}
	else
	cout << "Wezel o podanym kluczu nie istnieje." << endl;
}

Node * BST::next(Node * n)
{
	if(n->right) return minN(n->right);
	
	Node * p = NULL;
	
	do
	{
		p = n;
		n = n->parent;
	}while(n && (n->left != p));
	
	return n;
}

Node * BST::prev(Node * n)
{
	if(n->left) return maxN(n->left);
	
	Node * p = NULL;
	
	do
	{
		p = n;
		n = n->parent;
	}while(n && (n->right != p));
	
	return n;
}

Node * BST::minN(Node * n)
{
	while(n->left) n = n->left;
	return n;
}

Node * BST::maxN(Node * n)
{
	while(n->right) n = n->right;
	return n;
}
/*! \brief Metoda Size, 
*
* zwraca iloœæ elementów w tablicy.
*/
int BST::Size()
{
	return counter;
}

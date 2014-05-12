#include "graf.hpp"

void Graf::WyswietlGraf() 
{
	cout << "W";
		
	for(int i = 0; i < Wierzcholki; i++) 
		cout << left << setw(3) << " | " << i;
		
	cout << endl;
		
	for(int i = 0; i < 2 + Wierzcholki * 4; i++)
		cout << "-";
		
	cout << endl;
		
	for(int i = 0; i < Wierzcholki; i++)
	{
		cout << left << i;
			
		for(int j = 0; j < Wierzcholki; j++) 
			cout << left << setw(3) << " | " << Macierz[i][j];
			
		cout << endl;
			
		for(int i = 0; i < 2 + Wierzcholki * 4; i++)
			cout << "-";
			
		cout << endl;
	}
	cout << endl << endl;
}

void Graf::IloscKrawedzi(int K)
{
	Krawedzie = K;
}

void Graf::StworzGraf(int M)
{
	Wierzcholki = M;
		
	Macierz = new int*[M];
	for(int i=0; i<M; i++)
		Macierz[i] = new int[M];

	for(int i=0; i<M; i++)
		for(int j=0; j<M; j++)
			Macierz[i][j]=0;
}

void Graf::DodajKrawedz(int W1, int W2, int C)
{
	Macierz[W1][W2] = Macierz[W2][W1] = C;
}

void Graf::UsunKrawedz(int W1, int W2)
{
	Macierz[W1][W2] = Macierz[W2][W1] = 0;
}

bool Graf::CzyPolaczone(int W1, int W2)
{
	if(Macierz[W1][W2] != 0 && Macierz[W2][W1] != 0) return true;
	else return false;
}

void Graf::Sasiedztwo(int W)
{
	cout << left << setw(3) << "W";
		
	for(int i = 0; i < Wierzcholki; i++) 
		cout << left << setw(3) << i;
			
	cout << endl;
	cout << W << ": ";
		
	for(int i = 0; i < Wierzcholki; i++)
		cout << left << setw(3) << Macierz[W][i];
		
	cout << endl << endl;
}

void Graf::DFS(int W) 
{
	bool *odwiedzony = new bool[Wierzcholki];
		
	for(int i = 0; i < Wierzcholki; i++) 
		odwiedzony[i] = false;
			
	stack<int> stos;
	stos.push(W);
		
	cout << "DFS:  ";
		
	while(!stos.empty())
	{
		W = stos.top();  
		stos.pop();
			
		if(!odwiedzony[W])
    	{
   		 odwiedzony[W] = true;
          			
         for(int i = 0; i < Wierzcholki; i++) 
			if(Macierz[W][i] && !odwiedzony[i]) 
				stos.push(i);
							
         	cout << W << " ";
      	}
	} 
	cout << endl << endl;
}

void Graf::BFS(int W)
{
	bool *odwiedzony = new bool[Wierzcholki];
		
	for(int i = 0; i < Wierzcholki; i++) 
		odwiedzony[i] = false;
			
	queue<int> kolejka;
	kolejka.push(W);
		
	cout << "BFS:  ";
		
	while(!kolejka.empty())
	{
		W = kolejka.front(); 
		kolejka.pop();
			
		if(!odwiedzony[W])
     	{
          	odwiedzony[W] = true;
          			
          	for(int i = 0; i < Wierzcholki; i++) 
				if(Macierz[W][i] && !odwiedzony[i]) 
					kolejka.push(i);
          		
			cout << W << " ";
      	}
	} 
	cout << endl << endl;
}



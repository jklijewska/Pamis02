#include "NWP.hpp"

NWP::~NWP()
{
	for(int i = 0; i < N; i++)
			delete [] Macierz[i];  

	delete [] Macierz;
	
	delete A, B;
}

void NWP::StworzMacierz(char *C1, char *C2)
{
	M = strlen(C1) + 1;
	N = strlen(C2) + 1;
	
	A = new char;
	B = new char;
	
	strcpy(A, C1);
	strcpy(B, C2);
	
	Macierz = new int*[N];
	for(int i = 0; i < N; i++)
		Macierz[i] = new int[M];
			
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
		Macierz[i][j] = 0;
}

void NWP::WyliczMacierz()
{	
	for(int i = 1; i < N; i++)
		for(int j = 1; j < M; j++)
			if(B[i-1]==A[j-1])
				Macierz[i][j] = Macierz[i-1][j-1] + 1;
			else
			{
				if(Macierz[i-1][j] > Macierz[i][j-1])
					Macierz[i][j] = Macierz[i-1][j];
				else
					Macierz[i][j] = Macierz[i][j-1];
			}
}

void NWP::OdtworzNWP()
{
	int i = N-1, j = M-1;
	
	string NWP = "";
	/*
	cout << endl << endl;
	
	do
	{
		
		if(Macierz[i][j] == Macierz[i][j-1] || Macierz[i][j] == Macierz[i-1][j])
		{
			j--;
		}
		else if(i == 0 && j == 0) { }
		else
		{
			NWP = A[j-1] + NWP;
			j--;
			i--;
		}	
		
	}while((i >= 0) && (j >= 0));
	*/
	
	cout << endl << endl;
	while((i >= 0) && (j >= 0))
	{
		if(A[j] == B[i])
		{
			NWP = A[j] + NWP;
			i--; j--;
		}
		else if(Macierz[i-1][j] > Macierz[i][j-1])
			i--;
		else
			j--;
	}
	
	cout << "NWP: " << NWP << endl;
}

void NWP::Show()
{
	
	cout << "A: " << A << ", B: " << B << endl;
	cout << "M: " << M << ", N: " << N << endl;	
	
	cout << endl;
	cout << "    ";
	for(int i = 0; i < M; i++)
	cout << A[i] << " ";
	
	for(int i = 0; i < N; i++)
	{
		if(i>0)cout << endl << B[i-1] << " ";
		else cout << endl << "  ";
		
		for(int j = 0; j < M; j++)
			cout << Macierz[i][j] << " ";
	}
}

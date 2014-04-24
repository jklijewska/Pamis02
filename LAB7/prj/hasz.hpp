#ifndef HASZ_HPP
#define HASZ_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class THasz
{
private:
	vector <string> tab;
	const int L;
	
public:
	THasz(int N);
	
	int HF(string s);
	void AddKey(string s);
	vector<string>::iterator TakeKey(string s);
	void DeleteKey(string s);
	int Size();
};

#endif

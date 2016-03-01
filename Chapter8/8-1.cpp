//8.1
// Chapter8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<map>
#include<iostream>

using namespace std;

int hopSteps(int n, map<int, int> &mem){

	if (n == 0){
		return 1;
	}
	else if (n < 0){
		return 0;
	}
	else if (mem[n] != -1){
		return mem[n];
	}
		mem[n] = hopSteps(n - 3, mem) + hopSteps(n - 2, mem) + hopSteps(n - 1, mem);
		return mem[n];
}

int hopSteps(int n){
	map<int, int> mem;
	for (int i = 0; i <= n; i++){
		mem[i] = -1;
	}

	return hopSteps(n, mem);
}

int main()
{
	cout << hopSteps(5) << endl;
	system("pause");
	return 0;
}
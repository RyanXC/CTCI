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
	mem[n] = hopSteps(n - 25, mem) + hopSteps(n - 10, mem) + hopSteps(n - 5, mem) + hopSteps(n - 1, mem);
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
	cout << hopSteps(25) << endl;
	system("pause");
	return 0;
}
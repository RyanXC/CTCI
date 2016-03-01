
#include "stdafx.h"

#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<map>

using namespace std;

void insertParensHelper(string prefix, int left, int right, int remaining, list<string> &allStrings){
	//No more paren can be insert.
	if (left < 0 || right < 0){
		return;
	}

	//Base Case. Permutation has been completed.
	if (remaining == 0){
		allStrings.push_back(prefix);
		return;
	}

	//Add left paren, if there are any left parens remaining.
	if (left <= right){
		insertParensHelper(prefix + '(', left - 1, right, remaining - 1, allStrings);
		insertParensHelper(prefix + ')', left, right - 1, remaining - 1, allStrings);
	}
}

list<string> insertParens(int num){

	list<string> allStrings;
	//case 1. If num is NULL
	if (num == 0){
		allStrings.push_back("");
		return allStrings;
	}

	string prefix = "";
	int remaining = num*2;
	int left = num;
	int right = num;
	insertParensHelper(prefix, left, right, remaining, allStrings);

	return allStrings;
}


int main(){
	int num = 3;
	list<string> allStrings;
	allStrings = insertParens(num);

	for (auto &c : allStrings){
		cout << c << endl;
	}

	system("pause");
	return 0;
}


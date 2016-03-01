
#include "stdafx.h"

#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<map>

using namespace std;

typedef map<char, int> CharMap;


void insertDuCharHelper(CharMap charmap, string prefix, int remaining, list<string> &allStrings){
	//Base Case. Permutation has been completed.
	if (remaining == 0){
		allStrings.push_back(prefix);
		return;
	}
	//Use each letter as the prefix and update the remaining and charmap.
	for (CharMap::iterator i = charmap.begin(); i != charmap.end(); ++i){
		if (i->second > 0){
			i->second--;
			insertDuCharHelper(charmap, prefix + i->first, remaining - 1, allStrings);
			//Recover the hash table to other cases.
			i->second++;
		}
	}
}

list<string> insertDuChar(string ori){

	list<string> allStrings;
	//case 1. If ori is NULL
	if (ori.length() == 0){
		allStrings.push_back("");
		return allStrings;
	}

	//generate a hash map;
	CharMap charMap;
	for (auto &s : ori){
		charMap[s]++;
	}

	string prefix = "";
	int remaining = ori.length();

	insertDuCharHelper(charMap, prefix, remaining, allStrings);

	return allStrings;
}


int main(){
	string test = "abab";
	list<string> allStrings;
	allStrings = insertDuChar(test);

	for (auto &c : allStrings){
		cout << c << endl;
	}

	system("pause");
	return 0;
}


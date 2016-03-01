//8.7

#include "stdafx.h"

#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<string>
#include<list>

using namespace std;

void insertCharHelper(string cur, string ori, int index, list<string> &allStrings){
	//case 1. Already done.
	if (index == ori.length()){
		allStrings.push_back(cur);
		return;
	}

	//case 2. Insert ori[index] into cur at different locations.
	char newChar = ori[index];
	for (int i = 0; i <= index; ++i){
		string start = cur.substr(0, i);
		string end = cur.substr(i);
		string temp = start + newChar + end;

		//recursion
		insertCharHelper(temp, ori, index + 1, allStrings);
	}
}


list<string> insertChar(string ori){
	list<string> allStrings;

	//case 1 ori is empty, which means the length is 0, return "";	
	if (ori.length() == 0){
		allStrings.push_back("");
		return allStrings;
	}
	
	//case 2
	int index = 0;
	string first = ori.substr(index, 1);  //first letter.
	insertCharHelper(first, ori, index+1, allStrings);

	return allStrings;
}


int main(){
	string test = "abc";
	list<string> allStrings;
	allStrings = insertChar(test);

	for (auto &c : allStrings){
		cout << c << endl;
	}

	system("pause");
	return 0;
}


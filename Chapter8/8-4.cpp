#include "stdafx.h"

#include<iostream>
#include<iterator>
#include<list>
#include<math.h>

using namespace std;

list<list<int>> allSubsets(const int *N, int sizeN){
	list<list<int>> all;  //All subsets list
	list<int> em; //empty set
	all.push_back(em);

	list<int> first = { N[0] };
	all.push_back(first);

	//1.                       all => { }, {a1}
	//2. temp = all[0];        temp=>{ }
	//3. temp.push_back(a2};   temp=>{a2}
	//4. all.push_back(temp);  all=>{ }, {a1}, {a2}

	for (int n = 1; n<sizeN; n++){
		list<list<int>>::iterator i = all.begin();

		for (int currSize = 0; currSize < pow(2,n); ++currSize){
			list<int> temp = *i;
			temp.push_back(N[n]);
			all.push_back(temp);
			i++;
		}
	}

	return all;
}

int main(){
	int N[3] = { 0, 1, 2 };
	list<list<int>> subsets;
	subsets = allSubsets(N, end(N) - begin(N));

	for (list<list<int>>::iterator i = subsets.begin(); i != subsets.end();i++){
		cout << "( ";
		for (auto &j: *i){
			cout << j << " ";
		}
		cout << ")" << endl;
	}

	system("pause");
	return 0;
}
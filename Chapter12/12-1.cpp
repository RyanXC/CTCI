
#include "stdafx.h"

#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void printLastKlines(string filename){

	const int k = 4;
	string L[k];
	ifstream in(filename);
	int size = 0;

	if (in){
		//Returns the next character in the input sequence, without extracting it:
		while (in.peek() != EOF){  //if the next line is not the End of file.
			getline(in, L[size%k]);  //circular array.
			size++;
		}

		//case 1. size <= k .
		//k = 5, size = 3, there are only three lines in the file.
		//print L[0] to L[min(k,size)-1].

		//case 2. size >k. 
		//k = 3, size = 7, there are seven lines in the file.
		//0 1 2
		//3 4 5
		//6     
		//print out 4, 5, 6. Start at L[1] to L[0], which means L[(size % k + i) % k], i from 0 to k

		int start = size>k ? (size%k) : 0;
		int count = min(k, size);

		for (int i = 0; i<count; i++){
			cout << L[(start + i) % k] << endl;
		}
	}
}

int main(){

	string file1 = "12-1_test_case1.txt";
	string file2 = "12-1_test_case2.txt";

	cout << "File 1" << endl;
	printLastKlines(file1);

	cout << "File 2" << endl;
	printLastKlines(file1);

	system("pause");
	return 0;
}

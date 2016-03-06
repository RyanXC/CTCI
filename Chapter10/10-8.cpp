#include"stdafx.h"

#include<bitset>
#include<iostream>

using namespace std;

void checkDuplicate(int arr[], int n){
	bitset<32000> numCount;
	for (size_t i = 0; i < n; i++){
		int num = arr[i]; //num start at 1, index start at 0
		if (numCount[num-1]){ //duplicate
			cout << num << endl;
		}
		else{
			numCount.set(num - 1);
		}
	}
	return;
}

int main(){

	int arr[32000];
	for (size_t i = 0; i < 1999; i++){
		arr[i] = i+1;
	}

	arr[1999] = arr[1998];

	for (size_t i = 2000; i < 32000; i++){
		arr[i] = i;
	}

	checkDuplicate(arr, 32000);
	system("pause");
	return 0;
}
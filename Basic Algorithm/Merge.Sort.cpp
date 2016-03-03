//Merge Sort
//https://en.wikipedia.org/wiki/Merge_sort
#include"stdafx.h"

#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

template<typename T, size_t N>
void mergeSort(T(&A)[N], T(&helper)[N], int low, int middle, int high){

	//Copy elements from A to helper
	for (size_t i = low; i <= high; ++i){
		helper[i] = A[i];
	}

	int helpLeft = low;
	int helpRight = middle + 1;
	int current = low;

	while (helpLeft <= middle && helpRight <= high){
		//case 1, left < right. insert left to array, current++, left ++
		if (helper[helpLeft] < helper[helpRight]){
			A[current] = helper[helpLeft];
			++helpLeft;
		}
		//case 2, left >= right. insert right to array, current++, right ++
		else{
			A[current] = helper[helpRight];
			++helpRight;
		}
		current++;
	}

	//Ex: 3 4 || 1 2  -> 1  2  ( 3  4 )
	//Copy the rest of the left elements into the array.
	//Ex: 0   1   2   3   4
	//    hf     mid
	//->         mid  hf      -> remaining = -1;
	int remaining = max(middle - helpLeft, 0);
	for (size_t i=0; i <= remaining; ++i){
		A[current + i] = helper[helpLeft + i];
	}

	return;
}

template<typename T, size_t N>
void mergeSortHelper(T (&A)[N], T (&helper)[N], int low, int high){
	
	if (low < high){
		int middle = (low + high) / 2;
		//pro-order: left, right, process.
		mergeSortHelper(A, helper, low, middle);
		mergeSortHelper(A, helper, middle + 1, high);
		mergeSort(A, helper, low, middle, high);
	}

	return;
}

template<typename T, size_t N>
void mergeSort(T (&A)[N]){
	int helper[N];
	mergeSortHelper(A, helper, 0, N - 1);
	return;
}

int main(){
	int A[] = { 4, 3, 1, 11, 7 };
	mergeSort(A);
	for (auto &i : A){
		cout << i << endl;
	}

	system("pause");
	return 0;
}
// Chapter8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<iterator>
#include<map>
#include<algorithm>

using namespace std;

int findMagicIndex(const int A[], int start, int end){

	int n = (start + end) / 2;

	if (end - start<0){
		return -1;
	}

	//if A[n]==n, we find it.
	if (A[n] == n){
		return n;
	}

	int left = findMagicIndex(A, start, min(A[n], n - 1));
	if (left >= 0){
		return left;
	}

	int right = findMagicIndex(A, max(A[n], n + 1), end);
	if (right >= 0){
		return right;
	}

}

int findMagicIndex(const int A[],int num){

	return findMagicIndex(A, 0, num - 1);
}

int main(){

	int A[] = { -1, 0, 1, 2, 3, 4, 5, 7 };
	cout << findMagicIndex(A, end(A)-begin(A)) << endl;

	system("pause");
	return 0;
}
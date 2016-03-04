//10.3
#include"stdafx.h"
#include<iostream>

using namespace std;

int searchNum(int A[], int start, int end, int x){
	//case 1.
	if (start > end){
		return -1;
	}

	//case 2. mid == x
	int middle = (start + end) / 2;
	if (A[middle] == x){
		return middle;
	}

	//case 3. start = end;
	if (start == end){
		return -1;
	}

	//case 4. start < middle
	//case 4.1 x belongs to [start, middle], go left.
	//case 4.2 go right.
	if (A[start] < A[middle]){
		if (x >= A[start] && x <= A[middle]){
			return searchNum(A, start, middle - 1, x);
		}
		else{
			return searchNum(A, middle + 1, end, x);
		}
	}

	//case 5. start > middle   10 2 3 4 5 6 7, find 2
	//case 5.1 x belongs to [middle, end], go right.
	//case 5.2 go left.
	if (A[start] > A[middle]){
		if (x >= A[middle] && x <= A[end]){
			return searchNum(A, middle + 1, end, x);
		}
		else{
			return searchNum(A, start, middle - 1, x);
		}
	}

	//case 6. start = middle
	//case 6.1 middle = end
	//case 6.1.1 go left.
	//case 6.1.2 go right.
	//return num!=-1;
	if (A[start] == A[middle]){
		if (A[middle] == A[end]){
			int result = searchNum(A, start, middle - 1, x);
			if (result == -1){
				return searchNum(A, middle + 1, end, x);
			}
		}
		else{
			//case 6.2 go right.
			return searchNum(A, middle + 1, end, x);
		}
	}

	return -1;
}

int main(){
	int A[] = { 1, 2, 2, 4, 6, 10 };
	int N = sizeof(A) / sizeof(int);
	int x = 10;

	cout << searchNum(A, 0, N, x) << endl;

	system("pause");
	return 0;
}
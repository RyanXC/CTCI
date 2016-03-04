//Radix Sort
//Count Sort
//Reference: http://www.geeksforgeeks.org/radix-sort/
#include"stdafx.h"

#include<iostream>

using namespace std;

//Get the max number in an array to detemine the number of digits.
int getMax(int arr[], int n){

	int maxNum = INT_MIN;
	for (size_t i = 0; i< n; ++i){
		if (arr[i] > maxNum){
			maxNum = arr[i];
		}
	}
	return maxNum;
}

//Count Sort
//   arr[]: 3 7 2 4 4 6 5

//          0 1 2 3 4 5 6 7
// count[]: 0 0 1 1 2 1 1 1 

// count[]: 0 0 1 2 4 5 6 7    count[i] += count[i-1];  

// 3 should be at second(1) position in the output array.
// 6 should be at sixth(5) position in the output array.
// arr[i] should be at count[arr[i]]-1 position in the output array.
// output[count[arr[i]-1] = arr[i];

// for(i = n - 1 ; i >= 0 ; --i) to guarantee the stale of the sorting algorithm
// count[arr[i]]--;

template<typename T, size_t N>
void countSort(T (&arr)[N], int exp){
	int count[10] = { 0 };
	int output[N];

	//count numbers.
	for (size_t i = 0; i < N; i++){
		count[(arr[i] / exp) % 10]++;  // 320/10 = 32, 32 % 10 = 2. 
	}

	//determine the actual position of each element.
	for (size_t i = 1; i < 10; i++){
		count[i] += count[i - 1];
	}

	//determine the output array. 
	//Cannot use size_t i here, because i = 0, i - 1 != -1;
	for (int i = N - 1; i >= 0; --i){
		int pos = count[(arr[i] / exp) % 10] - 1;
		output[pos] = arr[i];
		count[(arr[i] / exp) % 10] --;
	}

	//copy output to arr;
	for (size_t i = 0; i < N; i++){
		arr[i] = output[i];
	}
	return;
}

template<typename T, size_t N>
void radixSort(T (&arr)[N]){

	int d = getMax(arr, N);

	//Run count sort from the least to most significant.
	for (int exp = 1; d / exp > 0; exp = exp * 10){
		countSort(arr, exp);
	}
	return;
}

int main(){
	int x[] = { 0, 1, 98, 88, 998, 598, 148, 48 };

	for (auto &i : x){
		cout << i << " ";
	}

	cout << " " << endl;
	radixSort(x);

	for (auto &i : x){
		cout << i << " ";
	}

	system("pause");
	return 0;

}
//Quick Sort

//Partition + Randomized

#include"stdafx.h"

#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<random>

using namespace std;

//Partition
//  1 6 7 2 (3)
//i          p 
//j

//(0,i) should be smaller than p.
//  1 6 7 2 3  i++, i<p, j++
//  i       p
//j 

//  1 6 7 2 3  swap(i,j)
//  i
//  j

//  1 6 7 2 3  i++, i>p
//    i
//  j

//  1 6 7 2 3  i++, i>p
//      i
//  j

//  1 6 7 2 3  i++, i<p, j++
//        i
//  j

//  1 6 7 2 3  swap(i,j)
//        i
//    j

//  1 2 7 6 3  
//        i
//    j

//  1 2 7 6 3  i++, i=length-1, swap(i, j+1)
//          i
//    j

//  1 2 3 6 7
//          i
//    j

//return the index of the partition element.
template<typename T, size_t N>
int partition(T(&A)[N], int start, int end){
	int i = strat - 1;
	int j = start - 1;
	int p = end;
	int temp;

	do{
		j++;
		if(A[j]<A[end]){
			i++;
			//swap A[i] with A[j];
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}while(j<end-1);

	//swap(p, j+1)
	temp = A[p];
	A[p] = A[j + 1];
	A[j + 1] = temp;

	return j + 1;
}

//Quick Sort.
template<typename T, size_t N>
void quickSort(T(&A)[N], int start, int end){

	if (start < end){
		//generate a random number.
		uniform_int_distribution<unsigned> u(start, end);
		default_random_engine e;
		int r = u(e);
		//swap(r, end)
		int temp;
		temp = A[end];
		A[end] = A[r];
		A[r] = temp;

		//Partition
		int p = partition(A, start, end);
		//left start, p-1.
		quickSort(A, start, p - 1);
		//right p+1, end
		quickSort(A, p + 1, end);
	}

	return;
}



int main(){
	int A[] = { 1, 6, 7, 2, 3, 11, 93, 100, 65};
	int N = sizeof(A) / sizeof(int);

	quickSort(A, 0, N - 1);
	for (auto &i : A){
		cout << i << " ";
	}

	system("pause");
	return 0;
}

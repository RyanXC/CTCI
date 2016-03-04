//10.1

#include<iostream>

using namespace std;

template<typename T, size_t N>
void sortedMerge(T (&A)[N], int B[], int numOfB, int numOfA){
	int indexA = numOfA-1;
	int indexB = numOfB-1;
	int indexOutput = N-1;
	while(indexB>0){
		//compare A[indexA] and B[indexB].
		//case 1. A>B, A[indexOutput] = A[indexA], indexA --.
		if(indexA>=0 && A[indexA]>B[indexB]){
			A[indexOutput] = A[indexA];
			indexA--;
		//case 2. A<=B, A[indexOuput]= B[indexB], indexB --.
			}else{
			A[indexOutput] = B[indexB];
			indexB--;
		}
		indexOuput--;
	}
	
	return;
}
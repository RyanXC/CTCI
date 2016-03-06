#include"stdafx.h"

#include<bitset>
#include<iostream>

using namespace std;

template<typename T, size_t N, size_t M>
void matrixFind(T (&arr)[N][M], int value, int &r, int &c){

	int row = 0;
	int col = M - 1;
	while (row < N&&col >= 0){
		//case 1. find element.
		if (arr[row][col] == value){
			r = row;
			c = col;
			return;
		} 
		if (col != 0){
			//case 2. arr[row][col-1] == value.
			if (arr[row][col - 1] == value){
				r = row;
				c = col - 1;
				return;
			}
			//case 2. arr[row][col]>value, arr[row][col-1]<value. row++.
			if (arr[row][col - 1] < value && arr[row][col]>value){
				row++;
			}
			//case 3. The most right element is less than value. 
			if (arr[row][col] < value){
				row++;
			}
			//case 3. arr[row][col]>value, arr[row][col-1]>value. col--.
			else{
				col--;
			}
		}
		else{
			return;
		}
	}

	//not find
	r = -1;
	c = -1;
	return;
}

int main(){

	int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	int r, c;
	matrixFind(arr, 7, r, c);
	cout << r << c << endl;

	system("pause");
	return 0;

}
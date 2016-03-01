#include "stdafx.h"

#include<iostream>
#include<iterator>
#include<list>
#include<math.h>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

//3x11 : 000011 * 001011
int multiplicationOperationHelper(int small, int big){

	if (small == 0){
		return 0;
	}

	int halfProd = multiplicationOperationHelper(small >> 1, big);

	int modeValue = small - ((small >> 1) << 1); //
	if (modeValue == 0){
		return (halfProd << 1);
	}
	else{
		return (halfProd << 1) + big;
	}
}

int multiplicationOperation(int a, int b){
	int small = min(a, b);
	int big = max(a, b);

	return multiplicationOperationHelper(small, big);
}

int main(){
	int a = 3;
	int b = 11;
	int result = multiplicationOperation(a, b);
	cout << result << endl;
	system("pause");
	return 0;
}
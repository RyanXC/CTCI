
#include "stdafx.h"

#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<map>
#include<vector>

using namespace std;

enum Color{
	Black,
	White,
	Red,
	Blue,
	Green
};

typedef vector<vector<Color>> Canvas;

bool paintFillHelper(Canvas &c, int row, int col, Color oriColor, Color newColor){
	//Exceed the range
	if (row<0 || row >=c.size() || col<0 || col>=c[0].size()){
		return false;
	}

	//DFS
	if (c[row][col] == oriColor){
		c[row][col] = newColor;
		paintFillHelper(c, row - 1, col, oriColor, newColor);
		paintFillHelper(c, row, col - 1, oriColor, newColor);
		paintFillHelper(c, row + 1, col, oriColor, newColor);
		paintFillHelper(c, row, col + 1, oriColor, newColor);
	}
	return true;
}

bool paintFill(Canvas &c, int row, int col, Color newColor){
	if (c[row][col] == newColor){
		return false;
	}
	return paintFillHelper(c, row, col, c[row][col], newColor);
}
int main(){

	Canvas c;
	int col, row;
	col = 4;
	row = 3;
	Color oriColor, newColor;
	oriColor = Black;
	newColor = Red;
	vector<Color> ori;
	for (int i = 0; i < col; i++){
		ori.push_back(oriColor);
	}
	for (int i = 0; i < row; i++){
		c.push_back(ori);
	}

	bool done = paintFill(c, 2, 1, newColor);
	
	system("pause");
	return 0;
}


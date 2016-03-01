// Chapter8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<iterator>
#include<map>

const int col=3;

using namespace std;

bool findPath(const int grid[][col], int rowNum, int colNum, vector<tuple<int,int>> &pathList, map<tuple<int,int>,bool> &cathe){
	//determine whether the slot is available.
	if (rowNum < 0 || colNum < 0 || grid[rowNum][colNum] == -1){
		return false;
	}

	//determine whether the current slot has been visited before. If it has, return its bool value.
	tuple<int,int> curr(rowNum, colNum);
	if (cathe.count(curr)>0){
		return cathe[curr];
	}

	//determine whether we get the end point.
	if (rowNum == 0 && colNum == 0){
		pathList.push_back(curr);
		return true;
	}

	//recursion
	bool isAPath = findPath(grid, rowNum - 1, colNum, pathList, cathe) || findPath(grid, rowNum, colNum - 1, pathList, cathe);
	
	//there is a available path. Add slots along that path to vector and update the hashmap.
	if (isAPath){
		pathList.push_back(curr);
		cathe[curr] = true;
		return true;
	}

	//there is no available path. Update the hashmap and return false.
	cathe[curr] = false;
	return false;

}


vector<tuple<int,int>> findPath(const int grid[][col]){

	int rowNum = sizeof(grid)-1;
	int colNum = sizeof(grid[0]) / sizeof((*grid)[0]);
	vector<tuple<int,int>> pathList;
	map<tuple<int,int>, bool> cathe;
	findPath(grid, rowNum, colNum, pathList, cathe);
	return pathList;
}

int main()
{
	int grid[4][col] = { 0 };
	grid[0][2] = -1;
	grid[1][2] = -1;
	grid[2][1] = -1;

	vector<tuple<int, int>> pathList;
	pathList = findPath(grid);
	
	for (auto b = pathList.begin(); b!= pathList.end(); b++){
		cout << "(" << get<0>(*b) << ", " << get<1>(*b) << " )" << endl;
	}
	system("pause");
	return 0;
}
#include"stdafx.h"

#include<iostream>

using namespace std;
class TreeNode{
public:
	TreeNode *left, *right;
	int data = 0;
	int leftSize = 0; //leftSize is used to record how many number is less that data in the subtree.

	TreeNode(int d){
		data = d;
	}

	int getRank(int d){
		//case 1. d==data, return leftSize.
		if (d == this->data){
			return leftSize;
		}
		//case 2. d>data. go right.
		if (d > this->data){
			if (right == NULL){
				return -1;
			}
			else{
				int result = right->getRank(d);
				return result == -1 ? -1: leftSize + result + 1; 
				// 20(4) -> 23(0) -> 24(0), getRank(24). return 4 + 1 + 1. 
				//Since two parents node are less than 24
			}
		}
		else{
			//case 3. d<data. go left.
			if (left == NULL){
				return -1;
			}
			else{
				return left->getRank(d);
			}
		}
	}


	void insert(int d){
		//case 1.
		if (d < this->data){
			//go left.
			if (left != NULL){
				//update leftSize.
				leftSize++;
				left->insert(d);
			}
			else{
				//create a new node and update the leftSize
				//update the leftSize
				TreeNode *curr = new TreeNode(d);
				left = curr;
				leftSize++;
			}
		}
		else{
			//go right
			if (right != NULL){
				right->insert(d);
			}
			else{
				TreeNode *curr = new TreeNode(d);
				right = curr;
			}
		}
	}
};

//Insert number.
TreeNode* track(int d, TreeNode *r){
	if (r == NULL){
		TreeNode *root = new TreeNode(d);
		return root;
	}
	else{
		r->insert(d);
	}
	return r;
}

int main(){
	int arr[] = { 20, 15, 25, 10, 23, 5, 13, 24 };
	TreeNode *root = NULL;
	for (size_t i = 0; i < sizeof(arr) / sizeof(int); ++i){
		root = track(arr[i],root);
	}

	cout << root->getRank(24) << endl;
	cout << root->getRank(14) << endl;

	system("pause");
	return 0;
}

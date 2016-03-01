
#include "stdafx.h"

#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

typedef map<Node*, Node*> NodeMap;

struct Node{
	Node *ptr1, *ptr2;
};

Node * copyRecursive(Node *cur, NodeMap &nodeMap){
	//Case 1, if cur == Null, return NULL;
	if (cur == NULL){
		return NULL;
	}

	//Case 2, if the cur is already in the map. 
	//Such as N1->ptr1 = N2, N2->ptr1 = N1.
	//return cur's copy.
	NodeMap::iterator i = nodeMap.find(cur);
	if (i != nodeMap.end()){
		return i->second;
	}

	//Case 3, if the cur is new in the map, declare a new node and copy its
	//two pointers recursively, till NULL or some existed Node.
	Node *temp = new Node;
	nodeMap[cur] = temp;
	temp->ptr1 = copyRecursive(cur->ptr1, nodeMap);
	temp->ptr2 = copyRecursive(cur->ptr2, nodeMap);
	return temp;
}

Node* copy_structure(Node* root){
	NodeMap nodeMap;
	return copyRecursive(root, nodeMap);
}

int main(){
	Node one, two, three;
	one.ptr1 = &two;
	one.ptr2 = &three;
	two.ptr1 = NULL;
	two.ptr2 = NULL;
	three.ptr1 = NULL;
	three.ptr2 = NULL;

	Node *four;
	four = copy_structure(&one);

	system("pause");
	return 0;
}


#include "stdafx.h"

#include<iostream>
#include<iterator>
#include<list>
#include<math.h>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

class Tower{
	stack<int> disk;
	int index;

public:
	Tower(int d){
		index = d;
	}

	int getIndex(){
		return index;
	}

	stack<int> getDisk(){
		return disk;
	}

	void add(int k){
		if (!disk.empty() && disk.top() <= k){
			cout << "Error placing disk " << k << endl;
		}
		else{
			disk.push(k);
		}
	}

	void moveToTop(Tower &t){
		t.add(disk.top());
		disk.pop();
	}

	void moveDisks(int n, Tower &destination, Tower &buffer){
		if (n > 0){
			moveDisks(n - 1, buffer, destination);
			moveToTop(destination);
			buffer.moveDisks(n - 1, destination, *this);
		}
	}
};


int main(){
	int n = 3;
	vector<Tower> v;

	for (int i = 0; i < n; ++i){
		Tower temp(i);
		v.push_back(temp);
	}


	for (int i = n; i >0; --i){
		v[0].add(i);
	}

	v[0].moveDisks(n, v[2], v[1]);

	stack<int> des = v[2].getDisk();
	for (int j = 0; j < n; ++j){
		cout << (des.top())<< endl;
		des.pop();
	}
	system("pause");

	return 0;
}
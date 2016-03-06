


int searchListy(Listy list, int value){
	index = 1;
	while(list.elementAt(index)!=-1 && list.elementAt(index)<value){
		index *=2;
	}
	return binarySearch(list, value, index/2, index);	
}

int binarySearch(Listy list, int value, int start, int end){
	
	if(start > end){
		return -1;
	}
	
	int mid = (start+end)/2;
	
	if(list.elementAt(mid)==value){
		return mid;
	}
	
	if(list.elementAt(mid) > value){
		return binarySearch(list, value, start, mid-1);
	}
	else{
		return binarySearch(list, value, mid+1, end);
	}
	
	return -1;
}

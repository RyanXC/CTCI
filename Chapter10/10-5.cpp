int binarySearchSpaceString(string arr[], string value, int start, int end){
	
	if(start>end){
		return -1;
	}
		
	//case 2. If mid == "".
	if(arr[mid].length() == 0){
		int left, right;
		left = mid-1;
		right = mid+1;
		
		while(true){
			//case 2.1 Exceed the range, return -1.
			if(left < start && right > end){
				return -1;
			}
			else if(right<=end && arr[right].length()!=0){
				mid = right;
				break;
			}
			else if(left>=start && arr[left].length()!=0){
				mid = left;
				break;
			}
			left--;
			right++;
		}	
	}	
	
	if(arr[mid]==value){
		return mid;
	}
	
	if(arr[mid]<value){
		return binarySearchSpaceString(arr, value, start, mid-1);
	}else{
		return binarySearchSpaceString(arr, value, mid+1, end);
	}
}
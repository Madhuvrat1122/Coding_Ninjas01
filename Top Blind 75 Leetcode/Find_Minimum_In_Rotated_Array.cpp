//Problem:- https://www.naukri.com/code360/problems/rotated-array_1093219?leftPanelTabValue=PROBLEM
// Approach:- Binary Search
int findMin(vector<int>& arr)
{
	// find pivot
	int left = 0, right = arr.size()-1;
	int pivot = -1;
	while(left < right){
		int mid = (left+right)/2;
		if(arr[mid] > arr[mid+1]){
			pivot = mid;
			break;
		}
		else if(arr[0] < arr[mid]){
			left = mid+1;
		}
		else {
			right = mid;
		}
	}

	return arr[pivot+1];
}

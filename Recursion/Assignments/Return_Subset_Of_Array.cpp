// Problem statement
// Given an integer array (of length n), find and return all the subsets of input array.

// NOTE- Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

// Note :
// The order of subsets are not important.


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input:
// 3
// 15 20 12
// Sample Output:
// [] (this just represents an empty array, don't worry about the square brackets)
// 12 
// 20 
// 20 12 
// 15 
// 15 12 
// 15 20 
// 15 20 12 

#include <iostream>
using namespace std;
int array_subsets(int input[], int size, int output[][1000]){
	if(size == 0){
	    output[0][0] = 0;
	    return 1;
	}
	
	int currentEle = input[0];
	int smallSubsetSize = array_subsets(input+1, size-1, output);
	for(int i=0; i<smallSubsetSize; i++){
	    int subsetSize = output[i][0];
	    output[smallSubsetSize+i][0] = subsetSize+1;
	    output[smallSubsetSize+i][1] = input[0];
	    
	    // copy the current element
	    for(int j=1; j<=subsetSize; j++){
	        output[smallSubsetSize+i][j+1] = output[i][j];
	    }
	}
	
	return 2*smallSubsetSize;
}
int main()
{
    int input[] = {15, 20, 12};
    int output[1000][1000];
    int size = 3;
    int subsetSize = array_subsets(input, size, output);
    // print subsets
    for(int i=0; i<subsetSize; i++){
        for(int j=1; j<=output[i][0]; j++){
            cout<<output[i][j]<<" ";
        }        
        cout<<endl;
    }
    return 0;
}





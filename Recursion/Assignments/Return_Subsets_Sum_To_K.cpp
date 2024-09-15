// Problem statement
// Given an array A of size n and an integer K, return all subsets of A which sum to K.

// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.


// Note :
// The order of subsets are not important.


// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= n <= 20

// Sample Input :
// 9 
// 5 12 3 17 1 18 15 3 17 
// 6
// Sample Output :
// 3 3
// 5 1
#include <iostream>
using namespace std;
void subsetSumToKHelper(int input[], int n, int k, int output[][1000], int temp[], int tempIdx, int &rowIndex, int index){
    // Base Case: if sum becomes zero
    if(k==0){
        output[rowIndex][0] = tempIdx;
        for(int i=0; i<tempIdx; i++){
            output[rowIndex][i+1] = temp[i];
        }
        rowIndex++;
        return;
    }
    // no element left in input array
    if(n == index){
        return;
    }
    
    // exlcude the current element
    subsetSumToKHelper(input, n, k, output, temp, tempIdx, rowIndex, index+1);
    
    // include the current element
    if(k-input[index] >= 0){
        temp[tempIdx] = input[index];
        subsetSumToKHelper(input, n, k-input[index], output, temp, tempIdx+1, rowIndex, index+1);
    }
}
int subsetSumToK(int input[], int n, int output[][1000], int k) {
	int temp[1000]; // to store the current subset
	int tempIdx = 0; // to keep track of input size
	int rowIndex = 0; // to keep track of output row
	int index = 0; // to keep track of input index
	subsetSumToKHelper(input, n, k, output, temp, tempIdx, rowIndex, index);
	return rowIndex;
}
int main()
{
    int input[] = {5, 12, 3, 17, 1, 18, 15, 3, 17};
    int output[1000][1000];
    int size = 9, k = 6;
    int subsetSize = subsetSumToK(input, size, output, k);
    // print subsets
    for(int i=0; i<subsetSize; i++){
        for(int j=1; j<=output[i][0]; j++){
            cout<<output[i][j]<<" ";
        }        
        cout<<endl;
    }
    return 0;
}







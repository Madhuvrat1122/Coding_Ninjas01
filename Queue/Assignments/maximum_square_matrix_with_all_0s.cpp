// Solution Video:- https://www.youtube.com/watch?v=auS1fynpnjo
// Problem statement
// Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.

// Detailed explanation ( Input/output format, Notes, Images )
//  Constraints :
// 0 <= N <= 10^4
// 0 <= M <= 10^4

// Time Limit: 1 sec
// Sample Input 1:
// 3 3
// 1 1 0
// 1 1 1
// 1 1 1
// Sample Output 1:
// 1
// Sample Input 2:
// 4 4
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// Sample Output 2:
// 4
int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	int**dp = new int*[n];
	for(int i=0; i<n; i++){
		dp[i] = new int[m];
	}


    int maxSquareSize = 0;  // To store the size of the largest square
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j] == 0){
				// for first row and first column 
				if(i==0 || j==0){
					dp[i][j] = 1;
				}
				else {
					// Take the minimum of top, left, and top-left neighbors + 1
					int area = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
					dp[i][j] = area;
				}
				// Track the maximum square size
                maxSquareSize = max(maxSquareSize, dp[i][j]);
			}
			else {
				dp[i][j] = 0;
			}
		}
	}

	return maxSquareSize;
}

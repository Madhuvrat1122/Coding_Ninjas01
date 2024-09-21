// Problem statement
// An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).

// From a cell (i, j), you can move in three directions:

// 1. ((i + 1),  j) which is, "down"
// 2. (i, (j + 1)) which is, "to the right"
// 3. ((i+1), (j+1)) which is, "to the diagonal"
// The cost of a path is defined as the sum of each cell's values through which the route passes.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= M <= 10 ^ 2
// 1 <= N <=  10 ^ 2

// Time Limit: 1 sec
// Sample Input 1 :
// 3 4
// 3 4 1 2
// 2 1 8 9
// 4 7 8 1
// Sample Output 1 :
// 13
// Sample Input 2 :
// 3 4
// 10 6 9 0
// -23 8 9 90
// -200 0 89 200
// Sample Output 2 :
// 76
// Sample Input 3 :
// 5 6
// 9 6 0 12 90 1
// 2 7 8 5 78 6
// 1 6 0 5 10 -4 
// 9 6 2 -10 7 4
// 10 -2 0 5 5 7
// Sample Output 3 :
// 18

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
// Brute Force Approach - T.C => 3^n
int minCostPathHelper(int **input, int m, int n, int i, int j){
	// base case
	if(i == m-1 && j == n-1) {
		return input[i][j];
	}

	int x = INT_MAX;
	if(i+1 <= m-1 && j <= n-1){
		x = minCostPathHelper(input, m, n, i+1, j); // down
	}
	int y = INT_MAX;
	if(i <= m-1 && j+1 <= n-1){
		y = minCostPathHelper(input, m, n, i, j+1); // right
	}	
	int z = INT_MAX;
	if(i+1 <= m-1 && j+1 <= n-1){
		 z = minCostPathHelper(input, m, n, i+1, j+1); // daigonal
	}

	int finalAns = min(x, min(y, z)) + input[i][j];
	return finalAns;
}
int minCostPathV1(int **input, int m, int n)
{
    return minCostPathHelper(input, m, n, 0, 0);
}
// Memoization Approach - T.C => O(m*n)
int minCostPathV2(int **input, int m, int n, int **dp, int i, int j){
   	if(i == m-1 && j == n-1) {
		return input[i][j];
	}
	
	if(dp[i][j] != -1) return dp[i][j];

	int x = INT_MAX;
	if(i+1 <= m-1 && j <= n-1){
		x = minCostPathV2(input, m, n, dp, i+1, j); // down
	}
	int y = INT_MAX;
	if(i <= m-1 && j+1 <= n-1){
		y = minCostPathV2(input, m, n, dp, i, j+1); // right
	}	
	int z = INT_MAX;
	if(i+1 <= m-1 && j+1 <= n-1){
		 z = minCostPathV2(input, m, n, dp, i+1, j+1); // daigonal
	}

	int finalAns = min(x, min(y, z)) + input[i][j];
	dp[i][j] = finalAns;
	return finalAns;
}
// Dynamic Programming (Tabulation Method) - T.c => O(m*n)
int minCostPathV3(int **input, int m, int n)
{
    int **dp;
    dp = new int *[m];
    for(int i=0; i<m; i++){
       dp[i] = new int[n]; 
    }
    //fill last cell
    dp[m-1][n-1] = input[m-1][n-1];
    //fill last row (right -> left)
    for(int j=n-2; j>=0; j--){
        dp[m-1][j] = dp[m-1][j+1]+input[m-1][j];
    }
    // fill last column(down to top)
    for(int i=m-2; i>=0; i--){
        dp[i][n-1] = dp[i+1][n-1]+input[i][n-1];
    }
    // fill remaining cells
    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            dp[i][j] = input[i][j]+min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1]));
        }
    }
    
    return dp[0][0];
}
int main()
{
    int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
    
    // Brute Force Calling
    cout<<"Brute Force Output:- "<<minCostPathV1(arr, n, m)<<endl;
    
    // Memoization Approach Calling
    int **dp;
    dp =  new int *[n];
    for (int i = 0; i < n; i++)
	{
		dp[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dp[i][j] = -1;
		}
	}
    cout<<"Memoization Approach Output:- "<<minCostPathV2(arr, n, m, dp, 0, 0)<<endl;
    
    // Free dp memory from Memoization
    for (int i = 0; i < m; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    
    // Tabulation Approach (DP)
    cout<<"Tabulation Method:- "<<minCostPathV3(arr, n, m)<<endl;

    return 0;
}

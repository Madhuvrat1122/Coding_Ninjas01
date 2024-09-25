// Scenario:- Partition DP Pattern
// Problem statement
// Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.

// You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 3
// 10 15 20 25
// Sample Output 1:
// 8000
// Sample Output Explanation:
// There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
// If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
// If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
// Thus minimum number of multiplications required are 8000. 

#include <iostream>
#include <climits>
#include <vector>
using namespace std;
// solution video:- 
// using Recursive and memoization :- https://www.youtube.com/watch?v=vRVfmbCFW7Y&t=2528s
// using dp :- https://www.youtube.com/watch?v=pDCXsbAw5Cg
// 1. Recursive Approach
int matrixChainMultiplication_1(int arr[], int i, int j) {
    // Base case
    if(i==j) return 0;
    int miniStep = INT_MAX;
    for(int k=i; k<j; k++){
        int steps = ( arr[i-1]*arr[k]*arr[j] ) + matrixChainMultiplication_1(arr, i, k) + matrixChainMultiplication_1(arr, k+1, j);
        miniStep = min(miniStep, steps);
    }
    
    return miniStep;
}
// 2. memoization Approach
int matrixChainMultiplication_2(int arr[], int i, int j, vector<vector<int>> &dp){
     // Base case
    if(i==j) return 0;
    //if already exist
    if(dp[i][j] != -1) return dp[i][j];
    int miniStep = INT_MAX;
    for(int k=i; k<j; k++){
        int steps = ( arr[i-1]*arr[k]*arr[j] ) + matrixChainMultiplication_1(arr, i, k) + matrixChainMultiplication_1(arr, k+1, j);
        miniStep = min(miniStep, steps);
    }
    //store for future use
    dp[i][j] = miniStep;
    return miniStep;
}
// 3. DP Approach
int matrixChainMultiplication_3(int arr[], int n){
    vector<vector<int>> dp(n, vector<int>(n));
    //size 1 matrix will have 0 operations
    for(int i = 0; i<n; i++){
        dp[i][i] = 0;
    }
    
    for(int i=n-1; i>=1; i--){
        for(int j=i+1; j<n; j++){
            int miniStep = INT_MAX;
            for(int k=i; k<j; k++){
                int steps = ( arr[i-1]*arr[k]*arr[j] ) + dp[i][k] + dp[k+1][j];
                miniStep = min(miniStep, steps);
            }
            dp[i][j] = miniStep;
        }
    }
    return dp[1][n-1];
}
int main()
{
    int arr[] = {10, 15, 20, 25};
    int n = 4;
    
    cout<<"Recursive Approach:- "<<matrixChainMultiplication_1(arr, 1, n-1)<<endl;
    
    vector<vector<int>> dp(n , vector<int>(n, -1));
    cout<<"memoization Approach:- "<<matrixChainMultiplication_2(arr, 1, n-1, dp)<<endl;
    
    cout<<"DP Approach:- "<<matrixChainMultiplication_3(arr, n)<<endl;
    
    return 0;
}

// Problem statement
// A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.

// Note
// Space complexity should be O(W).
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints
// 1 <= N <= 10^4
// 1<= wi <= 100
// 1 <= vi <= 100
// Time Limit: 1 second
// Sample Input 1 :
// 4
// 1 2 4 5
// 5 4 8 6
// 5
// Sample Output 1 :
// 13
#include <iostream>
#include <string>
using namespace std;
// Recursive Approach (T.c = 2^n)
int knapsack_1(int *weights, int *values, int n, int maxWeight)
{
	// Base case
	if(n==0 || maxWeight==0){
	    return 0;
	}
	
	// if current element weights is greater then maxWeight
	if(weights[0] > maxWeight){
	    return knapsack_1(weights+1, values+1, n-1, maxWeight);
	}
	
	//Recursive calls
	int x = knapsack_1(weights+1, values+1, n-1, maxWeight-weights[0]) + values[0]; // taking the first weight
	int y = knapsack_1(weights+1, values+1, n-1, maxWeight); // skip the first weight
	return max(x, y);
}
// Memoization Approach (T.C = O(maxWeight*n))
int knapsack_2(int *weights, int *values, int n, int maxWeight, int **dp) {
   // Base case
	if(n==0 || maxWeight==0){
	    return 0;
	}
	
	// if already exist
	if(dp[n][maxWeight] != -1) return dp[n][maxWeight];
	
	// if current element weights is greater then maxWeight
	if(weights[0] > maxWeight){
	    return knapsack_2(weights+1, values+1, n-1, maxWeight, dp);
	}
	
	//Recursive calls
	int x = knapsack_2(weights+1, values+1, n-1, maxWeight-weights[0], dp) + values[0]; // taking the first weight
	int y = knapsack_2(weights+1, values+1, n-1, maxWeight, dp); // skip the first weight
	int ans = max(x,y);
	// store in dp for future use
	dp[n][maxWeight] = ans;
	return ans; 
}
// DP Approach (T.C = O(maxWeight*n))
int knapsack_3(int *weights, int *values, int n, int maxWeight) {
    int **dp = new int *[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = new int[maxWeight+1];
    }
    
    //fill first row: no items, capacity can be anything, value is 0
    for(int j=0; j<=maxWeight; j++){
        dp[0][j] = 0;
    }
    
    //fill first column: capacity is 0, no matter the number of items, value is 0
    for(int i=0; i<=n; i++){
        dp[i][0] = 0;
    }
    
    //fill the remaining cells
    for(int i=1; i<=n; i++){
        for(int j=1; j<=maxWeight; j++){
            int maxValWithoutCurr = dp[i - 1][j]; // Value without taking the current item
            int maxValWithCurr = 0; // Initialize to 0 in case we can't take the current item

            int weightOfCurr = weights[i - 1]; // i-1 because 'i' is 1-indexed for dp
            if (j >= weightOfCurr) { // Can we fit this item in the knapsack?
                maxValWithCurr = values[i - 1]; // The value of the current item
                int remainingCapacity = j - weightOfCurr; // Remaining capacity after taking the current item
                maxValWithCurr += dp[i - 1][remainingCapacity]; // Add value of the remaining capacity
            }
            
            dp[i][j] = std::max(maxValWithoutCurr, maxValWithCurr); // Choose the best of both options
        }
    }

    int result = dp[n][maxWeight];
    
    // Deallocate the memory to avoid memory leaks
    for(int i=0; i<=n; i++){
        delete[] dp[i];
    }
    delete[] dp;
    
    return result;
}

int main()
{
    int n = 4;
	int *weights = new int[n];
	int *values = new int[n];
    // Using a loop to initialize
    int tempWeights[] = {9, 8, 1, 9};
    int tempValues[] = {6, 10, 8, 8};
    
    for(int i = 0; i < n; i++) {
        weights[i] = tempWeights[i];
        values[i] = tempValues[i];
    }
    int maxWeight = 16;

    cout<<"Recursive Approach:- "<<knapsack_1(weights, values, n, maxWeight)<<endl;
    
    int **dp = new int *[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = new int[maxWeight+1];
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=maxWeight; j++){
            dp[i][j] = -1;
        }
    }
    cout<<"Memoization Approach:- "<<knapsack_2(weights, values, n, maxWeight, dp)<<endl;
    
    cout<<"DP Approach:- "<<knapsack_3(weights, values, n, maxWeight)<<endl;
    
    return 0;
}

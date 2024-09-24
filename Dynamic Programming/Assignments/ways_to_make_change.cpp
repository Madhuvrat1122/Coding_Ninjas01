// Problem statement
// For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.

// Return 0 if the change isn't possible.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 3
// 1 2 3
// 4
// Sample Output 1 :
// 4
// Explanation to Sample Input 1 :
// Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
// Sample Input 2 :
// 6
// 1 2 3 4 5 6
// 250
// Sample Output 2 :
// 13868903
#include <iostream>
using namespace std;
// Recursive Approach
int countWaysToMakeChange(int denominations[], int numDenominations, int value, int currentIndex){
	//Base case
	if(currentIndex < 0){
	    return 0;
	}
	if(value == 0){
	    return 1;
	}
	
	int canTake = 0;
	if(denominations[currentIndex] <= value){
	    canTake = countWaysToMakeChange(denominations, numDenominations, value-denominations[currentIndex], currentIndex);
	}
	int notTake = countWaysToMakeChange(denominations, numDenominations, value, currentIndex-1);
	
	return canTake + notTake;
}
// Memoization Approach
int countWaysToMakeChangeMem(int denominations[], int numDenominations, int value, int currentIndex, int **dp){
    //Base case
	if(currentIndex < 0){
	    return 0;
	}
	if(value == 0){
	    return 1;
	}
	// if already exist
	if(dp[currentIndex][value] != -1){
	    return dp[currentIndex][value];
	}
	
	int canTake = 0;
	if(denominations[currentIndex] <= value){
	    canTake = countWaysToMakeChangeMem(denominations, numDenominations, value-denominations[currentIndex], currentIndex, dp);
	}
	int notTake = countWaysToMakeChangeMem(denominations, numDenominations, value, currentIndex-1, dp);
	//store it for future use
	int ans = notTake + canTake;
	dp[currentIndex][value] = ans;
	return ans;
}
// DP Approach
int countWaysToMakeChangeDP(int denominations[], int numDenominations, int value){
    int **dp = new int *[numDenominations+1];
    for(int i=0; i<=numDenominations; i++){
        dp[i] = new int[value+1];
    }
    // fill first row
    for(int j=0; j<=value; j++){
        dp[0][j] = 0;
    }
    //fill first column
    for(int i=0; i<=numDenominations; i++){
        dp[i][0] = 1;
    }
    
    for(int i=1; i<=numDenominations; i++){
        for(int j=1; j<=value; j++){
            if(denominations[i-1] <= j){
                int coinValue = denominations[i-1];
        	    dp[i][j] = dp[i][j-coinValue]; // can take
        	}
        	dp[i][j] += dp[i-1][j]; // not take
        }
    }
    
    return dp[numDenominations][value];
}
int main()
{
    int denominations[] = {1,2,3,4,5,6};
    int numDenominations = 6;
    int value = 300;
    
    // cout<<"Recursive Approach:- "<<countWaysToMakeChange(denominations, numDenominations, value, numDenominations-1)<<endl;
    
    int **dp = new int *[numDenominations+1];
    for(int i=0; i<=numDenominations; i++){
        dp[i] = new int[value+1];
    }
    for(int i=0; i<=numDenominations; i++){
        for(int j=0; j<=value; j++){
            dp[i][j] = -1;
        }
    }
    cout<<"Memoization Approach:- "<<countWaysToMakeChangeMem(denominations, numDenominations, value, numDenominations-1, dp)<<endl;
    
    cout<<"DP Approach:- "<<countWaysToMakeChangeDP(denominations, numDenominations, value)<<endl;
    
    return 0;
}

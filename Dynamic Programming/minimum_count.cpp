// Problem statement
// Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.

// That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= n <= 10 ^ 4

// Time Limit: 1 sec
// Sample Input 1 :
// 12
// Sample Output 1 :
// 3
// Explanation of Sample Output 1 :
// 12 can be represented as : 
// A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

// B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

// C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

// D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

// As we can see, the output should be 3.
// Sample Input 2 :
// 9
// Sample Output 2 :
// 1

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
// Brute Force Approach - T.C => 3^n
int minCountV1(int n)
{
    // Base Case
	if(n<=0){
        return 0;
    }
    
    int minOps = INT_MAX;
    for(int i=1; i<= sqrt(n); i++){
        int curr = minCountV1(n-pow(i,2)) + 1;
        minOps = min(curr, minOps);
    }
    
    return minOps;
}
// Memoization Approach - T.C => O(n)
int minCountV2(int n, int *dp){
     // Base Case
	if(n<=0){
        return 0;
    }
    
    if(dp[n] != -1){
        return dp[n];
    }
    
    int minOps = INT_MAX;
    for(int i=1; i<= sqrt(n); i++){
        int curr = minCountV1(n-pow(i,2)) + 1;
        minOps = min(curr, minOps);
    }
    dp[n] = minOps;
    
    return minOps;
}
// Dynamic Programming (Tabulation Method) - T.c => O(n)
int minCountV3(int n)
{
    int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        dp[i] = INT_MAX;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j*j<=i; j++){
            dp[i] = min(dp[i], dp[i-(j*j)]+1);   
        }
    }
    
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    
    // Brute Force Calling
    cout<<"Brute Force Output:- "<<minCountV1(n)<<endl;
    
    // Memoization Approach Calling
    int *dp =  new int[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = -1;
    }
    cout<<"Memoization Approach Output:- "<<minCountV2(n, dp)<<endl;
    
    // Tabulation Approach (DP)
    cout<<"Tabulation Method:- "<<minCountV3(n)<<endl;

    return 0;
}

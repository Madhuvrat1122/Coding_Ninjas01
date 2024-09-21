// Problem statement
// Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.

// This number can be huge, so, return output modulus 10^9 + 7.

// Time complexity should be O(h).

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= h <= 10^6
// Time Limit: 1 sec
// Sample Input 1:
// 3
// Sample Output 1:
// 15
// Sample Input 2:
// 4
// Sample Output 2:
// 315
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
// Brute Force Approach - T.C => 2^n
int balancedBTs(int h)
{
    // Base Case
	if(h<=1){
        return 1;
    }
    const int mod = 1e9+7;
    int x = balancedBTs(h-1);
    int y = balancedBTs(h-2);
    int temp1 = (int)(((long)(x)*x)%mod);
    int temp2 = (int)(((2*(long)(x)*y))%mod);
    
    return (temp1+temp2)%mod;
}
// Memoization Approach - T.C => O(n)
int balancedBTsV2(int h, int *dp){
    // Base Case
	if(h<=1){
        return 1;
    }
    if(dp[h] != -1) return dp[h];
    const int mod = 1e9+7;
    int x = balancedBTs(h-1);
    int y = balancedBTs(h-2);
    int temp1 = (int)(((long)(x)*x)%mod);
    int temp2 = (int)(((2*(long)(x)*y))%mod);
    dp[h] = (temp1+temp2)%mod;
    return dp[h];
}
// // Dynamic Programming (Tabulation Method) - T.c => O(n)
int balancedBTsV3(int h)
{
    int dp[h+1];
    const int mod = 1e9+7;
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=h; i++){
        dp[i] = (int)(((long)(dp[i-1])*dp[i-1])%mod) + (int)((2*(long)(dp[i-1])*dp[i-2])%mod);
    }
    
    return dp[h]%mod;
}
int main()
{
    int h;
    cin>>h;
    
    // Brute Force Calling
    cout<<"Brute Force Output:- "<<balancedBTs(h)<<endl;
    
    // Memoization Approach Calling
    int *dp =  new int[h+1];
    for(int i=0; i<=h; i++){
        dp[i] = -1;
    }
    cout<<"Memoization Approach Output:- "<<balancedBTsV2(h, dp)<<endl;
    
    // Tabulation Approach (DP)
    cout<<"Tabulation Method:- "<<balancedBTsV3(h)<<endl;

    return 0;
}

// Problem statement
// A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= n <= 10 ^ 4

// Time Limit: 1 sec
// Sample Input 1 :
// 6
// 5 5 10 100 10 5
// Sample Output 1 :
// 110
// Sample Input 2 :
// 6
// 10 2 30 20 3 50
// Sample Output 2 :
// 90
// Explanation of Sample Output 2 :
// Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
#include <iostream>
#include <climits>
using namespace std;
// Recursive Approach
int maxMoneyLooted_1(int *arr, int n, int currentIndex)
{
    if(currentIndex >= n){
        return 0;
    }
    
    int include = arr[currentIndex] + maxMoneyLooted_1(arr, n, currentIndex + 2);
    int exclude = maxMoneyLooted_1(arr, n, currentIndex+1); 
    
    return max(include, exclude);
    
}
// Memoization Approach
int maxMoneyLooted_2(int *arr, int n, int currentIndex, int *dp){
    if(currentIndex >= n){
        return 0;
    }
    // if already exist
    if(dp[currentIndex] != -1) return dp[currentIndex];
    
    int include = arr[currentIndex] + maxMoneyLooted_1(arr, n, currentIndex + 2);
    int exclude = maxMoneyLooted_1(arr, n, currentIndex+1); 
    
    int ans = max(include, exclude);
    // store it for future use
    dp[currentIndex] = ans;
    return ans;
}
// Dynamic Programming Approach
int maxMoneyLooted_3(int *arr, int n){
    int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] = arr[0];
    for(int i=2; i<=n; i++){
        int include = arr[i-1] + dp[i-2];
        int exclude = dp[i-1];
        dp[i] = max(include, exclude);
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cout<<"Recursive Approach:- "<<maxMoneyLooted_1(arr, n, 0)<<endl;
    
    int *dp = new int[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = -1;
    }
    cout<<"Momoization Approach:- "<<maxMoneyLooted_2(arr, n, 0, dp)<<endl;
    
    cout<<"DP Approach:- "<<maxMoneyLooted_3(arr, n)<<endl;
    
    return 0;
}

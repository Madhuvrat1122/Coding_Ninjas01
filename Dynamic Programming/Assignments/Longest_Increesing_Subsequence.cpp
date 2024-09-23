// Problem statement
// Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints
// 1 <= N <= 10^3
// Time Limit: 1 second
// Sample Input 1 :
// 6
// 5 4 11 1 16 8
// Sample Output 1 :
// 3
// Sample Output Explanation
// Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
// Sample Input 2 :
// 3
// 1 2 2
// Sample Output 2 :
// 2
#include <iostream>
#include <climits>
using namespace std;
// Recursive Approach
int longestIncreasingSubsequence_1(int* arr, int n, int maxSoFar, int currentIndex) {
    if(currentIndex >= n){
        return 0;
    }
    
    // we will include only if the current element is greater then last element taken
    int include = INT_MIN, exclude = INT_MIN;
    if(arr[currentIndex] > maxSoFar){
        include = 1 + longestIncreasingSubsequence_1(arr, n, arr[currentIndex], currentIndex+1);
    }
    exclude = longestIncreasingSubsequence_1(arr, n, maxSoFar, currentIndex+1);
    return max(include, exclude);
}
// Memoization Approach
int longestIncreasingSubsequence_2(int *arr, int n, int maxSoFar, int currentIndex, int *dp){
    if(currentIndex >= n){
        return 0;
    }
    
    // if already exist
    if(dp[currentIndex] != -1) return dp[currentIndex];
    // we will include only if the current element is greater then last element taken
    int include = INT_MIN, exclude = INT_MIN;
    if(arr[currentIndex] > maxSoFar){
        include = 1 + longestIncreasingSubsequence_1(arr, n, arr[currentIndex], currentIndex+1);
    }
    exclude = longestIncreasingSubsequence_1(arr, n, maxSoFar, currentIndex+1);
    
    int ans = max(include, exclude);
    // store it in dp for future use
    dp[currentIndex] = ans;
    return ans;
}
// DP Approach
int longestIncreasingSubsequence_3(int *arr, int n){
    int *dp = new int[n];
    for(int i=0; i<n; i++){
        dp[i] = 1; // because each element is lis by itself
    }
    
     int maxLength = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
           if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }
    return maxLength;
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int maxSoFar = INT_MIN;
    int currentIndex = 0;
    cout<<"Recursive Approach:- "<<longestIncreasingSubsequence_1(arr, n, maxSoFar, 0)<<endl;
    
    int *dp = new int[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = -1;
    }
    cout<<"Momoization Approach:- "<<longestIncreasingSubsequence_2(arr, n, maxSoFar, 0, dp)<<endl;
    
    cout<<"DP Approach:- "<<longestIncreasingSubsequence_3(arr, n)<<endl;
    
    return 0;
}

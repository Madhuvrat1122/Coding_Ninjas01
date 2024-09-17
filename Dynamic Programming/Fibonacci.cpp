#include <iostream>
using namespace std;
// Recursive Appraoch T.c = O(2^n)
int fibo_recursive(int n){
    if(n <= 1) return n;
    int a = fibo_recursive(n-1);
    int b = fibo_recursive(n-2);
    return a+b;
}
// Memoization (Top-Down) Appraoch T.c = O(n)
int fibo_1_helper(int n, int *dp){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    int a = fibo_1_helper(n-1, dp);
    int b = fibo_1_helper(n-2, dp);
    dp[n] = a+b;
    return dp[n];
}
int fibo_1(int n){
    int *dp = new int[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = -1;
    }
    return fibo_1_helper(n, dp);
}
// Dynamic Programming (bottom-up Appraoch) T.C = O(n)
int fibo_2(int n){
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    
    cout<<"Appraoch 1:- "<<fibo_recursive(n)<<endl; // Recursive Appraoch
    
    cout<<"Appraoch 2:- "<<fibo_1(n)<<endl; // Memoization Appraoch
    
    cout<<"Appraoch 3:- "<<fibo_2(n)<<endl; // Dynamic Programming Appraoch

    return 0;
}

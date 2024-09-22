// Input: 
// S = "xyz", T = "axby"
// Output: 2
#include <iostream>
#include <string>
using namespace std;
// Recursive Approach (T.c = 2^n)
int lcs_1(string a, string b){
    if(a.empty() || b.empty()){
        return 0;
    }
    // if first charactor matched
    if(a[0] == b[0]){
        return 1+lcs_1(a.substr(1), b.substr(1));
    }
    else {
        // skip the first charactor of a
        int first = lcs_1(a.substr(1), b);
        // skip the first charactor of b
        int second = lcs_1(a, b.substr(1));
        // skip the first charactor for both a and b
        // int third = lcs_1(a.substr(1), b.substr(1));
        return max(first, second);
    }
}
// Memoization Approach (T.c = O(mn))
int lcs_2(string a, string b, int **dp){
    int m = a.size();
    int n = b.size();
    if(a.empty() || b.empty()){
        return 0;
    }
    
    // if already exist
    if(dp[m][n] != -1) return dp[m][n];
    
    int ans;
    // if first charactor matched
    if(a[0] == b[0]){
        ans = 1+lcs_1(a.substr(1), b.substr(1));
    }
    
    else {
        // skip the first charactor of a
        int first = lcs_1(a.substr(1), b);
        // skip the first charactor of b
        int second = lcs_1(a, b.substr(1));
        // skip the first charactor for both a and b
        // int third = lcs_1(a.substr(1), b.substr(1));
        ans = max(first, second);
    }
    dp[m][n] = ans;
    return ans;
}
// DP Approach
int lcs_3(string a, string b){
    int m = a.size();
    int n = b.size();
    int **dp;
    dp = new int*[m+1];
    for(int i=0; i<=m; i++){
        dp[i] = new int[n+1];
    }
    
    // fill the first row 
    for(int j=0; j<=n; j++){
        dp[0][j] = 0;
    }
    
    // fill the first column
    for(int i=1; i<=m; i++){
        dp[i][0] = 0;
    }
    
    // fill the remaining cells
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            // if first charactor matched
            if(a[m-i] == b[n-j]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }
    
    return dp[m][n];
}
int main()
{
    string a = "xyz";
    string b = "axbycz";
    cout<<"Recursive Approach:- "<<lcs_1(a,b)<<endl;
    
    int **dp;
    dp = new int *[a.size()+1];
    for(int i=0; i<a.size()+1; i++){
        dp[i] = new int[b.size()+1];
    }
    for(int i=0; i<a.size()+1; i++){
        for(int j=0; j<b.size()+1; j++){
            dp[i][j] = -1;
        }
    }
    cout<<"Memoization Approach:- "<<lcs_2(a,b, dp)<<endl;
    
    cout<<"DP Approach:- "<<lcs_3(a,b)<<endl;
    return 0;
}

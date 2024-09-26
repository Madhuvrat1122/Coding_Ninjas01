// *********************Din't understood completely may be will try later*******************************
// Problem statement
// Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.

// Note: The input data will be such that there will always be a solution.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= |S| <= 1000 (|x| implies the length of the string x)
// 1 <= |V| <= 1000 
// Time Limit: 1 second
// Sample Input 1:
// babab
// babba
// Sample Output 1:
// 3
// Explanation:
// "aab" is the shortest subsequence which is present in S and absent in V.

#include <iostream>
#include <string>
#include <climits>
#include <vector>
using namespace std;
// Recursive Approach
int solve_1(string s, string v, int startIndex_S = 0, int startIndex_V = 0){
    // if at last of s or s is empty
    if(startIndex_S == s.size()) return 1001;
    // if at lasr of v or v is empty it means we can take whole string s as part subsequence which is not preset in v
    if(startIndex_V == v.size()) return 1; // bacuse we need smallest
    
    int exclude = solve_1(s, v, startIndex_S+1, startIndex_V);
    
    // in include we could have two scenarios.
    // find out the index of current char of s in j
    int k = -1;
    for(int i=startIndex_V; i<v.size(); i++){
        if(s[startIndex_S] == v[i]){
            k = i;
            break;
        }
    }
    
    //now current element is not at all present in v then we can consider current element is smallest subsequence not present in v
    if(k == -1) return 1;
    int include = 1 + solve_1(s, v, startIndex_S+1, k+1); // else start looking after current element index in v
    return min(include, exclude);
}
// Memoization Approach
int solve_2(string s, string v, int startIndex_S, int startIndex_V, int **dp){
    // if at last of s or s is empty
    if(startIndex_S == s.size()) return 1001;
    // if at lasr of v or v is empty it means we can take whole string s as part subsequence which is not preset in v
    if(startIndex_V == v.size()) return 1; // bacuse we need smallest
    
    // if already exist
    if(dp[startIndex_S][startIndex_V] != -1) return dp[startIndex_S][startIndex_V];
    int exclude = solve_2(s, v, startIndex_S+1, startIndex_V, dp);
    
    // in include we could have two scenarios.
    // find out the index of current char of s in j
    int k = -1;
    for(int i=startIndex_V; i<v.size(); i++){
        if(s[startIndex_S] == v[i]){
            k = i;
            break;
        }
    }
    
    //now current element is not at all present in v then we can consider current element is smallest subsequence not present in v
    if(k == -1) return 1;
    int include = 1 + solve_2(s, v, startIndex_S+1, k+1, dp); // else start looking after current element index in v
    int ans = min(include, exclude);
    dp[startIndex_S][startIndex_V] = ans;
    return ans;
}
// DP Approach
int solve_3(string S, string V) {
    int n = S.length();
    int m = V.length();

    // Create dp table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base case when V is empty
    // If V is empty, the shortest subsequence in S[0...i] that isn't in V is always 1 (any single character of S)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Base case when S is empty
    // If S is empty, there can't be a subsequence, so set to "infinity" (no solution)
    for (int j = 1; j <= m; j++) {
        dp[0][j] = INT_MAX;
    }

    // Fill dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // Exclude S[i-1] and look at dp[i-1][j]
            dp[i][j] = dp[i-1][j];

            // Find the first occurrence of S[i-1] in V[0...j-1]
            int k = j - 1;
            while (k >= 0 && V[k] != S[i-1]) {
                k--;
            }

            // If S[i-1] is not found in V[0...j-1], the shortest subsequence is 1 (i.e., S[i-1] itself)
            if (k == -1) {
                dp[i][j] = 1;
            } else {
                // Include S[i-1] and add the result of dp[i-1][k]
                if (dp[i-1][k] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + 1);
                }
            }
        }
    }

    // The result is the length of the shortest subsequence that isn't a subsequence in V
    return dp[n][m] == INT_MAX ? -1 : dp[n][m];
}
int main()
{
    string s = "babab";
    string v = "babba";
    
    cout<<"Recursive Approach:- "<<solve_1(s,v)<<endl;
    
    int **dp = new int*[s.size()];
    for(int i=0; i<s.size(); i++){
        dp[i] = new int[v.size()];
    }
    
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<v.size(); j++){
            dp[i][j] = -1;
        }
    }
    cout<<"Memoization Approach:- "<<solve_2(s, v, 0 , 0, dp)<<endl;
    
     cout<<"DP Approach:- "<<solve_3(s, v);

    return 0;
}

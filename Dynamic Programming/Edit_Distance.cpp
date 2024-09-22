// Problem statement
// You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.

// Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:

// 1. Delete a character
// 2. Replace a character with another one
// 3. Insert a character
// Note :
// Strings don't contain spaces in between.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= M <= 10 ^ 3
// 0 <= N <= 10 ^ 3

// Time Limit: 1 sec
// Sample Input 1 :
// abc
// dc
// Sample Output 1 :
// 2
//  Explanation to the Sample Input 1 :
//  In 2 operations we can make string T to look like string S.
// First, insert character 'a' to string T, which makes it "adc".

// And secondly, replace the character 'd' of string T with 'b' from the string S. This would make string T as "abc" which is also string S. 

// Hence, the minimum distance.
// Sample Input 2 :
// whgtdwhgtdg
// aswcfg
// Sample Output 2 :
// 9

#include <iostream>
#include <string>
using namespace std;
// Recursive Approach (T.c = 3^n)
int editDistance_1(string s1, string s2) {
   	// Base case 
   	// If Any One string is empty then steps required will be equal to the length of non-empty string
    if(s1.empty() || s2.empty()){
        return max(s1.size(), s2.size());
    }
    // if first charactor matches
    if(s1[0] == s2[0]){
        return editDistance_1(s1.substr(1), s2.substr(1));
    }
    else {
        int x = editDistance_1(s1.substr(1), s2) + 1; // insert a charactor
        int y = editDistance_1(s1, s2.substr(1)) + 1; // delete a charactor
        int z = editDistance_1(s1.substr(1), s2.substr(1))  + 1; // replace a charactor
        return min(x, min(y,z));
    }
}
// Memoization Approach (T.C = O(MN))
int editDistance_2(string s1, string s2, int **dp){
    int m = s1.size();
    int n = s2.size();
    // Base case 
   	// If Any One string is empty then steps required will be equal to the length of non-empty string
    if(s1.empty() || s2.empty()){
        return max(s1.size(), s2.size());
    }
    
    // if aleady exist
    if(dp[m][n] != -1){
        return dp[m][n];
    }
    
    int ans;
    // if first charactor matches
    if(s1[0] == s2[0]){
        ans = editDistance_2(s1.substr(1), s2.substr(1), dp);
    }
    else {
        int x = editDistance_2(s1.substr(1), s2, dp) + 1; // insert a charactor
        int y = editDistance_2(s1, s2.substr(1), dp) + 1; // delete a charactor
        int z = editDistance_2(s1.substr(1), s2.substr(1), dp)  + 1; // replace a charactor
        ans = min(x, min(y,z));
    }
    // save it for future use
    dp[m][n] = ans;
    return ans;
}
// DP Approach (T.C = O(MN))
int editDistance_3(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    int **dp = new int *[m+1];
    for(int i=0; i<=m; i++){
        dp[i] = new int[n+1];
    }
    
    // fill first row
    for(int j=0; j<=n; j++){
        dp[0][j] = j;
    }
    //fill first column
    for(int i=1; i<=m; i++){
        dp[i][0] = i;
    }
    //fill remaining rows
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            // if first charactor matches
            if(s1[m-i] == s2[n-j]){
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                int a = dp[i-1][j];
                int b = dp[i][j-1];
                int c = dp[i-1][j-1];
                dp[i][j] = min(a, min(b, c)) + 1;
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string a = "abc";
    string b = "dc";
    cout<<"Recursive Approach:- "<<editDistance_1(a,b)<<endl;
    
    int **dp;
    dp = new int*[a.size()+1];
    for(int i=0; i<=a.size(); i++){
        dp[i] = new int[b.size()+1];
    }
    for(int i=0; i<=a.size(); i++){
        for(int j=0; j<=b.size(); j++){
            dp[i][j] = -1;
        }
    }
    cout<<"Memoization Approach:- "<<editDistance_2(a, b, dp)<<endl;
    
    cout<<"DP Approach:- "<<editDistance_3(a, b)<<endl;
    
    return 0;
}

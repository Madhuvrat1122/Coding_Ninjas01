// Problem statement
// // Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:

// // 1.) Subtract 1 from it. (n = n - ­1) ,
// // 2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
// // 3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
// // Detailed explanation ( Input/output format, Notes, Images )
// // Constraints :
// // 1 <= n <= 10 ^ 6
// // Time Limit: 1 sec
// // Sample Input 1 :
// // 4
// // Sample Output 1 :
// // 2 
// // Explanation of Sample Output 1 :
// // For n = 4
// // Step 1 :  n = 4 / 2  = 2
// // Step 2 : n = 2 / 2  =  1 
// // Sample Input 2 :
// // 7
// // Sample Output 2 :
// // 3
// // Explanation of Sample Output 2 :
// // For n = 7
// // Step 1 :  n = 7 ­- 1 = 6
// // Step 2 : n = 6  / 3 = 2 
// // Step 3 : n = 2 / 2 = 1 

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
// Brute Force Approach - T.C => 3^n
int countMinStepsToOne(int n)
{
    // Base Case
	if(n==1){
	    return 0;
	}
	
	int a = countMinStepsToOne(n-1); // decreement by 1
	int b = INT_MAX, c = INT_MAX;
	if(n%2 == 0){
	    b = countMinStepsToOne(n/2); // divide by 2
	}
	if(n%3 == 0){
	    c = countMinStepsToOne(n/3); // divide by 3
	}
	
	int finalAns = min(a, min(b,c)) + 1; // adding 1 to consider the current step
	return finalAns;
}
// Memoization Approach - T.C => O(n)
int countMinStepsToOneV2(int n, int *dp){
    if(n == 1){
        return 0;
    }
    // If Result Already Exist In dp
    if(dp[n] != -1){
        return dp[n];
    }
    int a = countMinStepsToOneV2(n-1, dp); // decreement by 1
	int b = INT_MAX, c = INT_MAX;
	if(n%2 == 0){
	    b = countMinStepsToOneV2(n/2, dp); // divide by 2
	}
	if(n%3 == 0){
	    c = countMinStepsToOneV2(n/3, dp); // divide by 3
	}
	
	int finalAns = min(a, min(b,c)) + 1; // adding 1 to consider the current step
	dp[n] = finalAns; // store in dp for future use
	return finalAns;
    
}
// Dynamic Programming (Tabulation Method) - T.c => O(n)
int countMinStepsToOneV3(int n){
    int *dp = new int[n+1];
    dp[1] = 0; // steps required to reach to 1 is zero   
    for(int i=2; i<=n; i++){
        //substract by 1
        dp[i] = dp[i-1]+1;
        // divided by 2
        if(i%2==0){
            dp[i] = min(dp[i], dp[i/2]+1);
        }
        // divided by 3
        if(i%3==0){
            dp[i] = min(dp[i], dp[i/3]+1);
        }
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    
    // Brute Force Calling
    cout<<"Brute Force Output:- "<<countMinStepsToOne(n)<<endl;
    
    // Memoization Approach Calling
    int *dp =  new int[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = -1;
    }
    cout<<"Memoization Approach Output:- "<<countMinStepsToOneV2(n, dp)<<endl;
    
    // Tabulation Approach (DP)
    cout<<"Tabulation Method:- "<<countMinStepsToOneV3(n)<<endl;

    return 0;
}

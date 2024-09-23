// Problem statement
// Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.

// For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-

// 10 = 1^2 + 3^2 
// Hence, answer is 1.

// Note : x^y represents x raise to the power y

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= a <= 10^4
// 1 < b <= 20
// Time Limit: 1 second
// Sample Input 1 :
// 10 2
// Sample Output 1 :
// 1
// Sample Input 2 :
// 100 2
// Sample Output 2 :
// 3
// Explanation:
// Following are the three ways: 
// 1. 100 = 10^2
// 2. 100 = 8^2 + 6^2
// 3. 100 = 7^2+5^2+4^2+3^2+1^2

#include <iostream>
#include <cmath>
using namespace std;
// Recursive Approach
int getAllWays_1(int a, int b, int currentNum) {
	int power = pow(currentNum, b);
	if(power == a) return 1;
	if(power > a) return 0;
	
	return getAllWays_1(a-power, b, currentNum+1) + getAllWays_1(a, b, currentNum+1);
}
int main()
{
    int a,b;
    cin>>a>>b;
  
    cout<<"Recursive Approach:- "<<getAllWays_1(a, b, 1)<<endl;
    
    return 0;
}

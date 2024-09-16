// Problem statement
// You are given an array 'ARR' of 'N' distinct positive integers. You are also given a non-negative integer 'B'.



// Your task is to return all unique combinations in the array whose sum equals 'B'. A number can be chosen any number of times from the array 'ARR'.



// Elements in each combination must be in non-decreasing order.



// For example:
// Let the array 'ARR' be [1, 2, 3] and 'B' = 5. Then all possible valid combinations are-

// (1, 1, 1, 1, 1)
// (1, 1, 1, 2)
// (1, 1, 3)
// (1, 2, 2)
// (2, 3)
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 3 8
// 2 3 5
// Sample Output 1:
// Yes
// Explanation Of Sample Input 1 :
// All possible valid combinations are:
// 2 2 2 2
// 2 3 3
// 3 5
// Sample Input 2 :
// 3 5
// 1 2 3 
// Sample Output 2:
// Yes
// Constraints:
// 1 <= 'N' <= 15
// 1 <= 'B' <= 20
// 1 <= 'ARR[i]' <= 20

// Time Limit: 1sec

#include <iostream>
#include <vector>
using namespace std;
void combSumHelper(vector<int> &ARR, vector<vector<int>> &combinations, int current_sum, int targetSum, vector<int> &current, int index){
    if(current_sum == targetSum){
        combinations.push_back(current);
        return;
    }
    if(current_sum > targetSum){
        return;
    }
    for(int i=index; i<ARR.size(); i++){
        current.push_back(ARR[i]);
        combSumHelper(ARR, combinations, current_sum+ARR[i], targetSum, current, i);
        current.pop_back();
    }
}
vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    vector<vector<int>> combinations;
    int current_sum = 0;
    vector<int> current;
    combSumHelper(ARR, combinations, current_sum, B, current, 0);
    return combinations;
}
int main()
{
    vector<int> arr {1, 2, 3};
    int sum = 5;
    vector<vector<int>> combinations = combSum(arr, sum);
    //print combinations
    for(int i=0; i<combinations.size(); i++){
        for(int j=0; j<combinations[i].size(); j++){
            cout<<combinations[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

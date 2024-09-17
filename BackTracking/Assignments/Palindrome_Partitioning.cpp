// Problem statement
// You are given a string 'S'. Your task is to partition 'S' such that every substring of the partition is a palindrome. You need to return all possible palindrome partitioning of 'S'.

// Note: A substring is a contiguous segment of a string.

// For Example:
// For a given string “BaaB”
// 3 possible palindrome partitioning of the given string are:
// {“B”, “a”, “a”, “B”}
// {“B”, “aa”, “B”}
// {“BaaB”}
// Every substring of all the above partitions of “BaaB” is a palindrome.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= |S|<= 15
// where |S| denotes the length of string 'S'.

// Time Limit: 1 sec.
// Sample Input 1:
// aaC
// Sample Output 1:
// ["C", "a", "a"]
// ["C", "aa"]
// Explanation for input 1:
// For the given string "aaC" there are two partitions in which all substring of partition is a palindrome.
// Sample Input 2:
// BaaB
// Sample Output 2:
// ["B", "B", "a", "a"]
// ["B", "B", "aa"]
// ["BaaB"]
// Explanation for input 2:
// For the given string "BaaB", there are 3 partitions that can be made in which every substring is palindromic substrings.

#include <iostream>
#include <vector>
using namespace std;
bool isPalindrome(const string &s){
    int left = 0, right = s.length() - 1;
    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
void partitionHelper(string &s, vector<string>& partitionArr, int index, int size, vector<vector<string>> &output){
    // Base Case.
    if(index == size){
        output.push_back(partitionArr);
        return;
    }
    
    string cur_string = "";
    for(int i=index; i<size; i++){
        cur_string += s[i];
        if(isPalindrome(cur_string)){
             partitionArr.push_back(cur_string);
            partitionHelper(s, partitionArr, i+1, size, output);
            partitionArr.pop_back(); //backtrack   
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> output;
    vector<string> partitionArr;
    int index = 0;
    int size = s.length();
    partitionHelper(s, partitionArr, index, size, output);
    return output;
}
int main()
{
    string s = "BaaB";
    vector<vector<string>> output = partition(s);
    //print partitions
    for(int i=0; i<output.size(); i++){
        for(int j=0; j<output[i].size(); j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// Problem statement
// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.

// Note : The order of codes are not important. And input string does not contain 0s.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= Length of String S <= 10

// Sample Input:
// 1123
// Sample Output:
// aabc
// kbc
// alc
// aaw
// kw

#include <iostream>
using namespace std;
void getCodesHelper(string input, string curString, string output[10000], int &size) {
    if(input.empty()){
        output[size] = curString;
        size++;
        return;
    }
    
    //pick first digit from input
    int firstDigit = input[0] - '0';
    if(firstDigit >= 1 && firstDigit <= 9){
        char curChar = 'a' + firstDigit - 1;
        getCodesHelper(input.substr(1), curString + curChar, output, size);
    }
    
    // pick two digit frm input;
    int twoDigit = stoi(input.substr(0,2));
    if(twoDigit >= 10 && twoDigit <= 26){
        char curChar = 'a' + twoDigit - 1;
        getCodesHelper(input.substr(2), curString+curChar, output, size);   
    }
    
}
int getCodes(string input, string output[10000]) {
    string curString = "";
    int size = 0;
    getCodesHelper(input, curString, output, size);
    return size;
}
int main()
{
    string input = "1123";
    string output[1000];
    int len = getCodes(input, output);
    for(int i=0; i<len; i++){
        cout<<output[i]<<endl;
    }
    
    return 0;
}

// Problem statement
// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.

// Return empty string for numbers 0 and 1.

// Note :
// 1. The order of strings are not important.
// 2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= n <= 10^6

// Sample Input:
// 23
// Sample Output:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf


#include <string>
using namespace std;
string getString(int num){
    if(num == 2) {
        return "abc";
    }
    else if(num == 3){
        return "def";
    }
    else if(num == 4){
        return "ghi";
    }
    else if(num == 5){
        return "jkl";
    }
    else if(num == 6){
        return "mno";
    }
    else if(num == 7){
        return "pqrs";
    }
    else if(num == 8){
        return "tuv";
    }
    else if(num == 9){
        return "wxyz";
    }
    else {
        return "";
    }
}
int keypad(int num, string output[]){
    if(num == 0 || num == 1){
        output[0] = getString(num);
        return 1;
    }

    int currNumber = num % 10;
    string curString = getString(currNumber);
    int smallNumber = num / 10;
    int smallkeypadSize = keypad(smallNumber, output);

    // copy the combinatio got for smallNumber till curstring sice - 1
    for(int i=0; i<curString.size()-1; i++){
        for(int j=0; j<smallkeypadSize; j++){
            output[j+(i+1)*smallkeypadSize] = output[j];
        }
    }

    // append the each charactor one by one on the current output combination
    for(int i=0; i<curString.size(); i++){
        for(int j=0; j<smallkeypadSize; j++){
            output[j+i*smallkeypadSize] = output[j+i*smallkeypadSize]+curString[i];
        }
    }

    return smallkeypadSize*curString.size();

}

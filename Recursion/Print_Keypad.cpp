// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
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

#include <iostream>
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
void printKeypadHelper(int num, string output){
   if(num == 0 || num == 1){
       cout<<output<<endl;
       return;
   }

   int curNumber = num%10;
   int smallNumber = num/10;
   string curString = getString(curNumber);

   for(int i=0 ;i<curString.length(); i++){
       printKeypadHelper(smallNumber, curString[i]+output);
   }
}
void printKeypad(int num){
    string output = "";
    printKeypadHelper(num, output);

}




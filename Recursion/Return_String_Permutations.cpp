// Problem statement
// Given a string S, find and return all the possible permutations of the input string.

// Note 1 : The order of permutations is not important. Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input :
// abc
// Sample Output :
// abc
// acb
// bac
// bca
// cab
// cba

#include <iostream>
#include <string>
using namespace std;
// Approach I.
int return_permutation(string input, string output[]){
    if(input.empty()){
        output[0] = input;
        return 1;
    }
    
    char firstChar = input[0];
    string smallOutput[1000];
    int smallerOutputSize = return_permutation(input.substr(1), smallOutput);
    int k=0;
    for(int i=0; i<smallerOutputSize; i++){
        string smallerpermu = smallOutput[i];
        for(int j=0; j<=smallerpermu.length(); j++){
            output[k++] = smallerpermu.substr(0,j) + firstChar + smallerpermu.substr(j);
        }
    }
    
    return k;
}
// Approach II.
int return_permutation_1(string input, string output[]){
  if(input.empty()){
      output[0] = input;
      return 1;
  }  
  
  int k = 0;
  for(int i=0; i<input.length(); i++){
      char firstChar = input[i];
      string smallerInput = input.substr(0,i)+input.substr(i+1);
      string smallerOutput[1000];
      int smallerOutputSize = return_permutation_1(smallerInput, smallerOutput);
      for(int j=0; j<smallerOutputSize; j++){
          output[k++] = firstChar + smallerOutput[j];
      }
  }
  
  return k;
}

int main()
{
    string input;
    cin>>input;
    string output[1000];
    
    // int outputSize = return_permutation(input, output);
    int outputSize = return_permutation_1(input, output);
    //print permutation
    for(int i=0; i<outputSize; i++){
        cout<<output[i]<<endl;
    }

    return 0;
}

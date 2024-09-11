
#include <iostream>
#include <string>
using namespace std;
int subSeq(string input, string output[]){
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    string smallString = input.substr(1);
    int smallStringSize = subSeq(smallString, output);
    for(int i=0; i<smallStringSize; i++){
        output[i+smallStringSize] = input[0]+output[i];
    }
    
    return 2*smallStringSize;
}
int main()
{
    string input;
    cin>>input;
    string *output = new string[1000];
    int size = subSeq(input, output);
    for(int i=0; i<size; i++){
        cout<<output[i]<<endl;
    }

    return 0;
}

// input -> abc
// output -> "", a, b, c, ab, ac, bc, abc

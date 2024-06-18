#include <iostream>
#include "stackUsingArray.cpp"

int main()
{
    stackUsingArray stack(4);
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50); //overflow
    
    cout<<stack.pop()<<endl; // 40
    cout<<stack.pop()<<endl; //30
    
    cout<<stack.size()<<endl; //2
    
    cout<<stack.topElement()<<endl; //20
    
    cout<<stack.isEmpty(); //false => 0

    return 0;
}
#include <iostream>
#include "stackUsingArray.cpp"

int main()
{
    stackUsingArray stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50); 
    
    cout<<stack.pop()<<endl; // 50
    cout<<stack.pop()<<endl; // 40
    
    cout<<stack.size()<<endl; // 3
    
    cout<<stack.topElement()<<endl; // 30
    
    cout<<stack.isEmpty(); //false => 0

    return 0;
}
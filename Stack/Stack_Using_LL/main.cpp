#include <iostream>
#include "StackUsingLL.cpp"
using namespace std;
int main()
{
    StackUsingLL<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    cout<<stack.top()<<endl;
    cout<<stack.getSize()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.top()<<endl;
    cout<<stack.getSize();

    return 0;
}

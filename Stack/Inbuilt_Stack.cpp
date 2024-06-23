#include<stack>
#include<iostream>
using namespace std;
int main(){
    stack<int> s;
    // push into stack
    s.push(100);
    s.push(200);
    s.push(300);
    s.push(400);
    s.push(500);
    // Get the top element in stack
    cout<<s.top()<<endl;
    // Delete Top Element
    s.pop();
    // Get the size of stack
    cout<<s.size()<<endl;
    // Check stack is empty or not
    cout<<s.empty()<<endl;
    
    return 0;
}

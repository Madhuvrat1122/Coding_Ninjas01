#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    
    q.push(100);
    q.push(200);
    q.push(300);
    q.push(400);
    q.push(500);
    q.push(600);
    
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    
    // delete all queue element and print
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}

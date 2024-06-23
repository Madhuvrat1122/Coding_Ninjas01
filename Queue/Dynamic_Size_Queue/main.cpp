#include<iostream>
#include "QueueUsingDynamicArray.cpp"
using namespace std;
int main(){
    QueueUsingDynamicArray<int> q;
    
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Enqueue(60);
    q.Enqueue(70);
    
    cout<<q.getSize()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.front()<<endl;
    cout<<q.isEmpty()<<endl;
    return 0;
}

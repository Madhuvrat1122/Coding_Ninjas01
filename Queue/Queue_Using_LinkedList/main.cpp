#include<iostream>
#include "QueueUsingLinkedList.cpp"
using namespace std;
int main(){
    QueueUsingLinkedList<int> q;
    
    q.Enqueue(100);
    q.Enqueue(200);
    q.Enqueue(300);
    q.Enqueue(400);
    q.Enqueue(500);
    q.Enqueue(600);
    
    cout<<q.getSize()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.front()<<endl;
    cout<<q.isEmpty()<<endl;
    return 0;
}

#include <iostream>
#include "PriorityQueue.h"
using namespace std;
int main()
{
    PriorityQueue pq;
    
    pq.insert(10);
    // cout<<pq.getSize()<<endl; // 1
    // cout<<pq.isEmpty()<<endl; // 0
    // cout<<pq.getMin()<<endl;  // 10
    
    pq.insert(8);
    // cout<<pq.getSize()<<endl; // 2
    // cout<<pq.isEmpty()<<endl; // 0
    // cout<<pq.getMin()<<endl;  // 8
    
    pq.insert(15);
    // cout<<pq.getSize()<<endl; // 3
    // cout<<pq.isEmpty()<<endl; // 0
    // cout<<pq.getMin()<<endl;  // 8
    
    pq.insert(1);
    // cout<<pq.getSize()<<endl; // 4
    // cout<<pq.isEmpty()<<endl; // 0
    // cout<<pq.getMin()<<endl;  // 1
    
    pq.insert(50);
    pq.insert(100);
    pq.insert(0);
    // cout<<pq.getSize()<<endl; // 7
    // cout<<pq.isEmpty()<<endl; // 0
    // cout<<pq.getMin()<<endl;  // 0
    
    
    cout<<pq.deleteMin()<<endl; // 0
    // cout<<pq.getSize()<<endl; // 6
    // cout<<pq.isEmpty()<<endl; // 0
    // cout<<pq.getMin()<<endl;  // 1
    
    cout<<pq.deleteMin()<<endl; // 1
    cout<<pq.getSize()<<endl; // 5
    cout<<pq.isEmpty()<<endl; // 0
    cout<<pq.getMin()<<endl;  // 8
    
    return 0;
}

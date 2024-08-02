#include <iostream>
#include "PriorityQueue.h"
using namespace std;
int main()
{
    PriorityQueue pq;
    
    pq.insert(10);
    pq.insert(8);
    pq.insert(15);
    pq.insert(1);
    pq.insert(50);
    pq.insert(100);
    pq.insert(0);
    
    // cout<<pq.getSize()<<endl; // 7
    // cout<<pq.isEmpty()<<endl; // 0
    // cout<<pq.getMax()<<endl;  // 100
    
    
    cout<<pq.deleteMax()<<endl; // 100
    // cout<<pq.getSize()<<endl; // 6
    // cout<<pq.isEmpty()<<endl; // 0
    // cout<<pq.getMax()<<endl;  // 50
    
    cout<<pq.deleteMax()<<endl; // 50
    cout<<pq.getSize()<<endl; // 5
    cout<<pq.isEmpty()<<endl; // 0
    cout<<pq.getMax()<<endl;  // 15
    
    return 0;
}

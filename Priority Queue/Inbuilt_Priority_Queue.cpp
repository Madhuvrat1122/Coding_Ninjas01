#include <iostream>
#include <queue>
using namespace std;
int main()
{
    // in-built max priority queue
    // priority_queue<int> pq;
    
    // in-built min priority queue
    priority_queue<int, vector<int>, greater<int>> pq;
    
    pq.push(1);
    pq.push(20);
    pq.push(67);
    pq.push(9);
    pq.push(100);
    
    cout<<pq.size()<<endl;
    cout<<pq.top()<<endl; // max priority queue = 100, min priority queue = 1
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    // max priority queue :- 100, 67, 20, 9, 1
    // min priority queue :- 1, 9, 20, 67, 100
    

    return 0;
}

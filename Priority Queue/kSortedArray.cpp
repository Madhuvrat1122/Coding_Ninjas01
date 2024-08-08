#include <iostream>
#include <queue>
using namespace std;
void kSortedArray(int input[], int n, int k){
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        pq.push(input[i]);
    } // klogk
    
    int j=0;
    for(int i=k; i<n; i++){
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    } // (n-k)logk
    
    while(!pq.empty()){
        input[j] = pq.top();
        pq.pop();
        j++;
    } // klogk
    
    // complexity
    //  = klogk + (n-k)logk + klogk
    // = klogk + nlogk - klogk + klogk
    // = klogk + nlogk
    // = (k+n)logk
    // = nlogk   [ as (k+n) ~ n ]
    // = O(n)    [ assuming logk is very small ]
}
int main()
{
    int input[] = {10, 12, 6, 7, 9};
    int k = 3;
    kSortedArray(input, 5, k);
    for(int i=0; i<5; i++){
        cout<<input[i]<<" ";
    }
    
    return 0;
}

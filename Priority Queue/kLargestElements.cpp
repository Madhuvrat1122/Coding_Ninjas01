#include <iostream>
#include <queue>
using namespace std;
// step(1). create a min proirity queue
// step(2). assuming first k element are largest and pushing into min proirity queue
// step(3). start looking from k to n-1;
// step(4). comparing each element with min of priority queue
            // if greater then
            // remove the min element and push the new element
// step(5). once traversal is completed we will left with k largest element in priority queue.
// Complexity:- nlogk ~= O(n).
vector<int> kLargestElement(int input[], int n, int k){
   priority_queue<int, vector<int>, greater<int>> pq;
   for(int i=0; i<k; i++){
       pq.push(input[i]);
   }
   
   for(int i=k; i<n; i++){
       if(input[i] > pq.top()){
           pq.pop();
           pq.push(input[i]);
       }
   }
   
   vector<int> ans;
   while(!pq.empty()){
       ans.push_back(pq.top());
       pq.pop();
   }
   
   return ans;
   
}
int main()
{
    int input[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    int k = 4;
    vector<int> kLargest = kLargestElement(input, 13, k);
    for(int i=0; i<kLargest.size(); i++){
        cout<<kLargest[i]<<" ";
    }
    
    return 0;
}

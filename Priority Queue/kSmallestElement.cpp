#include <iostream>
#include <queue>
using namespace std;
// step(1). create a max proirity queue
// step(2). assuming first k element are smallest and pushing into max proirity queue
// step(3). start looking from k to n-1;
// step(4). comparing each element with max of priority queue
            // if smallest then
            // remove the max element and push the new element
// step(5). once traversal is completed we will left with k minimum element in priority queue.
// Complexity:- nlogk ~= O(n).
vector<int> kSmallestElement(int input[], int n, int k){
   priority_queue<int> pq;
   for(int i=0; i<k; i++){
       pq.push(input[i]);
   }
   
   for(int i=k; i<n; i++){
       if(input[i] < pq.top()){
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
    vector<int> kSmallest = kSmallestElement(input, 13, k);
    for(int i=0; i<kSmallest.size(); i++){
        cout<<kSmallest[i]<<" ";
    }
    
    return 0;
}
